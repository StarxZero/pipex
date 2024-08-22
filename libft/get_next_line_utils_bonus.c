/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czheng-c <czheng-c@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:31:16 by czheng-c          #+#    #+#             */
/*   Updated: 2023/07/29 10:28:17 by czheng-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *format)
{
	int	i;

	i = 0;
	if (!format)
		return (0);
	while (format[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *one, char *two)
{
	char	*format;
	int		i;
	int		j;

	i = 0;
	j = 0;
	format = ft_calloc(ft_strlen(one) + ft_strlen(two) + 1, 1);
	if (!format)
		return (NULL);
	while (one[i] != '\0')
	{
		format[i] = one[i];
		i++;
	}
	while (two[j] != '\0')
	{
		format[i++] = two[j++];
	}
	format[i] = '\0';
	return (format);
}

void	*ft_calloc(size_t count, size_t	size)
{
	char	*tst;
	size_t	i;

	i = 0;
	if (size == SIZE_MAX)
		return (0);
	tst = (char *)malloc(count * size);
	if (tst != NULL)
		while (i < count * size)
			tst[i++] = 0;
	return (tst);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == 0 && s[i] == '\0')
		return ((char *)&s[i]);
	return (0);
}
