/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <ameta@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:13:27 by ameta             #+#    #+#             */
/*   Updated: 2021/07/31 12:09:38 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_data
{
	int					num_of_ph;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					num_of_eat;
	int					someone_died;
	int					*lock;
	int					start_sim;
	struct timeval		start_time;
	pthread_t			*thread;
	pthread_mutex_t		*fork;
	pthread_mutex_t		dead_mutex;
	pthread_mutex_t		print_mutex;
}				t_data;

typedef struct s_content
{
	int		philo_id;
	long	last_meal;
	t_data	*data;
}				t_content;

void		ft_lock_right(t_data *data, int index);
int			ft_one_ph(void *content, t_data *data, int i);
void		ft_lock_left(t_data *data, int index);
void		ft_init_data(t_data *data);
int			ft_death(t_data *data, int index);
int			ft_isdead(void *content);
int			ft_eat(void *content, t_data *data, int i);
int			ft_unlockfork(void *content, t_data *data, int i);
int			ft_sleep(void *content, t_data *data, int i);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
long		ft_time(struct timeval start_time);
void		ft_printstatus(t_data *data, int i, char *message);
int			ft_check_input(char **av);
int			ft_error(char *error, t_data *data);
int			ft_strlen(char *str);
int			ft_atoi(const char *nptr);
int			ft_isnum(char *num);
int			ft_setdata(t_data *data, int ac, char **av, int i);
int			ft_threads(t_data *data);
int			ft_waitfork(void *content, t_data *data, int i);
void		*ft_life(void *content);
t_content	*ft_content(int i, t_data *data);
int			ft_create_threads(t_data *data);

#endif
