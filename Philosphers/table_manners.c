/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_manners.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:56:34 by cegbulef          #+#    #+#             */
/*   Updated: 2023/01/19 17:20:21 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*one_philo(void *p)
{
	t_philo	*phl;

	phl = (t_philo *)p;
	pthread_mutex_lock(&phl->args->fork[phl->l_fork]);
	display(phl, "\U0001F944 just got a fork");
	phl->last_lunch = timestamp(phl->args);
	ft_sleep(phl, phl->args->t_die);
	display(phl, "\U0001F480 \033[1;31m died \033[0m");
	phl->args->end_game = true;
	return (NULL);
}

void	phl_eat(t_philo *phl)
{
	if (phl->args->end_game == false)
	{
		pthread_mutex_lock(&phl->args->fork[phl->l_fork]);
		print(phl, "\U0001F944 just got a fork");
		pthread_mutex_lock(&phl->args->fork[phl->r_fork]);
		print(phl, "just got a fork");
		print(phl, "\U0001F958 \e[0;34m is eating \033[0m");
		phl->last_lunch = timestamp(phl->args);
		phl->lunch_eaten++;
		ft_sleep(phl, phl->args->t_eat);
		pthread_mutex_unlock(&phl->args->fork[phl->l_fork]);
		pthread_mutex_unlock(&phl->args->fork[phl->r_fork]);
	}
}

// void	phl_wait(t_philo *phl)

// void	phl_sleep(t_philo *phl)