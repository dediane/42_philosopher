/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:12:23 by ddecourt          #+#    #+#             */
/*   Updated: 2021/10/27 00:37:06 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*routine(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *)(arg);
	//while (!is_dead(ph))
		exec_routine(ph);
	return (0);
}

int	is_dead(t_philo *ph)
{
	int i;
	
	i = -1;
	while (&ph->ph[++i])
	{
		if (ph[i].last_meal > ph[i].env->t_to_die)
		{
			printf("Valeur de last meal : %ld et valeur de t_to_die : %ld\n", ph[i].last_meal, ph[i].env->t_to_die);
			return (1);
		}
	}
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
		pthread_create(&ph[i].ph, NULL, &routine, &ph[i]);
		pthread_mutex_init(&ph[i].fork, NULL);
		pthread_mutex_init(&ph[i].mutex_write, NULL);
		ph[i].env = env;
		ph[i].last_meal = 0;
		if (i == nb - 1)
			ph[i].next_fork = ph[0].fork;
		else
			ph[i].next_fork = ph[i + 1].fork;
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
	ph = malloc(sizeof(t_philo) * (nb_of_philo + 1));
	if (!ph)
		return (0);
	init_my_philos(ph, &env, nb_of_philo);
	while (i < env.nb_philo)
		pthread_join(&ph->ph[++i], NULL);
	printf("Parsing successful\n");
}
