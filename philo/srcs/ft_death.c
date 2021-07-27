/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_death.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <ameta@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:07:20 by ameta             #+#    #+#             */
/*   Updated: 2021/07/27 19:32:18 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_lock_right(t_data *data, int index)
{
	pthread_mutex_lock(&(data->fork[(index + 1) % data->num_of_ph]));
	pthread_mutex_lock(&(data->fork[index]));
	if (data->lock[(index + 1) % data->num_of_ph] == -1
		&& data->lock[index] == -1)
	{
		data->lock[(index + 1) % data->num_of_ph] = index;
		data->lock[index] = index;
		ft_printstatus(data, index, "taken a fork");
		ft_printstatus(data, index, "taken a fork");
	}
	pthread_mutex_unlock(&(data->fork[(index + 1) % data->num_of_ph]));
	pthread_mutex_unlock(&(data->fork[index]));
}

void	ft_lock_left(t_data *data, int index)
{
	pthread_mutex_lock(&(data->fork[index]));
	pthread_mutex_lock(&(data->fork[(index + 1) % data->num_of_ph]));
	if (data->lock[index] == -1
		&& data->lock[(index + 1) % data->num_of_ph] == -1)
	{
		data->lock[index] = index;
		data->lock[(index + 1) % data->num_of_ph] = index;
		ft_printstatus(data, index, "taken a fork");
		ft_printstatus(data, index, "taken a fork");
	}
	pthread_mutex_unlock(&(data->fork[index]));
	pthread_mutex_unlock(&(data->fork[(index + 1) % data->num_of_ph]));
}

int	ft_one_ph(void *content, t_data *data, int i)
{
	while (1)
	{
		if (data->lock[i] == -1)
		{
			data->lock[i] = i;
			ft_printstatus(data, i, "taken a fork");
		}
		if (ft_isdead(content))
			return (ft_death(data, i));
	}
}

int	ft_death(t_data *data, int index)
{
	pthread_mutex_lock(&data->dead_mutex);
	if (data->someone_died)
	{
		pthread_mutex_unlock(&data->dead_mutex);
		return (0);
	}
	else
	{
		data->someone_died = 1;
		printf("%.4li Philosopher %d has died\n", ft_time() - \
		data->start_time, index + 1);
		pthread_mutex_unlock(&data->dead_mutex);
	}
	return (0);
}

int	ft_isdead(void *content)
{
	long	last_meal;
	t_data	*data;

	data = ((t_content *)content)->data;
	last_meal = ((t_content *)content)->last_meal;
	if (ft_time() - last_meal - data->start_time > data->time_to_die)
		return (1);
	return (0);
}
