/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_misc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czheng-c <czheng-c@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:13:55 by czheng-c          #+#    #+#             */
/*   Updated: 2023/11/10 13:14:40 by czheng-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	perror_n_exit(char *s)
{
	perror(s);
	exit(EXIT_FAILURE);
}

void	print_n_exit(char *s)
{
	write(1, "Error\n", 6);
	ft_putstr_fd(s, 1);
	exit (0);
}

void	free_n_init(char **old, char *new)
{
	free(*old);
	*old = new;
}
