/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:37:29 by mabdelou          #+#    #+#             */
/*   Updated: 2022/05/13 18:37:30 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	*ft_check(void *ptr)
{
	t_data	*data;

	data = (t_data *)ptr;
	while (data->all_eat == 0)
	{
		sem_wait(data->dead_mutex);
		if (ft_check_if_dead(data, data->a))
			exit(0);
		if (data->argc == 6 && data->num_of_times_eat
			>= data->number_of_times_each_philosopher_must_eat)
		{
			sem_post(data->dead_mutex);
			exit(1);
		}
		sem_post(data->dead_mutex);
		usleep(100);
	}
	return (NULL);
}

void	*works_list_for_phils(t_data *data)
{
	int	num_of_philo;

	if (data->number_of_philosophers == 1)
	{
		usleep(data->time_to_die * 1000);
		printf("%d %d dead\n", data->time_to_die, 1);
		data->all_eat = 1;
		exit(0);
	}
	num_of_philo = data->a;
	if (num_of_philo % 2 == 0)
		usleep(10000);
	while (1337)
	{
		ft_take_forks(data, num_of_philo);
		ft_philo_eat(data, num_of_philo);
		ft_philo_sleep(data, num_of_philo);
	}
}

int	ft_create_prosses(t_data *data)
{
	int	pid;

	data->a = -1;
	data->old_time = ft_calc_time(data);
	while (++data->a < data->number_of_philosophers)
	{
		pid = fork();
		if (pid == 0)
		{
			if (pthread_create(&data->phil, NULL, &ft_check, data) != 0)
			{
				ft_error("ERROR : can't create thread\n");
				exit(1);
			}
			works_list_for_phils(data);
		}
		else if (pid == -1)
			return (ft_error("ERROR : can't create thread\n"));
	}
	return (0);
}

int	ft_data_init(t_data *data, char **argv)
{
	int	a;

	a = -1;
	data->all_eat = 0;
	data->old_time = 0;
	data->time_now = 0;
	data->number_of_philosophers = ft_atoi(argv[1]);
	if (data->number_of_philosophers == 0)
		return (ft_error("invalid num of phils\n"));
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (data->argc == 6)
		data->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	data->a = -1;
	sem_unlink("forks1");
	data->mutex_eat = sem_open("forks1", O_CREAT,
			0644, data->number_of_philosophers);
	sem_unlink("dead1");
	data->dead_mutex = sem_open("dead1", O_CREAT,
			0644, 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->argc = argc;
	if (argc != 5 && argc != 6)
		return (ft_error("too litle or too many argumment\n"));
	if (ft_check_argument_if_correct(argv))
		return (1);
	if (ft_data_init(data, argv))
		return (1);
	if (ft_create_philos(data))
		return (1);
	if (ft_create_prosses(data))
		return (1);
	if (ft_wait_prosses(data))
		return (1);
	return (0);
}
