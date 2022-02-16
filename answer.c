/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   answer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:57:06 by acash             #+#    #+#             */
/*   Updated: 2022/02/02 22:23:55 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*geter(int code)
{
	if (code == 0)
		return (" died\n");
	if (code == 1)
		return (" is eating\n");
	if (code == 2)
		return (" is sleeping\n");
	if (code == 3)
		return (" is thinking\n");
	if (code == 4)
		return (" has taken a fork\n");
	if (code == 5)
		return (" must eat count is done\n");
	return ("");
}

void	show_status(t_philos *philo, int code)
{
	static int	done = 0;

	pthread_mutex_lock(&philo->data->write_m);
	if (done == 0)
	{
		ft_putnbr(get_time(philo->data->start_time));
		ft_putchar('\t');
		if (code != 5)
			ft_putnbr(philo->position + 1);
		if (code == 5 || code == 0)
			done = 1;
		ft_putstr(geter(code));
	}
	pthread_mutex_unlock(&philo->data->write_m);
}
