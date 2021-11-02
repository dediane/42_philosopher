/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:12:23 by ddecourt          #+#    #+#             */
/*   Updated: 2021/11/02 13:08:40 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*routine(void *arg)
{
	t_philo	*ph;

	
	ph = (t_philo *)(arg);
	if (ph->id % 2 == 0)
		ft_usleep(100);
	while (1)
	{
		exec_routine(ph);
	}
	return (0);
}

void	is_someone_dead(t_philo *ph)
{
	int i;

	i = -1;
	while (1)
	{
		while (++i < ph->env->nb_philo)
		{
			if (check_dead(&ph[i]))
				ph->env->is_dead = 0;
		}
		i = -1;
	}
}

int	check_dead(t_philo *ph)
{
	pthread_mutex_lock(&ph->env->mutex_write);
	if (ph->last_meal > ph->env->t_to_die)
	{
		ft_print_status(ph, "died");
		return (1);
	}
	pthread_mutex_unlock(&ph->env->mutex_write);
	return (0);
}

void	init_my_philos(t_philo *ph, t_env *env, int nb)
{
	int	i;

	i = -1;
	env->nb_philo = nb;
	init_time(env);
	while (++i < nb )
	{
		ph[i].id = i + 1;
		pthread_mutex_init(&ph[i].fork, NULL);
		ph[i].env = env;
		ph[i].last_meal = 0;
	}
	i = -1;
	while (++i < nb)
	{
		if (i == nb - 1)
			ph[i].next_fork = &ph[0].fork;
		else
			ph[i].next_fork = &ph[i + 1].fork;
		pthread_create(&ph[i].ph, NULL, routine, &ph[i]);
	}
}

int	main(int ac, char **av)
{
	t_env	env;
	t_philo	*ph;
	int		i;
	int		nb_of_philo;

	i = -1;
	if (ft_check_ac(ac) == 1)
		return (EXIT_FAILURE);
	if (ft_parsing(av, &env) == 1)
		return (EXIT_FAILURE);
	env.is_dead = 0;
	nb_of_philo = ft_atoi(av[1]);
	ph = malloc(sizeof(*ph) * (nb_of_philo));
	if (!ph)
		return (0);
	init_mutex(&env);
	init_my_philos(ph, &env, nb_of_philo);
	while (++i < env.nb_philo)
		pthread_join(&ph->ph[i], NULL);
}
