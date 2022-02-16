/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:47:31 by acash             #+#    #+#             */
/*   Updated: 2022/02/02 22:53:30 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

struct	s_data;

typedef struct s_philos
{
	int				position;
	int				is_eat;
	time_t			limit;
	int				last_eat;
	int				lfork;
	int				rfork;
	int				eat_count;
	struct s_data	*data;
	pthread_mutex_t	mutex;
	pthread_mutex_t	eat_m;
}	t_philos;

typedef struct s_data
{
	int				phil_count;
	long			start_time;
	time_t			t_die;
	time_t			t_eat;
	time_t			t_sleep;
	int				t_musteat;
	int				start;
	t_philos		*philos;
	pthread_mutex_t	*forks_m;
	pthread_mutex_t	write_m;
	pthread_mutex_t	smonedead;
}	t_data;

int		ft_error(int code);
int		ft_atoi(char *str);
void	ft_putchar(char c);
int		ft_strlen(char *s);
void	ft_putnbr(long n);
void	ft_putstr(char *s);
int		ft_init(t_data *data, int argc, char **argv);
long	get_time(long time);
void	show_status(t_philos *philo, int code);
int		start_cycle(t_data *data);
void	take_fork(t_philos *philo);
void	eat(t_philos *philo);
void	drop(t_philos *philo);
int		ft_check(t_data *data);
void	ft_usleep(time_t milisec, long start_time);
long	get_time2(void);

#endif