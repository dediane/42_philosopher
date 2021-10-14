/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:51:13 by ddecourt          #+#    #+#             */
/*   Updated: 2021/10/14 19:11:50 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_parsing(char **av, t_env *var)
{
	var->nb_philo = ft_atoi(av[1]);
	var->t_to_die = ft_atoi(av[2]);
	var->t_to_eat = ft_atoi(av[3]);
	var->t_to_sleep = ft_atoi(av[4]);
	if (var->nb_philo <= 0 || var->t_to_die <= 0 || var->t_need_eat <= 0 || var->t_to_sleep >= 0)
		return(1); 
	if (av[5] != NULL)
		var->t_need_eat = ft_atoi(av[5]);
	return (0);
}