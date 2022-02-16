/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buisnes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:49:20 by acash             #+#    #+#             */
/*   Updated: 2022/02/02 22:33:08 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philos *philo)
{
	pthread_mutex_lock(&philo->data->forks_m[philo->lfork]);
	show_status(philo, 4);
	pthread_mutex_lock(&philo->data->forks_m[philo->rfork]);
	show_status(philo, 4);
}

void	eat(t_philos *philo)
{
	pthread_mutex_lock(&philo->mutex);
	philo->is_eat = 1;
	philo->last_eat = get_time(philo->data->start_time);
	philo->limit = philo->last_eat + philo->data->t_die;
	show_status(philo, 1);
	ft_usleep(philo->data->t_eat, philo->data->start_time);
	philo->eat_count += 1;
	philo->is_eat = 0;
	pthread_mutex_unlock(&philo->mutex);
	pthread_mutex_unlock(&philo->eat_m);
}

void	drop(t_philos *philo)
{
	show_status(philo, 2);
	pthread_mutex_unlock(&philo->data->forks_m[philo->lfork]);
	pthread_mutex_unlock(&philo->data->forks_m[philo->rfork]);
	ft_usleep(philo->data->t_sleep, philo->data->start_time);
}
