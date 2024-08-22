/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czheng-c <czheng-c@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 10:12:57 by czheng-c          #+#    #+#             */
/*   Updated: 2023/05/14 12:30:17 by czheng-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	len;

	if (s != NULL)
	{
		len = ft_strlen(s);
		i = 0;
		while (i < len)
		{
			ft_putchar_fd(s[i], fd);
			i++;
		}
	}
}
