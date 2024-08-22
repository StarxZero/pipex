/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czheng-c <czheng-c@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:35:24 by czheng-c          #+#    #+#             */
/*   Updated: 2023/07/31 09:32:47 by czheng-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	fni(char **one, char *get)
{
	free(*one);
	*one = get;
}

void	ft_separate(char **main, char **sub)
{
	int		i;
	int		j;
	char	*temp_main;
	char	*temp_sub;

	i = 0;
	j = 0;
	if (!**sub)
	{
		fni(*(&sub), NULL);
		return ;
	}
	temp_main = ft_calloc(ft_strlen(*sub) + 1, 1);
	temp_sub = ft_calloc(ft_strlen(*sub) + 1, 1);
	while ((*sub)[i] != '\0')
	{
		temp_main[i] = (*sub)[i];
		if (temp_main[i++] == '\n')
			break ;
	}
	while ((*sub)[i] != '\0')
		temp_sub[j++] = (*sub)[i++];
	fni(*(&main), temp_main);
	fni(*(&sub), temp_sub);
}

char	*get_next_line(int fd)
{
	static char	*res[5000];
	char		*store;
	char		*temp;
	ssize_t		len;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (!res[fd])
		res[fd] = ft_calloc(1, 1);
	store = ft_calloc(BUFFER_SIZE + 1, 1);
	while (!ft_strchr(res[fd], '\n'))
	{
		len = read(fd, store, BUFFER_SIZE);
		if (len <= 0 || !*store)
		{
			fni(&store, NULL);
			break ;
		}
		store[len] = '\0';
		temp = ft_strjoin(res[fd], store);
		fni(&res[fd], temp);
	}
	ft_separate(&store, &res[fd]);
	return (store);
}
