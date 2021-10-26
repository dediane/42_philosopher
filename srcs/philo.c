/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:12:23 by ddecourt          #+#    #+#             */
/*   Updated: 2021/10/26 14:54:43 by ddecourt         ###   ########.fr       */
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
	while (++i <= (nb - 1))
	{
		ph[i].id = i + 1;
		pthread_create(&ph[i].philo, NULL, &routine, &ph[i]);
		pthread_mutex_init(&ph[i].fork, NULL);
		pthread_mutex_init(&ph[i].mutex_write, NULL);
		ph[i].init_time = 0;
		ph[i].t_wait = 0;
		if (i == nb - 1)
			ph[i].next_fork = ph[0].fork;
		else	
			ph[i].next_fork = ph[i + 1].fork;
	}
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
