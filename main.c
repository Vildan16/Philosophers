#include "philo.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	init_data(t_data *data)
{
	data->num_of_ph = 0;
	data->time_to_die = 0;
	data->time_to_eat = 0;
	data->time_to_sleep = 0;
	data->num_of_eat = -1;
	data->someone_died = 0;
	data->lock = NULL;
	data->thread = NULL;
	data->fork = NULL;
}

int	ft_error(char *error, t_data *data)
{
	write(2, "Error\n", 6);
	if (error)
		write(2, error, ft_strlen(error));
	if (data)
	{
		if (data->thread)
			free(data->thread);
		if (data->fork)
			free(data->fork);
		if (data->lock)
			free(data->lock);
	}
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
	int		i;

	if (!(ac == 5 || ac == 6) || ft_check_input(av))
		return (ft_error("Wrong arguments\n", NULL));
	ft_init_data(&data);
	if (!(ft_setdata(&data, ac, av) && ft_threads(&data)))
		return (ft_error(NULL, &data));
	i = -1;
	while (++i < data.num_of_philo)
		pthread_mutex_destroy(&(data.fork[i]));
	pthread_mutex_destroy(&(data.dead_mutex));
	free_data(&data);
	return (0);
}