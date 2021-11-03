/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 00:39:07 by ddecourt          #+#    #+#             */
/*   Updated: 2021/11/03 15:26:34 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	exec_routine(t_philo *ph)
{
	pthread_mutex_lock(&ph->fork);
	ft_print_status(ph, "has taken a fork");
	pthread_mutex_lock(ph->next_fork);
	ft_print_status(ph, "has taken a fork");
	pthread_mutex_lock(&ph->env->eating);
	ph->last_meal = get_timestamp(ph->env->start_time);
	ph->time_he_eat++;
	pthread_mutex_unlock(&ph->env->eating);
	ft_print_status(ph, "is eating");
	ft_usleep(ph->env->t_to_eat);
	pthread_mutex_unlock(ph->next_fork);
	pthread_mutex_unlock(&ph->fork);
	ft_print_status(ph, "is sleeping");
	ft_usleep(ph->env->t_to_sleep);
	ft_print_status(ph, "is thinking");
}

void	destroy_mutex(t_philo *ph, t_env *env, int nb)
{
	int	i;

	i = -1;
	while (++i < nb)
	{
		pthread_mutex_destroy(&ph[i].fork);
	}
	pthread_mutex_destroy(&env->mutex_write);
	pthread_mutex_destroy(&env->eating);
}

void	ft_free_my_philos(t_philo *ph, int nb)
{
	int	i;

	i = -1;
	while (++i < nb)
	{
		free(&ph[i]);
	}
	free(&ph);
}

void	init_mutex(t_env *env)
{
	pthread_mutex_init(&env->mutex_write, NULL);
	pthread_mutex_init(&env->eating, NULL);
}
