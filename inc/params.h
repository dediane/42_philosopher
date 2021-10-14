/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 01:09:16 by ddecourt          #+#    #+#             */
/*   Updated: 2021/10/14 19:24:24 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

typedef struct s_philo
{
	int	id;
	pthread_t philo;
	/*pthread_mutex_t	fork;
	pthread_mutex_t	eat;
	pthread_mutex_t	sleep;*/
}		t_philo;

typedef struct s_env
{
	long	start_time;
	int		nb_philo;
	int		t_to_die;
	int		t_to_eat;
	int		t_to_sleep;
	int		t_need_eat;
}		t_env;