/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:46:17 by acash             #+#    #+#             */
/*   Updated: 2022/02/02 22:59:29 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_clear(t_data *data)
{
	int	i;

	i = 0;
	if (data->forks_m)
	{
		while (i < data->phil_count)
			pthread_mutex_destroy(&data->forks_m[i++]);
		free(data->forks_m);
	}
	i = 0;
	if (data->philos)
	{
		while (i < data->phil_count)
		{
			pthread_mutex_destroy(&data->philos[i].mutex);
			pthread_mutex_destroy(&data->philos[i].eat_m);
			i++;
		}
		free(data->philos);
	}
	pthread_mutex_destroy(&data->write_m);
	pthread_mutex_destroy(&data->smonedead);
	return (1);
}

int	ft_error(int code)
{
	if (code == 0)
		write(1, "arg error pls try again!\n", 26);
	if (code == 1)
		write(1, "malloc error\n", 14);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		flag;

	if (argc != 5 && argc != 6)
		return (ft_error(0));
	flag = ft_init(&data, argc, argv);
	if (flag != 0)
	{
		if (flag == 2)
			ft_clear(&data);
		return (ft_error(0));
	}
	if (start_cycle(&data))
	{
		ft_clear(&data);
		return (ft_error(1));
	}
	pthread_mutex_lock(&data.smonedead);
	pthread_mutex_unlock(&data.smonedead);
	ft_clear(&data);
	return (0);
}
