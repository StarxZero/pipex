/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czheng-c <czheng-c@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 09:53:26 by czheng-c          #+#    #+#             */
/*   Updated: 2023/06/02 16:13:00 by czheng-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int	ft_word(char const *s, char c, int i)
{
	int	j;

	j = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

int	ft_size(char const *s, char c)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i] != '\0')
		{
			i = i + ft_word(s, c, i);
			j++;
		}
		else
			i++;
	}
	return (j);
}

char	*assign(char const *s, char c, int i)
{
	char	*temp;
	int		j;

	j = 0;
	temp = malloc(sizeof(char) * (ft_word(s, c, i) + 1));
	if (!temp)
		return (0);
	while (s[i] != c && s[i] != '\0')
		temp[j++] = s[i++];
	temp[j] = '\0';
	return (temp);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	str = malloc(sizeof(char *) * (ft_size(s, c) + 1));
	if (!str)
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			str[j] = assign(s, c, i);
			j++;
		}
		i = i + ft_word(s, c, i);
	}
	str[j] = NULL;
	return (str);
}
