/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilis_I.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:37:07 by mabdelou          #+#    #+#             */
/*   Updated: 2022/05/13 18:37:08 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	ft_error(char *error)
{
	int	a;

	a = 0;
	while (error[a])
		a++;
	write(2, error, a);
	return (1);
}

int	ft_isdigit(int a)
{
	if (a >= 48 && a <= 57)
		return (0);
	else
		return (1);
}

int	ft_check_argument_if_correct(char **argv)
{
	int	a;
	int	b;

	a = 0;
	while (argv[++a])
	{
		b = -1;
		while (argv[a][++b])
			if (ft_isdigit(argv[a][b]))
				return (ft_error("invalid argumment\n"));
		if (argv[a][0] == 0)
			return (ft_error("invalid argumment\n"));
	}
	return (0);
}

int	ft_create_philos(t_data *data)
{
	data->a = -1;
	data->old_time_eat = 0;
	data->num_of_times_eat = 0;
	return (0);
}

int	ft_wait_prosses(t_data *data)
{
	int	a;
	int	end_state;

	end_state = 0;
	a = -1;
	while (++a < data->number_of_philosophers)
	{
		waitpid(-1, &end_state, 0);
		end_state = end_state / 256;
		if (end_state == 0)
			kill(0, 2);
	}
	return (0);
}
