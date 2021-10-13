/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dianedecourt <dianedecourt@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 23:24:16 by ddecourt          #+#    #+#             */
/*   Updated: 2021/10/13 23:32:02 by dianedecour      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main(int ac, char **av)
{
	if (ac != 5 || ac != 6)
	{
		printf("Usage: ./philo number_of_philosopher time_to_die time_to_eat \
		time_to_sleep [number_of_times_each_philosopher_must_eat]");
		return (1);
	}
}

