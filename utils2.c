/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:42:19 by acash             #+#    #+#             */
/*   Updated: 2022/02/02 22:53:44 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putnbr(long n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr((n / 10));
		ft_putchar('0' + n % 10);
	}
	else
		ft_putchar('0' + n);
}

int	ft_check(t_data *data)
{
	if (data->phil_count <= 0 || data->t_die <= 0
		|| data->t_eat <= 0 || data->t_sleep <= 0
		|| data->t_musteat < 0)
		return (1);
	return (0);
}

void	ft_usleep(time_t milisec, long start_time)
{
	time_t	stop;
	time_t	start;

	stop = get_time(start_time) + milisec;
	start = get_time(start_time);
	while (start < stop)
	{
		usleep(1);
		start = get_time(start_time);
	}
}

long	get_time2(void)
{
	struct timeval	start_time;

	gettimeofday(&start_time, NULL);
	return (start_time.tv_sec * 1000 + start_time.tv_usec / 1000);
}
