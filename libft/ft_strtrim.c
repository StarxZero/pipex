/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czheng-c <czheng-c@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:22:15 by czheng-c          #+#    #+#             */
/*   Updated: 2023/05/15 14:42:00 by czheng-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*cs1;
	char	*cset;

	start = 0;
	if (!s1 || !set)
		return (0);
	cs1 = (char *)s1;
	cset = (char *)set;
	while ((ft_strchr(set, cs1[start])) && cs1[start] != '\0')
	{
		start++;
	}
	end = ft_strlen(cs1) - 1;
	while ((ft_strchr(set, cs1[end])) && end > 0)
	{
		end--;
	}
	return (ft_substr(cs1, start, end - start + 1));
}
