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

void	eating_enough_time(t_philo *ph)
{
	ph->env->is_dead = 1;
	pthread_mutex_unlock(&ph->env->eating);
	pthread_mutex_unlock(&ph->env->death_mutex);
}

void	check_dead2(t_philo *ph)
{
	ft_print_status(ph, "died");
	pthread_mutex_lock(&ph->env->death_mutex);
	ph->env->is_dead = 1;
	pthread_mutex_unlock(&ph->env->death_mutex);
	pthread_mutex_unlock(&ph->env->eating);
}

void	check_dead3(t_philo *ph)
{
	pthread_mutex_lock(&ph->env->death_mutex);
	ph->env->is_dead = 0;
	pthread_mutex_unlock(&ph->env->death_mutex);
}

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
				return (eating_enough_time(&ph[i]), 1);
			pthread_mutex_unlock(&ph[i].env->death_mutex);
		}
		if ((get_timestamp(ph[i].env->start_time) - ph[i].last_meal) > \
		(long)ph[i].env->t_to_die)
			return (check_dead2(&ph[i]), 1);
		else
			check_dead3(&ph[i]);
		pthread_mutex_unlock(&ph[i].env->eating);
	}
	return (0);
}
