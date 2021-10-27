/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:12:23 by ddecourt          #+#    #+#             */
/*   Updated: 2021/10/27 20:10:53 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*routine(void *arg)
{
	t_philo	*ph;

	
	ph = (t_philo *)(arg);
	while (1)
	{
		// if (check_dead(ph) == 1)
		// 	break;
		while (ph->id % 2 == 0)
		{
			// if (check_dead(ph) == 1)
			// 	break;
			ft_usleep(100);
			exec_routine(ph);
		}
		while (ph->id % 2 != 0)
		{
			// if (check_dead(ph) == 1)
			// 	break;
			exec_routine(ph);
		}
	}
	return (0);
}

int	check_dead(t_philo *ph)
{
	if (ph->last_meal > ph->env->t_to_die)
		return (1);
	return (0);
}

void	init_my_philos(t_philo *ph, t_env *env, int nb)
{
	int	i;

	i = -1;
	env->nb_philo = nb;
	init_time(env);
	while (++i <= (nb - 1))
	{
		ph[i].id = i + 1;
		pthread_mutex_init(&ph[i].fork, NULL);
		pthread_mutex_init(&ph[i].mutex_write, NULL);
		ph[i].env = env;
		ph[i].last_meal = 0;
		ph[i].init_time = env->start_time;
	}
	i = -1;
	while (++i <= (nb - 1))
	{
		if (i == nb - 1)
			ph[i].next_fork = &ph[0].fork;
		else
			ph[i].next_fork = &ph[i + 1].fork;
		pthread_create(&ph[i].ph, NULL, &routine, &ph[i]);
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
	nb_of_philo = ft_atoi(av[1]);
	ph = malloc(sizeof(*ph) * (nb_of_philo + 1));
	if (!ph)
		return (0);
	init_my_philos(ph, &env, nb_of_philo);
	while (i < env.nb_philo)
		pthread_join(&ph->ph[++i], NULL);
}
