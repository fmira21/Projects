/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <fmira@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 17:18:27 by fmira             #+#    #+#             */
/*   Updated: 2021/09/10 22:46:51 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	arg_check(t_args *arguments)
{
	if (arguments->num_phil < 1)
	{
		printf("No philosophers around the table!\n");
		return (1);
	}
	if (arguments->time_to_die < 60 || \
	arguments->time_to_eat < 60 || arguments->time_to_sleep < 60)
	{
		printf("Invalid time input (should be >= 60 ms).\n");
		return (1);
	}
	return (0);
}

unsigned long long	get_time(void)
{
	struct timeval		time;
	unsigned long long	time_from_start;

	gettimeofday(&time, NULL);
	time_from_start = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (time_from_start);
}

int	arg_precheck(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 5 || argc > 6)
	{
		printf("Wrong number of arguments!\n");
		return (1);
	}
	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (ft_isdigit(argv[i][j]) != 1)
			{
				printf("Wrong argument: %s\n", argv[i]);
				return (1);
			}
		}
	}
	return (0);
}
