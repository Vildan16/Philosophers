#include "philo.h"

long	ft_time(void)
{
    static time_t		start_sec;
	static suseconds_t	start_micro_sec;
	struct timeval		time;

    start_sec = 0;
    start_micro_sec = 0;
	gettimeofday(&time, NULL);
	if (!start_sec)
	{
		start_sec = time.tv_sec;
		start_micro_sec = time.tv_usec;
	}
	return (((time.tv_sec - start_sec) * 1000)
		+ (time.tv_usec - start_micro_sec) / 1000);
}

int	validate_user_input(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (!ft_isnbr(argv[i]) || ft_atoi(argv[i]) < 0)
			return (0);
	}
	return (1);
}


void	ft_printstatus(t_data *data, int i, char *message)
{
	pthread_mutex_lock(&data->dead_mutex);
	if (!data->someone_died)
	{
        if (!ft_strncmp(message, "satisfied", 10))
		    printf("%.4li %d is satisfied\n", ft_time(), i + 1);
		else if (!ft_strncmp(message, "sleeping", 10))
		    printf("%.4li %d is sleeping\n", ft_time(), i + 1);
		else if (!ft_strncmp(message, "thinking", 10))
            printf("%.4li %d is thinking\n", ft_time(), i + 1);
        else if (!ft_strncmp(message, "taken a fork", 20))
            printf("%.4li %d has taken a fork\n", ft_time(), i + 1);
        else if (!ft_strncmp(message, "eating", 10))
            printf("%.4li %d is eating\n", ft_time(), i + 1);
	}
	pthread_mutex_unlock(&data->dead_mutex);
}