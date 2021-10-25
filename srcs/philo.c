/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:12:23 by ddecourt          #+#    #+#             */
/*   Updated: 2021/10/26 01:44:43 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*routine(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *)(arg);
	pthread_mutex_lock(&ph->mutex_write);
	printf("here\n");
	pthread_mutex_unlock(&ph->mutex_write);
	exec_routine(ph);
	return (0);
}

void	init_my_philos(t_philo *ph, t_env *env, int nb)
{
	int	i;

	i = -1;
	env->nb_philo = nb;
	while (++i < (nb - 1))
	{
		ph[i].id = i + 1;
		pthread_create(&ph[i].philo, NULL, &routine, &ph[i]);
		pthread_mutex_init(&ph[i].fork, NULL);
		pthread_mutex_init(&ph[i].mutex_write, NULL);
		ph[i].next_fork = ph[i + 1].fork;
		ph[i].init_time = 0;
		ph[i].t_wait = 0;
	}
	ph[nb - 1].id = nb;
	pthread_create(&ph[nb - 1].philo, NULL, &routine, &ph[nb - 1]);
	pthread_mutex_init(&ph[nb - 1].fork, NULL);
	pthread_mutex_init(&ph[nb - 1].mutex_write, NULL);
	ph[nb - 1].next_fork = ph[0].fork;
}

int	main(int ac, char **av)
{
	t_philo	*ph;
	t_env	env;
	int		nb_of_philo;

	if (ft_check_ac(ac) == 1)
		return (EXIT_FAILURE);
	if (ft_parsing(av, &env) == 1)
		return (EXIT_FAILURE);
	nb_of_philo = ft_atoi(av[1]);
	ph = malloc(sizeof(t_philo) * (nb_of_philo + 1));
	if (!ph)
		return (0);
	init_my_philos(ph, &env, nb_of_philo);
	printf("Parsing successful\n");
}
	/*if (ac != 5 && ac != 6)
	{
		printf("Usage: ./philo number_of_philosopher time_to_die time_to_eat\
		time_to_sleep [number_of_times_each_philosopher_must_eat]");
		return (1);
	}
	if (ft_parsing(av, &env) == 1)
		return (1);
	printf("ICI\n");
	return (0);*/

	/*int				i;
	pthread_mutex_t	*next_fork;

	i = -1;
	env->nb_philo = nb;
	while (++i < nb)
	{
		next_fork = NULL;
		ph->id = i + 1;
		if (&(ph[i].fork) == NULL && i != (nb - 2))
		{
			ph[i + 1].fork = next_fork;
			ph[i].next_fork = next_fork;
		}
		if (i == (nb - 2))
		{
			ph[0].fork = next_fork;
			ph[i].next_fork = next_fork;
		}
		env->start_time = 0;
	}*/