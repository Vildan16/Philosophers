/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstatus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <ameta@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:07:37 by ameta             #+#    #+#             */
/*   Updated: 2021/07/29 14:22:57 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	ft_time(struct timeval start_time)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000 + current_time.tv_usec / 1000) - \
	(start_time.tv_sec * 1000 + start_time.tv_usec / 1000));
}

void	ft_printstatus(t_data *data, int i, char *message)
{
	long	time;

	time = ft_time(data->start_time);
	pthread_mutex_lock(&data->print_mutex);
	if (!data->someone_died)
	{
		if (!ft_strncmp(message, "satisfied", 10))
			printf("%.4li %d is satisfied\n", time, i + 1);
		else if (!ft_strncmp(message, "sleeping", 10))
			printf("%.4li %d is sleeping\n", time, i + 1);
		else if (!ft_strncmp(message, "thinking", 10))
			printf("%.4li %d is thinking\n", time, i + 1);
		else if (!ft_strncmp(message, "taken a fork", 20))
			printf("%.4li %d has taken a fork\n", time, i + 1);
		else if (!ft_strncmp(message, "eating", 10))
			printf("%.4li %d is eating\n", time, i + 1);
	}	
	pthread_mutex_unlock(&data->print_mutex);
}
