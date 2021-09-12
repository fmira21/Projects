/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <fmira@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 18:32:56 by fmira             #+#    #+#             */
/*   Updated: 2021/09/10 23:00:02 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	odd_philos(t_phil *current)
{
	unsigned long long	time;

	pthread_mutex_lock(current->r_fork);
	time = get_time();
	pthread_mutex_lock(&current->writing_lock);
	printf("%lli ms: Philosopher %i has taken a right fork\n", \
	time - current->start_time, current->id);
	pthread_mutex_unlock(&current->writing_lock);
	pthread_mutex_lock(current->l_fork);
	time = get_time();
	pthread_mutex_lock(&current->writing_lock);
	printf("%lli ms: Philosopher %i has taken a left fork\n", \
	time - current->start_time, current->id);
	pthread_mutex_unlock(&current->writing_lock);
}

void	even_philos(t_phil *current)
{
	unsigned long long	time;

	pthread_mutex_lock(current->l_fork);
	time = get_time();
	pthread_mutex_lock(&current->writing_lock);
	printf("%lli ms: Philosopher %i has taken a left fork\n", \
	time - current->start_time, current->id);
	pthread_mutex_unlock(&current->writing_lock);
	pthread_mutex_lock(current->r_fork);
	time = get_time();
	pthread_mutex_lock(&current->writing_lock);
	printf("%lli ms: Philosopher %i has taken a right fork\n", \
	time - current->start_time, current->id);
	pthread_mutex_unlock(&current->writing_lock);
}

void	sleep_and_think(t_phil *current)
{
	unsigned long long	time;

	time = get_time();
	pthread_mutex_unlock(current->r_fork);
	pthread_mutex_unlock(current->l_fork);
	pthread_mutex_lock(&current->writing_lock);
	printf("%lli ms: Philosopher %i is sleeping\n", \
	time - current->start_time, current->id);
	pthread_mutex_unlock(&current->writing_lock);
	usleep(current->time_to_sleep * 1000);
	time = get_time();
	pthread_mutex_lock(&current->writing_lock);
	printf("%lli ms: Philosopher %i is thinking\n", \
	time - current->start_time, current->id);
	pthread_mutex_unlock(&current->writing_lock);
	current->has_eaten++;
}

void	child_routine(void *current_ph)
{
	t_phil				*current;
	unsigned long long	time;

	current = (t_phil *)current_ph;
	while (1)
	{
		time = get_time();
		if ((int)(time - current->last_eat_time) > current->time_to_die)
			break ;
		if (current->eating_times && current->has_eaten == \
		current->eating_times)
			current->finish_eat = 1;
		if (current->id % 2 == 0)
			odd_philos(current);
		else
			even_philos(current);
		time = get_time();
		pthread_mutex_lock(&current->writing_lock);
		printf("%lli ms: Philosopher %i is eating\n", \
		time - current->start_time, current->id);
		pthread_mutex_unlock(&current->writing_lock);
		usleep(current->time_to_eat * 1000);
		current->last_eat_time = get_time();
		sleep_and_think(current);
	}
}

void	run_threads(int num, t_phil *philosophers)
{
	pthread_mutex_t		writing_lock;
	int					i;
	unsigned long long	time;

	i = -1;
	pthread_mutex_init(&writing_lock, NULL);
	time = get_time();
	while (++i < num)
	{
		philosophers[i].start_time = time;
		philosophers[i].last_eat_time = time;
		philosophers[i].writing_lock = writing_lock;
		pthread_create(&philosophers[i].philo_thread, \
		NULL, (void *)child_routine, (void *)(&philosophers[i]));
		usleep(1000);
	}
	usleep(10000);
}
