#include "../includes/philo.h"

int	ft_eat(void *content, t_data *data, int i)
{
	long		time_start;

	time_start = ft_time();
	((t_content *)content)->last_meal = time_start;
	ft_printstatus(data, i, "eating");
	while (ft_time() - time_start < data->time_to_eat)
	{
		if (ft_isdead(content))
			return (ft_death(data, i));
		if (data->someone_died)
			return (0);
		usleep(100);
	}
	return (1);
}

int	ft_unlockfork(void *content, t_data *data, int i)
{
	(void)content;
	data->lock[i] = -1;
	data->lock[(i + 1) % data->num_of_ph] = -1;
	if (data->someone_died)
		return (0);
	return (1);
}

int	ft_sleep(void *content, t_data *data, int i)
{
	long	time_start;

	time_start = ft_time();
	ft_printstatus(data, i, "sleeping");
	while (ft_time() - time_start < data->time_to_sleep)
	{
		if (data->someone_died || ft_isdead(content))
			return (ft_death(data, i + 1));
		usleep(100);
	}
	return (1);
}