/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:13:28 by ddecourt          #+#    #+#             */
/*   Updated: 2021/11/03 15:24:35 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	check_dead(t_philo *ph)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (++i < ph->env->nb_philo)
	{
		pthread_mutex_lock(&ph[i].env->eating);
		if (ph[i].time_he_eat == ph[i].env->nb_time_eat)
		{
			j++;
			pthread_mutex_lock(&ph[i].env->death_mutex);
			if (j == ph->env->nb_philo)
			{
				ph[i].env->is_dead = 1;
				return (1);
			}
			pthread_mutex_unlock(&ph[i].env->death_mutex);
		}
		if ((get_timestamp(ph[i].env->start_time) - ph[i].last_meal) > \
		(long)ph[i].env->t_to_die)
		{
			ft_print_status(ph, "died");
			pthread_mutex_lock(&ph[i].env->death_mutex);
			ph[i].env->is_dead = 1;
			pthread_mutex_unlock(&ph[i].env->death_mutex);
			return (1);
		}
		else
		{
			pthread_mutex_lock(&ph[i].env->death_mutex);
			ph->env->is_dead = 0;
			pthread_mutex_unlock(&ph[i].env->death_mutex);
		}
		pthread_mutex_unlock(&ph[i].env->eating);
	}
	return (0);
}
