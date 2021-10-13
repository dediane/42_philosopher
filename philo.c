/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 23:24:16 by ddecourt          #+#    #+#             */
/*   Updated: 2021/10/14 01:10:53 by ddecourt         ###   ########.fr       */
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
