/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:13:28 by ddecourt          #+#    #+#             */
/*   Updated: 2021/11/02 19:12:06 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*int	is_someone_dead(t_philo *ph)
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
				ph->env->is_dead = 1;
				return (1);
			}
			else
				ph->env->is_dead = 0;
		}
		i = -1;
	}
	return(1);
}*/

int	check_dead(t_philo *ph)
{
	int i;

	i = -1;
	while (++i < ph->env->nb_philo)
	{
		pthread_mutex_lock(&ph->philo_mutex);
		if (ph[i].time_he_eat == ph[i].env->nb_time_eat)
		{
			ph[i].env->is_dead = 1;
			return (1);
		}
		if ((get_timestamp(ph[i].env->start_time) - ph[i].last_meal) > (long)ph[i].env->t_to_die)
		{
			ft_print_status(ph, "died");
			ph[i].env->is_dead = 1;
			return (1);
		}
		else
			ph->env->is_dead = 0;
		pthread_mutex_unlock(&ph->philo_mutex);
	}
	return (0);
}
