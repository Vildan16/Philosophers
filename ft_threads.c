# include "philo.h"

static int	ft_create_threads(t_data *data)
{
	t_content	*content;
	int			i;

	i = -1;
	while (++i < data->num_of_ph)
	{
		content = content_handler(data, i);
		if (!content)
			return (0);
		if (pthread_create(&(data->thread[i]), NULL,
				&routine, (void *)content) != 0)
		{
			output_error(THREAD_CREATE_ERROR);
			return (0);
		}
		usleep(100);
	}
	return (1);
}

int	ft_threads(t_data *data)
{
	int ret;

	ret = ft_create_threads(data);
	
	return (ret);
}