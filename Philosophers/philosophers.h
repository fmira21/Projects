/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <fmira@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 22:09:35 by fmira             #+#    #+#             */
/*   Updated: 2021/09/10 22:52:11 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/types.h>
# include <sys/time.h>
# include <stdint.h>
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_phil{
	int					id;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					has_eaten;
	unsigned long long	start_time;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		writing_lock;
	pthread_t			philo_thread;
	int					finish_eat;
	unsigned long long	last_eat_time;
	int					eating_times;
}						t_phil;

typedef struct s_args{
	int	num_phil;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	eating_times;
}		t_args;

typedef struct s_main{
	int				philos_eaten;
	t_args			*args;
	t_phil			*phil;
	pthread_mutex_t	*all_forks;
}					t_main;

int					ft_atoi(const char *nptr);
int					ft_isdigit(int c);
unsigned long long	get_time(void);
int					arg_precheck(int argc, char **argv);
void				init_arguments(int ac, char **av, t_args *arguments);
pthread_mutex_t		*init_forks(int num);
t_phil				*init_philosophers(int num, pthread_mutex_t *all_forks, \
t_args *arguments);
t_main				*init_main(t_args *arguments, \
t_phil *philosophers, pthread_mutex_t *all_forks);
int					arg_check(t_args *arguments);
void				run_threads(int num, t_phil *philosophers);
void				child_routine(void *current_ph);

#endif