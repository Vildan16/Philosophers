# include "philo.h"

int	ft_waitfork(void *content, t_data *data, int index)
{
	if (data->num_of_ph == 1)
		return (ft_one_ph(content, data, index));
	while (!data->someone_died)
	{
		if (index % 2)
			lock_from_right_to_left(data, index);
		else
			lock_from_left_to_right(data, index);
		if (is_dead(content))
			return (death_handler(data, ((t_content *)content)->philo_id));
		if (data->lock[index] == index
			&& data->lock[(index + 1) % data->num_of_philo] == index)
			return (!(data->someone_died));
		usleep(100);
	}
	return (0);
}

void	*ft_life(void *content)
{
	t_data		*data;
	int			times_to_eat;
	int			i;

	i = ((t_content *)content)->philo_id;
	times_to_eat = data->num_of_eat;
	data = ((t_content *)content)->data;
	while (times_to_eat--)
	{
		if (!ft_waitfork(content, data, i))
			break ;
		if (!ft_eat(content, data, i))
			break ;
		if (!ft_unlockfork(content, data, i))
			break ;
		if (!ft_sleep(content, data, i))
			break ;
		ft_printstatus(data, i, "thinking");
		usleep(1000);
	}
	ft_printstatus(data, i, "satisfied");
	free(content);
	return (NULL);
}

t_content	*content_handler(int i, t_data *data)
{
	t_content	*content;

	content = malloc(sizeof(t_content));
	if (!content)
		return (NULL);
	content->data = data;
	content->philo_id = i;
	content->last_meal = 0;
	return (content);
}

int	ft_create_threads(t_data *data)
{
	t_content	*content;
	int			i;

	i = -1;
	while (++i < data->num_of_ph)
	{
		content = ft_content(i, data);
		if (!content)
			return (0);
		if (pthread_create(&(data->thread[i]), NULL,
				&ft_life, (void *)content) != 0)
		{
			ft_error("Couldn't create threads\n", data);
			return (0);
		}
		usleep(100);
	}
	return (1);
}

int	ft_threads(t_data *data)
{
	int	i;

	if (ft_create_threads(data) == 0)
		return (0);
	i = -1;
	while (++i < data->num_of_ph)
	{
		if (pthread_join(data->thread[i], NULL) != 0)
		{
			ft_error("Couldn't create threads\n", data);
			return (0);
		}
	}
	return (1);
}
