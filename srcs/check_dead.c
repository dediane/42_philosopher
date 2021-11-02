/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:13:28 by ddecourt          #+#    #+#             */
/*   Updated: 2021/11/03 00:25:04 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	check_dead(t_philo *ph)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (++i < ph->env->nb_philo)
	{
		pthread_mutex_lock(&ph->philo_mutex);
		if (ph[i].time_he_eat == ph[i].env->nb_time_eat)
		{
			j++;
			if (j == ph->env->nb_philo)
			{
				ph[i].env->is_dead = 1;
				return (1);
			}
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
