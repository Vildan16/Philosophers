/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <ameta@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:13:27 by ameta             #+#    #+#             */
/*   Updated: 2021/08/03 19:21:52 by ameta            ###   ########.fr       */
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
	int					start_sim;
	pthread_mutex_t		*mutex;
	pthread_mutex_t		print_mutex;
	long				start_time;
	int					all_eaten;
}				t_data;

typedef struct s_content
{
	int					philo_id;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	long				last_meal;
	int					eat_count;
	t_data				*data;
}				t_content;

void		ft_init_data(t_data *data);
int			ft_isdead(t_content *content, t_data *data, int i);
int			ft_eat(t_content *content);
int			ft_sleep(t_content *content);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
long		ft_time(void);
int			ft_printstatus(t_data *data, int i, char *message);
int			ft_check_input(char **av);
int			ft_error(char *error);
int			ft_strlen(char *str);
int			ft_atoi(const char *nptr);
int			ft_isnum(char *num);
int			ft_setdata(t_data *data, int ac, char **av);
int			ft_threads(t_data *data);
int			ft_waitforks(t_content *content);
void		*ft_life(void *content);
void		ft_create_threads(t_data *data, t_content *content, \
			pthread_t *thread);

#endif
