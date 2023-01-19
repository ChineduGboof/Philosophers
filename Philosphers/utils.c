/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 07:39:18 by cegbulef          #+#    #+#             */
/*   Updated: 2023/01/18 15:22:46 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//doubts -> check the print statement 
static int	ft_isdigit(int ascii_nbr)
{
	if (ascii_nbr >= '0' && ascii_nbr <= '9')
		return (1);
	return (0);
}

int	check_digit(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 0;
	j = count * size;
	if (size >= SIZE_MAX / count)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	while (i < j)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

void	display(t_philo *phl, char *str)
{
	if (phl->args->end_game == false)
	{
		pthread_mutex_lock(&phl->args->output);
		printf("%lld\t : %d\t : %s\n", timestamp(phl->args), phl->id_num, str);
		pthread_mutex_unlock(&phl->args->output);
	}
}