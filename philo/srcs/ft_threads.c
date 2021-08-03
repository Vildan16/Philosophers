/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <ameta@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:07:53 by ameta             #+#    #+#             */
/*   Updated: 2021/08/03 19:20:17 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_isdead(t_content *content, t_data *data, int i)
{
	if (data->time_to_die < ft_time() - data->start_time - content[i].last_meal)
	{
		data->someone_died = 1;
		ft_printstatus(data, content->philo_id, "died");
		return (1);
	}
	if (content[i].eat_count == data->num_of_eat)
	{
		data->all_eaten++;
		if (data->all_eaten == data->num_of_ph)
		{
			printf("%.4li All philosophers satisfied\n", ft_time() - \
			data->start_time);
			return (1);
		}
	}
	return (0);
}

void	*monitor(void *content_)
{
	t_content	*content;
	t_data		*data;
	int			i;

	content = (t_content *)content_;
	data = content[0].data;
	while (1)
	{
		data->all_eaten = 0;
		i = 0;
		while (i < data->num_of_ph)
		{
			if (ft_isdead(content, data, i))
				return (NULL);
			i++;
			usleep(100);
		}
	}
	return (NULL);
}

void	*ft_life(void *content_)
{
	t_content	*content;
	long		start;

	content = (t_content *)content_;
	start = ft_time();
	while (content->data->start_sim != 1)
		usleep(0);
	if (content->philo_id % 2 == 0)
	{
		while (ft_time() - start < content->data->time_to_eat)
			usleep(50);
	}
	while (content->data->someone_died == 0 && content->eat_count != content->\
	data->num_of_eat)
	{
		if (ft_waitforks(content) || ft_eat(content))
			return (NULL);
		pthread_mutex_unlock(content->left_fork);
		pthread_mutex_unlock(content->right_fork);
		if (ft_sleep(content) || ft_printstatus(content->data, \
		content->philo_id, "thinking"))
			return (NULL);
		usleep(200);
	}
	return (NULL);
}

void	ft_create_threads(t_data *data, t_content *content, pthread_t *thread)
{
	int	i;

	i = 0;
	data->start_time = ft_time();
	while (i < data->num_of_ph)
	{
		pthread_mutex_init(&data->mutex[i], NULL);
		content[i].philo_id = i + 1;
		content[i].right_fork = &data->mutex[i];
		content[i].last_meal = 0;
		content[i].eat_count = 0;
		content[i].data = data;
		if (i != data->num_of_ph - 1)
			content[i].left_fork = &data->mutex[i + 1];
		else
			content[i].left_fork = &data->mutex[0];
		pthread_create(&thread[i], NULL, &ft_life, (void *)(&content[i]));
		i++;
	}
	data->start_sim = 1;
	pthread_create(&thread[i], NULL, &monitor, (void *)(content));
}

int	ft_threads(t_data *data)
{
	pthread_t	*thread;
	t_content	*content;
	int			i;

	i = 0;
	content = (t_content *)malloc(data->num_of_ph * sizeof(t_content));
	thread = (pthread_t *)malloc((data->num_of_ph + 1) * (sizeof(pthread_t)));
	data->mutex = (pthread_mutex_t *)malloc((data->num_of_ph + 1) * sizeof
			(pthread_mutex_t));
	pthread_mutex_init(&data->print_mutex, NULL);
	ft_create_threads(data, content, thread);
	while (i < data->num_of_ph)
		pthread_mutex_destroy(&data->mutex[i++]);
	pthread_join(thread[i], NULL);
	pthread_mutex_destroy(&data->print_mutex);
	free(thread);
	free(data->mutex);
	free(content);
	return (1);
}
