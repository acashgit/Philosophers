/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:57:23 by acash             #+#    #+#             */
/*   Updated: 2022/02/02 22:52:26 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
}

int	ft_atoi(char *str)
{
	size_t	i;
	int		sign;
	long	digit;

	i = 0;
	sign = 1;
	digit = 0;
	if (ft_strlen(str) > 12)
		ft_error(0);
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			ft_error(0);
		digit = (digit * 10) + (str[i] - '0');
		i++;
	}
	if ((digit > 2147483647 && sign > 0) || (digit > 2147483648 && sign < 0))
		ft_error(0);
	return (digit * sign);
}

long	get_time(long time)
{
	struct timeval	start_time;
	long			current;

	gettimeofday(&start_time, NULL);
	current = start_time.tv_sec * 1000 + start_time.tv_usec / 1000;
	return (current - time);
}
