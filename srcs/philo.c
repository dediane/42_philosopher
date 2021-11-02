/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:12:23 by ddecourt          #+#    #+#             */
/*   Updated: 2021/11/02 16:02:10 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*routine(void *arg)
{
	t_philo	*ph;

	
	ph = (t_philo *)(arg);
	while (1)
	{
		exec_routine(ph);
	}
	return (0);
}

int	is_someone_dead(t_philo *ph)
{
	int i;

	i = -1;
	while (1)
	{
		while (++i < ph->env->nb_philo)
		{
			if (ph[i].last_meal >= ph[i].env->t_to_die)
			{
				ft_print_status(&ph[i], "died");
				return(0);
			}
		}
		i = -1;
	}
	return(1);
}

int	check_dead(t_philo *ph)
{
	pthread_mutex_lock(&ph->env->mutex_write);
	if (ph->last_meal > (long)ph->env->t_to_die)
	{
		ft_print_status(ph, "died");
		return (1);
	}
	pthread_mutex_unlock(&ph->env->mutex_write);
	return (0);
}

// UNE PREMIERE BOUCLE
// BOUCLE A PART
// {
//		Assignation fourchette
// }
// init_time()
// while(i < nb)
//{
//	if(i % 2 == 0)
//			phthread_create( exec_routine)
//		TU VAS LANCER TOUS TES PAIRS
//}
//            | P1 |P2| P3 
// }
// usleep(250)
// if(i % 2 != 0)
 

void	init_my_philos(t_philo *ph, t_env *env, int nb)
{
	int	i;

	i = -1;
	env->nb_philo = nb;
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
	}
	init_time(env);
}

int	init_prog(int ac, char **av, t_env *env)
{
	if (ft_check_ac(ac) == 1)
		return (EXIT_FAILURE);
	if (ft_parsing(av, env) == 1)
		return (EXIT_FAILURE);
	return (0);
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
	init_mutex(&env);
	init_my_philos(ph, &env, nb_of_philo);
	while (++i < env.nb_philo)
	{
		if (i % 2 == 0)
			pthread_create(&ph[i].ph, NULL, routine, &ph[i]);
	}
	i = -1;
	ft_usleep(100);
	while (++i < env.nb_philo)
	{
		if (i % 2 != 0)
			pthread_create(&ph[i].ph, NULL, routine, &ph[i]);
	}
	i = -1;
	while (++i < env.nb_philo)
		pthread_join(&ph->ph[i], NULL);
}
