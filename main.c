#include "philo.h"

ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_error(char *error, t_data *data)
{
	write(2, "Error\n", 6);
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
	while (argv[i])
	{
		if (!ft_isnbr(argv[i]) || ft_atoi(argv[i]) < 0)
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		i;

	if ((ac != 5 || ac != 6) && ft_check_input(av))
		return (ft_error("Wrong arguments\n", NULL));
	if (ft_atoi(argv[1]) > HARD_CAP)
		return (error_handler(TOO_MANY_THREADS, NULL));
	init_data(&data);
	if (!(data_setup(&data, argc, argv) && create_and_join_threads(&data)))
		return (error_handler(errno, &data));
	i = -1;
	while (++i < data.num_of_philo)
		pthread_mutex_destroy(&(data.fork[i]));
	pthread_mutex_destroy(&(data.dead_mutex));
	free_data(&data);
	return (0);
}