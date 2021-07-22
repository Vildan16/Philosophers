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
	int     			num_of_eat;
    int					someone_died;
    int					*lock;
	pthread_t			*thread;
	pthread_mutex_t		*fork;
    pthread_mutex_t		dead_mutex;
}				t_data;

typedef struct s_content
{
	int		philo_id;
	long	last_meal;
	t_data	*data;
}				t_content;

int	ft_check_input(char **av);
int	ft_error(char *error, t_data *data);
int ft_strlen(char *str);
int		ft_atoi(const char *nptr);
int 	ft_isnum(char *num);
int	ft_setdata(t_data *data, int ac, char **av);
int	ft_threads(t_data *data);



#endif