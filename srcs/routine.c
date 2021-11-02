/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 00:39:07 by ddecourt          #+#    #+#             */
/*   Updated: 2021/11/02 12:10:19 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	exec_routine(t_philo *ph)
{
	pthread_mutex_lock(ph->next_fork);
	pthread_mutex_lock(&ph->env->mutex_write);
	ft_print_status(ph, "has taken a fork");
	pthread_mutex_unlock(&ph->env->mutex_write);
	
	pthread_mutex_lock(&ph->fork);
	pthread_mutex_lock(&ph->env->mutex_write);
	ft_print_status(ph, "has taken a fork");
	pthread_mutex_unlock(&ph->env->mutex_write);
	
	//pthread_mutex_lock(&ph->env->eating);
	ph->last_meal= get_timestamp(ph->env->start_time);
	//pthread_mutex_unlock(&ph->env->eating);
	
	pthread_mutex_lock(&ph->env->mutex_write);
	ft_print_status(ph, "is eating");
	ft_usleep(ph->env->t_to_eat);
	pthread_mutex_unlock(&ph->env->mutex_write);
	
	pthread_mutex_unlock(&ph->fork);
	pthread_mutex_unlock(ph->next_fork);
	
	pthread_mutex_lock(&ph->env->mutex_write);
	ft_print_status(ph, "is sleeping");
	pthread_mutex_unlock(&ph->env->mutex_write);
	ft_usleep(ph->env->t_to_sleep);
	
	pthread_mutex_lock(&ph->env->mutex_write);
	ft_print_status(ph, "is thinking");
	pthread_mutex_unlock(&ph->env->mutex_write);
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
