/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czheng-c <czheng-c@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 10:46:15 by czheng-c          #+#    #+#             */
/*   Updated: 2023/05/28 13:29:40 by czheng-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(char *nbr, int i)
{
	char	temp;
	int		size;
	int		j;

	j = 0;
	size = i;
	while (j < size / 2)
	{
		temp = nbr[j];
		nbr[j++] = nbr[--i];
		nbr[i] = temp;
	}
	nbr[size] = '\0';
}

int	length(long j)
{
	int	i;

	i = 0;
	if (j == 0)
		i++;
	if (j < 0)
	{
		i++;
		j *= -1;
	}
	while (j > 0)
	{
		i++;
		j = j / 10;
	}
	return (i);
}

void	work(char *nbr, long nb, int sign)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		sign = -1;
		nb *= -1;
	}
	if (nb == 0)
		nbr[i++] = 48;
	while (nb)
	{
		nbr[i++] = (nb % 10) + 48;
		nb = nb / 10;
	}
	if (sign < 0)
		nbr[i++] = '-';
	ft_swap(nbr, i);
}

char	*ft_itoa(int n)
{
	char	*nbr;
	int		sign;
	long	nb;

	nb = n;
	sign = 1;
	nbr = (char *)malloc(length(nb) + 1);
	if (!nbr)
		return (0);
	work(nbr, nb, sign);
	return (nbr);
}
