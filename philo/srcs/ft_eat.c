#include "philo.h"

int	ft_one_philo(void *content, t_data *data, int i)
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
		usleep(100);
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
		printf("%.4li Philosopher %d has died\n", timer(), index + 1);
		pthread_mutex_unlock(&data->dead_mutex);
	}
	return (0);
}

int	ft_isdead(void *content)
{
    long		last_meal;
	t_data		*data;

	data = ((t_content *)content)->data;
	last_meal = ((t_content *)content)->last_meal;
	if (ft_time() - last_meal > data->time_to_die)
		return (1);
	return (0);
}
