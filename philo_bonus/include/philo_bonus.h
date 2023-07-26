/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:36:46 by mabdelou          #+#    #+#             */
/*   Updated: 2022/05/13 18:36:47 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

typedef struct s_data
{
	int			a;
	int			number_of_philosophers;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep ;
	long long	time_now;
	long long	old_time;
	int			all_eat;
	int			number_of_times_each_philosopher_must_eat;
	int			argc;
	sem_t		*mutex_eat;
	sem_t		*dead_mutex;
	pthread_t	phil;
	int			old_time_eat;
	int			num_of_times_eat;
}	t_data;

int			ft_atoi(const char *str);
int			ft_error(char *error);
int			ft_free(t_data *data);
int			ft_check_argument_if_correct(char **argv);
int			ft_check_if_all_eat(t_data *data);
long long	ft_calc_time(t_data *data);
int			ft_check_if_dead(t_data *data, int num_of_philo);
void		ft_usleep(t_data *data, int time);
int			ft_create_philos(t_data *data);
int			ft_wait_prosses(t_data *data);
int			ft_take_forks(t_data *data, int num_of_philo);
int			ft_philo_eat(t_data *data, int num_of_philo);
int			ft_philo_sleep(t_data *data, int num_of_philo);

#endif
