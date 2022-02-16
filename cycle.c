/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 19:03:25 by acash             #+#    #+#             */
/*   Updated: 2022/02/02 22:31:16 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*obs_c(void	*dat)
{
	t_data	*data;
	int		i;
	int		count;

	data = (t_data *)dat;
	count = 0;
	while (count < data->t_musteat)
	{
		i = 0;
		while (i < data->phil_count)
		{
			pthread_mutex_lock(&data->philos[i].eat_m);
			i++;
		}
		count++;
	}
	show_status(&data->philos[0], 5);
	pthread_mutex_unlock(&data->smonedead);
	return (NULL);
}

void	*observ(void	*phil)
{
	t_philos	*philo;

	philo = (t_philos *)phil;
	while (1)
	{
		pthread_mutex_lock(&philo->mutex);
		if (!philo->is_eat && get_time(philo->data->start_time) >= philo->limit)
		{
			show_status(philo, 0);
			pthread_mutex_unlock(&philo->mutex);
			pthread_mutex_unlock(&philo->data->smonedead);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->mutex);
		usleep(10000);
	}	
}

void	*live(void *phil)
{
	t_philos	*philo;
	pthread_t	t2;

	philo = (t_philos *)phil;
	philo->last_eat = get_time(philo->data->start_time);
	philo->limit = philo->last_eat + philo->data->t_die;
	if (pthread_create(&t2, NULL, &observ, phil) != 0)
		return ((void *)1);
	pthread_detach(t2);
	while (1)
	{
		take_fork(philo);
		eat(philo);
		drop(philo);
		show_status(philo, 3);
	}
	return ((void *)0);
}

int	start_cycle(t_data *data)
{
	int			i;
	pthread_t	t1;
	void		*philo;

	data->start_time = 0;
	data->start_time = get_time(data->start_time);
	i = 0;
	if (data->t_musteat != 0)
	{
		if (pthread_create(&t1, NULL, &obs_c, (void *)data) != 0)
			return (1);
		pthread_detach(t1);
	}
	while (i < data->phil_count)
	{
		philo = (void *)(&data->philos[i]);
		if (pthread_create(&t1, NULL, &live, (void *)(&data->philos[i])) != 0)
			return (1);
		pthread_detach(t1);
		usleep(500);
		i++;
	}
	return (0);
}
