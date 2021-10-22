/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:12:23 by ddecourt          #+#    #+#             */
/*   Updated: 2021/10/22 18:48:36 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *ph)
{
	pthread_mutex_lock(ph);
	printf("has taken a fork \n");
	pthread_mutex_unlock(ph);
	return(0);
}

void	ft_fill_my_philos(t_philo *ph, t_env *var, int nb)
{
	int i;

	i = -1;
	while(++i < nb)
	{
		ph->id = i + 1;
		pthread_mutex_init(&(ph[i].fork), NULL);
		//pthread_create(&(ph[i].philo), NULL, &routine, NULL);
		pthread_create(&ph[i].philo, NULL, &routine, &ph[i]);
		printf("Philo %i is created\n", ph->id);
		var->start_time = 0;
	}
}

int	main(int ac, char** av)
{
	t_philo *ph;
	t_env var;
	int nb_of_philo;
	
	nb_of_philo = ft_atoi(av[1]);
	ph = malloc(sizeof(t_philo) * (nb_of_philo + 1));
	if (!ph)
		return ((int)NULL);
	ft_parsing(ac, av, &var);
	ft_fill_my_philos(ph, &var, nb_of_philo);
	return (0);
}