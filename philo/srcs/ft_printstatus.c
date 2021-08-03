/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstatus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <ameta@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:07:37 by ameta             #+#    #+#             */
/*   Updated: 2021/08/03 19:32:52 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	ft_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000 + current_time.tv_usec / 1000));
}

int	ft_printstatus(t_data *data, int i, char *message)
{
	usleep(100);
	pthread_mutex_lock(&data->print_mutex);
	if (!ft_strncmp(message, "died", 5))
	{
		printf("%.4li %d died\n", ft_time() - data->start_time, i);
		return (1);
	}
	if (data->someone_died == 1 || data->all_eaten == data->num_of_eat)
	{
		pthread_mutex_unlock(&data->print_mutex);
		return (1);
	}
	else if (!ft_strncmp(message, "satisfied", 10) && data->someone_died == 0)
		printf("%.4li %d is satisfied\n", ft_time() - data->start_time, i);
	else if (!ft_strncmp(message, "sleeping", 10) && data->someone_died == 0)
		printf("%.4li %d is sleeping\n", ft_time() - data->start_time, i);
	else if (!ft_strncmp(message, "thinking", 10) && data->someone_died == 0)
		printf("%.4li %d is thinking\n", ft_time() - data->start_time, i);
	else if (!ft_strncmp(message, "taken a fork", 20) && data->someone_died \
	== 0)
		printf("%.4li %d has taken a fork\n", ft_time() - data->start_time, i);
	else if (!ft_strncmp(message, "eating", 10) && data->someone_died == 0)
		printf("%.4li %d is eating\n", ft_time() - data->start_time, i);
	pthread_mutex_unlock(&data->print_mutex);
	return (0);
}
