/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <fmira@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 22:40:57 by fmira             #+#    #+#             */
/*   Updated: 2021/09/10 23:09:39 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philo_death(int num, t_phil philosophers, pthread_mutex_t forks)
{
	int					j;
	unsigned long long	time;

	time = get_time();
	pthread_mutex_lock(&philosophers.writing_lock);
	printf("%lli ms: Philosopher %i is dead.\n", \
	time - philosophers.start_time, philosophers.id);
	pthread_mutex_unlock(&philosophers.writing_lock);
	j = -1;
	while (++j < num)
	{
		pthread_detach(philosophers.philo_thread);
		pthread_mutex_destroy(&forks);
	}
	return (1);
}

int	philo_finish(int num, t_phil philosophers, \
pthread_mutex_t forks)
{
	int					j;
	unsigned long long	time;

	time = get_time();
	pthread_mutex_lock(&philosophers.writing_lock);
	printf("%lli ms: All philosophers have eaten.\n", \
	time - philosophers.start_time);
	pthread_mutex_unlock(&philosophers.writing_lock);
	j = -1;
	while (++j < num)
	{
		pthread_detach(philosophers.philo_thread);
		pthread_mutex_destroy(&forks);
	}
	return (1);
}

int	waiter(int num, t_phil *philosophers, \
pthread_mutex_t *all_forks, t_main *main)
{
	unsigned long long	time;
	int					i;

	while (1)
	{
		i = -1;
		while (++i < num)
		{
			time = get_time();
			if ((int)(time - philosophers[i].last_eat_time) > \
			philosophers[i].time_to_die + 1)
				return (philo_death(num, philosophers[i], all_forks[i]));
			if (philosophers[i].finish_eat == 1)
			{
				main->philos_eaten++;
				if (main->philos_eaten >= num)
					return (philo_finish(num, philosophers[i], all_forks[i]));
			}
		}
		usleep(1000);
	}
}

void	free_all(t_args *arguments, t_phil *philosophers, \
pthread_mutex_t *forks, t_main *main)
{
	free(philosophers);
	free(arguments);
	free(forks);
	free(main);
}

int	main(int ac, char **av)
{
	t_args			*arguments;
	t_phil			*philosophers;
	pthread_mutex_t	*all_forks;
	t_main			*main;

	if (arg_precheck(ac, av) == 1)
		return (1);
	arguments = (t_args *)malloc(sizeof(t_args) * 1);
	if (!arguments)
		return (1);
	init_arguments(ac, av, arguments);
	if (arg_check(arguments))
		return (1);
	all_forks = init_forks(arguments->num_phil);
	philosophers = init_philosophers(arguments->num_phil, all_forks, arguments);
	main = init_main(arguments, philosophers, all_forks);
	if (!all_forks || !philosophers || !main)
		return (1);
	run_threads(arguments->num_phil, philosophers);
	if (waiter(arguments->num_phil, philosophers, all_forks, main))
	{
		free_all(arguments, philosophers, all_forks, main);
		return (0);
	}
}
