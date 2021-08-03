/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <ameta@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:07:25 by ameta             #+#    #+#             */
/*   Updated: 2021/08/03 19:17:34 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_waitforks(t_content *content)
{
	if (content->data->num_of_ph == 1)
	{
		pthread_mutex_lock(content->left_fork);
		ft_printstatus(content->data, content->philo_id, "taken a fork");
		return (1);
	}
	pthread_mutex_lock(content->left_fork);
	if (ft_printstatus(content->data, content->philo_id, "taken a fork"))
		return (1);
	pthread_mutex_lock(content->right_fork);
	if (ft_printstatus(content->data, content->philo_id, "taken a fork"))
		return (1);
	return (0);
}

int	ft_eat(t_content *content)
{
	long	start;

	if (content->data->someone_died == 1)
		return (1);
	if (ft_printstatus(content->data, content->philo_id, "eating"))
		return (1);
	content->last_meal = ft_time() - content->data->start_time;
	start = ft_time();
	while (ft_time() - start < content->data->time_to_eat)
		usleep(50);
	content->eat_count++;
	return (0);
}

int	ft_sleep(t_content *content)
{
	long	start;

	if (content->data->someone_died == 1)
		return (1);
	if (ft_printstatus(content->data, content->philo_id, "sleeping"))
		return (1);
	start = ft_time();
	while (ft_time() - start < content->data->time_to_sleep)
		usleep(50);
	return (0);
}
