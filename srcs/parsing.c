/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:51:13 by ddecourt          #+#    #+#             */
/*   Updated: 2021/11/02 19:08:05 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	is_numeric(char **av, int i, int j)
{
	while (av[++i])
	{
		while (av[i][++j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
			{
				printf("Error: arguments must be numeric\n");
				return (0);
			}
		}
		j = -1;
	}
	return (1);
}

int	ft_check_ac(int ac)
{
	if (ac != 5 && ac != 6)
	{
		printf("Error: wrong number of arguments\n");
		return (1);
	}
	return (0);
}

int	ft_parsing(char **av, t_env *env)
{
	if (!is_numeric(av, 0, -1))
		return (1);
	env->nb_philo = ft_atoi(av[1]);
	env->t_to_die = ft_atoi(av[2]);
	env->t_to_eat = ft_atoi(av[3]);
	env->t_to_sleep = ft_atoi(av[4]);
	env->stop = 0;
	pthread_mutex_init(&env->mutex_write, NULL);
	pthread_mutex_init(&env->death_mutex, NULL);
	pthread_mutex_init(&env->eating, NULL);
	if (env->nb_philo <= 0 || env->t_to_die <= 0 || \
	env->t_to_eat <= 0 || env->t_to_sleep <= 0)
		return (1);
	if (av[5] != NULL)
		env->nb_time_eat = ft_atoi(av[5]);
	else
		env->nb_time_eat = 2147483647;
	return (0);
}

int	init_prog(int ac, char **av, t_env *env)
{
	if (ft_check_ac(ac) == 1)
		return (EXIT_FAILURE);
	if (ft_parsing(av, env) == 1)
		return (EXIT_FAILURE);
	return (0);
}
