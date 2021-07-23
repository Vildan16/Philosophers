#include "../includes/philo.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
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


int		ft_atoi(const char *nptr)
{
	int i;
	int res;
	int minus;

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

static int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int 	ft_isnum(char *num)
{
	int i;

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


