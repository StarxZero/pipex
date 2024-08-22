/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czheng-c <czheng-c@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:52:28 by czheng-c          #+#    #+#             */
/*   Updated: 2023/05/28 13:38:23 by czheng-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*tst;

	if (size == SIZE_MAX)
		return (0);
	tst = (char *)malloc(count * size);
	if (tst != NULL)
		ft_bzero(tst, size * count);
	return (tst);
}
