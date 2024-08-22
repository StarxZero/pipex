/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czheng-c <czheng-c@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 11:59:32 by czheng-c          #+#    #+#             */
/*   Updated: 2023/05/11 09:41:17 by czheng-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*cb;
	char	cc;

	cb = (char *)b;
	cc = (char )c;
	while (len--)
	{
		cb[len] = cc;
	}
	return (cb);
}
