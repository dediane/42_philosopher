/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:12:23 by ddecourt          #+#    #+#             */
/*   Updated: 2021/11/15 16:24:09 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*routine(void *arg)
{
	t_philo	*ph;
	int		is_dead;

	ph = (t_philo *)(arg);
	pthread_mutex_lock(&ph->env->death_mutex);
	is_dead = ph->env->is_dead;
	pthread_mutex_unlock(&ph->env->death_mutex);
	while (is_dead == 0)
	{
		exec_routine(ph);
		pthread_mutex_lock(&ph->env->death_mutex);
		is_dead = ph->env->is_dead;
		pthread_mutex_unlock(&ph->env->death_mutex);
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
	int	dead;

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
	while (1)
	{
		dead = check_dead(ph);
		if (dead == 1)
			return (1);
	}
	return (0);
}

void	one_philo(t_philo *ph, t_env *env)
{
	ft_print_status(ph, "is taking a fork");
	ft_usleep(env->t_to_die);
	ft_print_status(ph, "is dead");
}

int	main(int ac, char **av)
{
	t_env	env;
	t_philo	*ph;
	int		i;

	i = -1;
	init_prog(ac, av, &env);
	if (env.nb_time_eat == 0)
		return (1);
	env.nb_philo = ft_atoi(av[1]);
	ph = malloc(sizeof(*ph) * (env.nb_philo));
	if (!ph)
		return (0);
	env.is_dead = 0;
	init_mutex(&env);
	init_my_philos(ph, &env, env.nb_philo);
	if (env.nb_philo == 1)
		one_philo(ph, &env);
	else
		start_my_philos(&env, ph);
	destroy_mutex(ph, &env, env.nb_philo);
	while (++i < env.nb_philo)
		pthread_join(ph[i].ph, NULL);
	free(ph);
	return (0);
}
