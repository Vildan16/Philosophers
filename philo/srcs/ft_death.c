/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_death.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <ameta@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:07:20 by ameta             #+#    #+#             */
/*   Updated: 2021/07/31 16:31:24 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_lock_right(t_data *data, int i)
{
	pthread_mutex_lock(&(data->fork[(i + 1) % data->num_of_ph]));
	if (data->lock[(i + 1) % data->num_of_ph] == -1)
	{
		data->lock[(i + 1) % data->num_of_ph] = i;
		pthread_mutex_lock(&(data->fork[i]));
		if (data->lock[i] == -1)
		{
			data->lock[i] = i;
			ft_printstatus(data, i, "taken a fork");
			ft_printstatus(data, i, "taken a fork");
		}
		else
			data->lock[(i + 1) % data->num_of_ph] = -1;
		pthread_mutex_unlock(&(data->fork[i]));
	}
	pthread_mutex_unlock(&(data->fork[(i + 1) % data->num_of_ph]));
}

void	ft_lock_left(t_data *data, int i)
{
	pthread_mutex_lock(&(data->fork[i]));
	if (data->lock[i] == -1)
	{
		data->lock[i] = i;
		pthread_mutex_lock(&(data->fork[(i + 1) % data->num_of_ph]));
		if (data->lock[(i + 1) % data->num_of_ph] == -1)
		{
			data->lock[(i + 1) % data->num_of_ph] = i;
			ft_printstatus(data, i, "taken a fork");
			ft_printstatus(data, i, "taken a fork");
		}
		else
			data->lock[i] = -1;
		pthread_mutex_unlock(&(data->fork[(i + 1) % data->num_of_ph]));
	}
	pthread_mutex_unlock(&(data->fork[i]));
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

int	ft_death(t_data *data, int i)
{
	pthread_mutex_lock(&data->dead_mutex);
	if (data->someone_died)
	{
		pthread_mutex_unlock(&data->dead_mutex);
		return (0);
	}
	else
	{
		pthread_mutex_lock(&data->print_mutex);
		data->someone_died = 1;
		printf("%.4li Philosopher %d has died\n", ft_time(data->start_time), \
		i + 1);
		pthread_mutex_unlock(&data->dead_mutex);
		pthread_mutex_unlock(&data->print_mutex);
	}
	return (0);
}

int	ft_isdead(void *content)
{
	long	last_meal;
	t_data	*data;

	data = ((t_content *)content)->data;
	last_meal = ((t_content *)content)->last_meal;
	if (ft_time(data->start_time) - last_meal > data->time_to_die)
		return (1);
	return (0);
}
