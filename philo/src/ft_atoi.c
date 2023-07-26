/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 13:33:31 by mabdelou          #+#    #+#             */
/*   Updated: 2021/11/16 23:51:26 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_long_long(int b)
{
	if (b == 1)
		return (-1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	a;
	int	b;
	int	nb;
	int	longlon;

	longlon = 0;
	a = 0;
	b = 1;
	nb = 0;
	while ((str[a] >= 9 && str[a] <= 13) || str[a] == 32)
		a++;
	if (str[a] == '-' || str[a] == '+')
	{
		if (str[a] == '-')
			b = b * -1;
		a++;
	}
	while (str[a] >= '0' && str[a] <= '9')
	{
		nb = nb * 10 + (str[a++] - 48);
		longlon++;
	}
	if (longlon > 10)
		return (ft_long_long(b));
	return (nb * b);
}
