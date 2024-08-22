/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czheng-c <czheng-c@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:20:58 by czheng-c          #+#    #+#             */
/*   Updated: 2023/12/11 15:21:20 by czheng-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check(t_pipe pip, char **box, int j)
{
	char	*tmp;

	while (box[j] != (void *) '\0')
	{
		if (ft_strncmp(box[j], pip.go[0], ft_strlen(box[j])) == 0)
			tmp = pip.go[0];
		else
		{
			tmp = ft_strjoin(box[j], "/");
			tmp = ft_strjoin(tmp, pip.go[0]);
		}
		if (access(tmp, 0) == 0)
			return (tmp);
		free(tmp);
		j++;
	}
	perror_n_exit("Command does not exist");
	return (NULL);
}

void	child1(t_pipe pip, char **box, char **av, char **envp)
{
	char	*tmp;

	close(pip.pipe_fd[1]);
	if (dup2(pip.pipe_fd[0], 0) == -1)
		perror_n_exit("dup2");
	close(pip.pipe_fd[0]);
	dup2(pip.f2, 1);
	pip.go = ft_split(av[3], ' ');
	tmp = check(pip, box, 0);
	if (execve(tmp, pip.go, envp) == -1)
		perror_n_exit("Child process failed");
	free(tmp);
}

void	parent1(t_pipe pip, char **box, char **av, char **envp)
{
	char	*tmp;

	close(pip.pipe_fd[0]);
	if (dup2(pip.pipe_fd[1], 1) == -1)
		perror_n_exit("dup2");
	close(pip.pipe_fd[1]);
	dup2(pip.f1, 0);
	pip.go = ft_split(av[2], ' ');
	tmp = check(pip, box, 0);
	if (execve(tmp, pip.go, envp) == -1)
		perror_n_exit("Parent process failed");
	free(tmp);
}

int	main(int ac, char **av, char **envp)
{
	char	**box;
	t_pipe	pip;

	if (ac != 5)
		print_n_exit("Run command like this\n./pipex file1 cmd1 cmd2 file2\n");
	pip.f1 = open(av[1], O_RDONLY);
	pip.f2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pip.f1 == -1 || pip.f2 == -1)
		perror_n_exit("File error:");
	while (ft_strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	box = ft_split(*envp + 5, ':');
	if (pipe(pip.pipe_fd) == -1)
		perror_n_exit("pipe");
	pip.child_pid = fork();
	if (pip.child_pid == -1)
		perror_n_exit("fork");
	if (pip.child_pid == 0)
		child1(pip, box, av, envp);
	else
		parent1(pip, box, av, envp);
	return (0);
}
