/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:28:30 by cegbulef          #+#    #+#             */
/*   Updated: 2023/01/18 11:55:28 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_philo	t_philo;
typedef struct s_data	t_data;

typedef struct s_philo
{
	int				lunch_eaten;	//how many lunch has the philo eaten
	int				id_num;		//the philosopher's id
	pthread_t		thd;
	long long		last_lunch;	//
	int				r_fork;		//the right fork
	int				l_fork;		//the left fork
	t_data			*args;
}	t_philo;

typedef struct s_data
{
	int				error;
	int				end_game;
	int				end_lunch;
	long long		t_start;	//start count of time
	long long		t_eat;		//time to eat
	long long		t_die;		//time to die
	long long		t_sleep;	//time to sleep
	int				n_philo;	//number of philosphers passed in arg
	int				max_lunch;	//time to eat
	t_philo			*philo;		//struct for each philosopher
	pthread_mutex_t	output;		//
	pthread_mutex_t	checks;		//
	pthread_mutex_t	*fork;		//
}	t_data;

int			check_digit(char **str);
int			ft_atoi(const char *str);
int			check_arg_error(int argc, char **argv);
int			ft_atoi(const char *str);
long long	timestart(void);
long long	timestamp(t_data *data);
void		init_var(char **argv, t_data *data);
void		*ft_calloc(size_t count, size_t size);
void		init_philos(t_data *data);
void    	lunch_start(t_data *data);
void		*one_philo(void *p);
void		display(t_philo *phl, char *str);
void		ft_sleep(t_philo *phl, int t_2_wait);

// void		destroy(t_data *data);
// void		*living_philos(void *arg);


#endif