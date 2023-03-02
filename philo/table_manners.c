/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_manners.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:56:34 by cegbulef          #+#    #+#             */
/*   Updated: 2023/01/28 20:00:56 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*one_philo(void *p)
{
	t_philo	*phl;

	phl = (t_philo *)p;
	pthread_mutex_lock(&phl->args->fork[phl->l_fork]);
	display(phl, "\U0001F944 \e[0;32m has taken a fork \033[0m");
	ft_usleep(phl, phl->args->t_die);
	pthread_mutex_unlock(&phl->args->fork[phl->l_fork]);
	display(phl, "\U0001F480 \033[1;31m died \033[0m");
	pthread_mutex_lock(&phl->args->checks);
	phl->args->end_game = true;
	pthread_mutex_unlock(&phl->args->checks);
	return (NULL);
}

void	pick_fork(t_philo *phl)
{
	if (phl->id_num % 2)
	{
		usleep(1500);
		pthread_mutex_lock(&phl->args->fork[phl->l_fork]);
		pthread_mutex_lock(&phl->args->fork[phl->r_fork]);
		display_fork(phl);
	}
	else
	{
		pthread_mutex_lock(&phl->args->fork[phl->r_fork]);
		pthread_mutex_lock(&phl->args->fork[phl->l_fork]);
		display_fork(phl);
	}
}

void	phl_eats(t_philo *phl)
{
	bool	lock;

	lock = true;
	pthread_mutex_lock(&phl->args->checks);
	if (phl->args->end_game == false)
	{
		lock = false;
		pthread_mutex_unlock(&phl->args->checks);
		pick_fork(phl);
		display(phl, "\U0001F958 \e[0;34m is eating \033[0m");
		pthread_mutex_lock(&phl->args->checks);
		phl->last_lunch = timestamp(phl->args);
		phl->lunch_eaten++;
		pthread_mutex_unlock(&phl->args->checks);
		ft_usleep(phl, phl->args->t_eat);
		pthread_mutex_unlock(&phl->args->fork[phl->l_fork]);
		pthread_mutex_unlock(&phl->args->fork[phl->r_fork]);
	}
	if (lock)
		pthread_mutex_unlock(&phl->args->checks);
}

void	phl_thinks(t_philo *phl)
{
	if (phl->args->end_game == false)
		display(phl, "\U0001F914 \e[0;33m is thinking \033[0m");
}

void	phl_sleeps(t_philo *phl)
{
	if (phl->args->end_game == false)
	{
		display(phl, "\U0001F6CC \e[0;36m is sleeping \033[0m");
		ft_usleep(phl, phl->args->t_sleep);
	}
}
