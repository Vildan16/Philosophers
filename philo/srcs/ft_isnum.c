/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameta <ameta@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:07:32 by ameta             #+#    #+#             */
/*   Updated: 2021/08/03 19:22:32 by ameta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_setdata(t_data *data, int ac, char **av)
{
	data->num_of_ph = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->num_of_eat = ft_atoi(av[5]);
	else
		data->num_of_eat = -1;
	return (1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				res;
	unsigned char	*str1;
	unsigned char	*str2;
	char			*end;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	end = (char *)str1 + n;
	res = 0;
	while (res == 0 && (char *)str1 != end && (*str1 || *str2))
	{
		res = *str1 - *str2;
		str1++;
		str2++;
	}
	return (res);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;
	int	minus;

	i = 0;
	res = 0;
	minus = 1;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n' || \
			nptr[i] == '\r' || nptr[i] == '\v' || nptr[i] == '\f')
		i++;
	if (nptr[i] == '-')
	{
		minus = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (res * minus);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (!num)
		return (0);
	if (num[i] == '+' || num[i] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}
