/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:12:23 by ddecourt          #+#    #+#             */
/*   Updated: 2021/10/22 19:31:48 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *ph)
{
	pthread_mutex_lock(ph);
	pthread_mutex_unlock(ph);
	return(0);
}

void	init_my_philos(t_philo *ph, t_env *env, int nb)
{
	int i;

	i = -1;
	while(++i < nb)
	{
		pthread_mutex_t next_fork;
		ph->id = i + 1;
		if (&(ph[i].fork) == NULL && i != (env->nb_philo - 1))
		{
			pthread_mutex_init(&(ph[i].fork), NULL);
			pthread_mutex_init(&next_fork, NULL);
			ph[i + 1].fork = next_fork;
			ph[i].next_fork = next_fork;
		}
		if (i == (env->nb_philo - 1))
		{
			pthread_mutex_init(&(ph[i].fork), NULL);
			pthread_mutex_init(&next_fork, NULL);
			ph[0].fork = next_fork;
			ph[i].next_fork = next_fork;
		}
		env->start_time = 0;
		pthread_create(&ph[i].philo, NULL, &routine, &ph);
	}
}

int	main(int ac, char** av)
{
	t_philo *ph;
	t_env env;
	int nb_of_philo;
	
	nb_of_philo = ft_atoi(av[1]);
	ph = malloc(sizeof(t_philo) * (nb_of_philo + 1));
	if (!ph)
		return ((int)NULL);
	ft_parsing(ac, av, &env);
	init_my_philos(ph, &env, nb_of_philo);
	return (0);
}