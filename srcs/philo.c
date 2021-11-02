/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:12:23 by ddecourt          #+#    #+#             */
/*   Updated: 2021/11/02 19:10:32 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*routine(void *arg)
{
	t_philo	*ph;
	t_env	*env;

	ph = (t_philo *)(arg);
	env = ph->env;
	while (env->is_dead == 0)
	{
			exec_routine(ph);
	}
	return (0);
}

void	init_my_philos(t_philo *ph, t_env *env, int nb)
{
	int	i;

	i = -1;
	env->nb_philo = nb;
	while (++i < nb)
	{
		ph[i].id = i + 1;
		pthread_mutex_init(&ph[i].fork, NULL);
		pthread_mutex_init(&ph[i].philo_mutex, NULL);
		ph[i].env = env;
		ph[i].last_meal = 0;
		ph[i].time_he_eat = 0;
	}
	i = -1;
	while (++i < nb)
	{
		if (i == nb - 1)
			ph[i].next_fork = &ph[0].fork;
		else
			ph[i].next_fork = &ph[i + 1].fork;
	}
	init_time(env);
}

int	start_my_philos(t_env *env, t_philo *ph)
{
	int	i;

	i = -1;
	while (++i < env->nb_philo)
	{
		if (i % 2 == 0)
			pthread_create(&ph[i].ph, NULL, routine, &ph[i]);
	}
	i = -1;
	ft_usleep(100);
	while (++i < env->nb_philo)
	{
		if (i % 2 != 0)
			pthread_create(&ph[i].ph, NULL, routine, &ph[i]);
	}
	while (ph->env->is_dead == 0)
		check_dead(ph);
	exit(0);
	return (1);
}

int	main(int ac, char **av)
{
	t_env	env;
	t_philo	*ph;
	int		i;
	int		nb_of_philo;

	i = -1;
	init_prog(ac, av, &env);
	nb_of_philo = ft_atoi(av[1]);
	ph = malloc(sizeof(*ph) * (nb_of_philo));
	if (!ph)
		return (0);
	env.is_dead = 0;
	init_mutex(&env);
	init_my_philos(ph, &env, nb_of_philo);
	start_my_philos(&env, ph);
	while (++i < env.nb_philo)
		pthread_join(&ph->ph[i], NULL);
	return (0);
}
