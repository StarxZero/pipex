/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czheng-c <czheng-c@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:05:58 by czheng-c          #+#    #+#             */
/*   Updated: 2023/05/28 13:33:00 by czheng-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*cdest;
	unsigned char	*csrc;

	if (!dest && !src)
		return (dest);
	cdest = (unsigned char *)dest;
	csrc = (unsigned char *)src;
	if (csrc <= cdest)
	{
		while (len)
		{
			cdest[len - 1] = csrc[len - 1];
			len--;
		}
	}
	else
	{
		while (len--)
		{
			*(cdest++) = *(csrc++);
		}
	}
	return (dest);
}
