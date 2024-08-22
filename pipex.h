/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czheng-c <czheng-c@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:25:19 by czheng-c          #+#    #+#             */
/*   Updated: 2023/12/11 15:25:25 by czheng-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "./libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>

typedef struct s_pipe
{
	pid_t	child_pid;
	int		pipe_fd[2];
	int		f1;
	int		f2;
	char	**go;
	int		status;
}	t_pipe;

#endif
