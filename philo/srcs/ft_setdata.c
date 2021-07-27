/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setdata.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:07:45 by ameta             #+#    #+#             */
/*   Updated: 2021/07/27 16:07:46 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_setdata(t_data *data, int ac, char **av)
{
	int	i;

	data->num_of_ph = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->num_of_eat = ft_atoi(av[5]);
	data->fork = malloc(sizeof(pthread_mutex_t) * (data->num_of_ph));
	if (!(data->fork))
		return (0);
	data->thread = malloc(sizeof(pthread_t) * (data->num_of_ph));
	if (!(data->thread))
		return (0);
	data->lock = malloc(sizeof(int) * (data->num_of_ph));
	if (!(data->lock))
		return (0);
	i = -1;
	while (++i < data->num_of_ph)
	{
		if (pthread_mutex_init(&(data->fork[i]), NULL) != 0)
			return (0);
		data->lock[i] = -1;
	}
	return (!(pthread_mutex_init(&(data->dead_mutex), NULL) != 0));
}
