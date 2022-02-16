/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:19:00 by acash             #+#    #+#             */
/*   Updated: 2022/02/02 22:58:35 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_mutex_init(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_init(&data->write_m, NULL);
	pthread_mutex_init(&data->smonedead, NULL);
	pthread_mutex_lock(&data->smonedead);
	data->forks_m = (pthread_mutex_t *)malloc(sizeof(*(data->forks_m)) \
	* data->phil_count);
	if (!data->forks_m)
		return (1);
	while (i < data->phil_count)
	{
		pthread_mutex_init(&data->forks_m[i], NULL);
		i++;
	}
	return (0);
}

void	philo_start(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->phil_count)
	{
		data->philos[i].eat_count = 0;
		data->philos[i].position = i;
		data->philos[i].lfork = i;
		data->philos[i].rfork = (i + 1) % data->phil_count;
		data->philos[i].eat_count = 0;
		data->philos[i].data = data;
		if (data->phil_count == 1)
			data->philos[i].is_eat = 0;
		else
			data->philos[i].is_eat = 1;
		pthread_mutex_init(&data->philos[i].mutex, NULL);
		pthread_mutex_init(&data->philos[i].eat_m, NULL);
		pthread_mutex_lock(&data->philos[i].eat_m);
		i++;
	}
}

int	ft_init(t_data *data, int argc, char **argv)
{
	data->phil_count = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	data->t_musteat = 0;
	if (argc == 6)
		data->t_musteat = ft_atoi(argv[5]);
	if (ft_check(data))
		return (1);
	data->forks_m = NULL;
	data->philos = NULL;
	data->philos = (t_philos *)malloc(sizeof(*(data->philos)) \
	* data->phil_count);
	if (!data->philos)
		return (2);
	philo_start(data);
	if (ft_mutex_init(data))
		return (2);
	return (0);
}
