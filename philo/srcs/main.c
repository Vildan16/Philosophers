/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <ameta@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:07:01 by ameta             #+#    #+#             */
/*   Updated: 2021/08/03 16:56:29 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_init_data(t_data *data)
{
	data->num_of_ph = 0;
	data->time_to_die = 0;
	data->time_to_eat = 0;
	data->time_to_sleep = 0;
	data->num_of_eat = -1;
	data->someone_died = 0;
	data->mutex = NULL;
	data->start_time = 0;
	data->all_eaten = 0;
}

int	ft_error(char *error)
{
	write(2, "Error\n", 6);
	write(2, error, ft_strlen(error));
	return (1);
}

int	ft_check_input(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!ft_isnum(av[i]) || ft_atoi(av[i]) < 1)
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (!(ac == 5 || ac == 6) || ft_check_input(av))
		return (ft_error("Wrong arguments\n"));
	ft_init_data(&data);
	if (!(ft_setdata(&data, ac, av) && ft_threads(&data)))
		return (ft_error("Error while running programm\n"));
	return (0);
}
