/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <fmira@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 22:09:24 by fmira             #+#    #+#             */
/*   Updated: 2021/09/10 22:21:07 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_arguments(int ac, char **av, t_args *arguments)
{
	arguments->num_phil = ft_atoi(av[1]);
	arguments->time_to_die = ft_atoi(av[2]);
	arguments->time_to_eat = ft_atoi(av[3]);
	arguments->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		arguments->eating_times = ft_atoi(av[5]);
	else
		arguments->eating_times = 0;
}

pthread_mutex_t	*init_forks(int num)
{
	int				i;
	pthread_mutex_t	*all_forks;

	i = -1;
	all_forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num);
	if (!all_forks)
		return (NULL);
	while (++i < num)
		pthread_mutex_init(&all_forks[i], NULL);
	return (all_forks);
}

void	init_nums(int i, t_phil *philo, t_args *arguments)
{
	philo->id = i + 1;
	philo->time_to_die = arguments->time_to_die + 1;
	philo->time_to_sleep = arguments->time_to_sleep;
	philo->time_to_eat = arguments->time_to_eat;
	philo->eating_times = arguments->eating_times;
	philo->has_eaten = 0;
	philo->finish_eat = 0;
}

t_phil	*init_philosophers(int num, pthread_mutex_t *all_forks, \
t_args *arguments)
{
	t_phil	*philosophers;
	int		i;

	i = -1;
	philosophers = (t_phil *)malloc(sizeof(t_phil) * num);
	if (!philosophers)
		return (NULL);
	while (++i < num)
	{
		init_nums(i, &philosophers[i], arguments);
		philosophers[i].r_fork = &all_forks[i - 1];
		if (i == 0)
		{
			philosophers[i].l_fork = &all_forks[0];
			philosophers[i].r_fork = &all_forks[arguments->num_phil - 1];
		}
		else
			philosophers[i].l_fork = &all_forks[i];
	}
	return (philosophers);
}

t_main	*init_main(t_args *arguments, t_phil *philosophers, \
pthread_mutex_t *all_forks)
{
	t_main	*main;

	main = (t_main *)malloc(sizeof(t_main) * 1);
	if (!main)
		return (NULL);
	main->args = arguments;
	main->phil = philosophers;
	main->all_forks = all_forks;
	main->philos_eaten = 0;
	return (main);
}
