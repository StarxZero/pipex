/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czheng-c <czheng-c@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 08:56:59 by czheng-c          #+#    #+#             */
/*   Updated: 2023/05/11 15:06:01 by czheng-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == 45 || str[i] == 43)
		if (str[i++] == 45)
			sign = -1;
	while (str[i] != '\0')
	{
		if (str[i] >= 48 && str[i] <= 57)
			result = result * 10 + str[i] - 48;
		else
			break ;
		i++;
	}
	return (result * sign);
}
