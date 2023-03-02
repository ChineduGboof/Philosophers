/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:28:30 by cegbulef          #+#    #+#             */
/*   Updated: 2023/01/28 20:03:53 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_philo	t_philo;
typedef struct s_data	t_data;

typedef struct s_philo
{
	int				lunch_eaten;
	int				id_num;
	pthread_t		thd;
	long long		last_lunch;
	int				r_fork;
	int				l_fork;
	t_data			*args;
}	t_philo;

typedef struct s_data
{
	int				error;
	bool			end_game;
	int				end_lunch;
	long long		t_start;
	long long		t_eat;
	long long		t_die;
	long long		t_sleep;
	int				n_philo;
	int				max_lunch;
	t_philo			*philo;
	pthread_mutex_t	checks;
	pthread_mutex_t	*fork;
}	t_data;

int			check_digit(char **str);
int			ft_atoi(const char *str);
int			check_arg_error(int argc, char **argv);
int			ft_atoi(const char *str);
int			int_overflow_check(t_data *data, char **argv);
long long	timestart(void);
long long	timestamp(t_data *data);
int			init_var(char **argv, t_data *data);
void		*ft_calloc(size_t count, size_t size);
void		init_philos(t_data *data);
void		lunch_start(t_data *data);
void		*philo_acts(void *val);
void		*one_philo(void *p);
void		display(t_philo *phl, char *str);
void		ft_usleep(t_philo *phl, int t_2_wait);
void		philo_destroy(t_data *data);
void		run_checks(t_data *data);
void		phl_eats(t_philo *phl);
void		phl_thinks(t_philo *phl);
void		phl_sleeps(t_philo *phl);
void		death_status(t_philo *phl);
void		pick_fork(t_philo *phl);
void		max_lunch_check(t_data *data);
void		display_fork(t_philo *phl);

#endif