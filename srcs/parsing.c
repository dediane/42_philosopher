/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:51:13 by ddecourt          #+#    #+#             */
/*   Updated: 2021/10/22 16:05:56 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_parsing(int ac, char **av, t_env *env)
{
	if (ac != 5 && ac != 6)
	{
		printf("Usage: ./philo number_of_philosopher time_to_die time_to_eat \
		time_to_sleep [number_of_times_each_philosopher_must_eat]");
		return (1);
	}
	env->nb_philo = ft_atoi(av[1]);
	env->t_to_die = ft_atoi(av[2]);
	env->t_to_eat = ft_atoi(av[3]);
	env->t_to_sleep = ft_atoi(av[4]);
	env->start_time = get_timestamp(0);
	if (env->nb_philo <= 0 || env->t_to_die <= 0 || env->t_to_eat <= 0 || env->t_to_sleep >= 0)
		return(1); 
	if (av[5] != NULL)
		env->nb_time_eat = ft_atoi(av[5]);
	return (0);
}