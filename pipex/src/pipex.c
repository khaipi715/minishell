/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaulak <lnaulak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:22:14 by npaturzo          #+#    #+#             */
/*   Updated: 2024/03/04 15:32:55 by lnaulak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd1(char *argv[], char *envp[], int *pfd)
{
	int		in_fd;
	char	**command;

	in_fd = open(argv[1], O_RDONLY);
	if (in_fd == -1)
	{
		ft_putstr_fd("Error: Failed to open infile\n", 2);
		exit(1);
	}
	dup2(in_fd, 0);
	dup2(pfd[1], 1);//to put the command to the write end
	close(pfd[0]);//to not cause dead lock as this pipe will be the writing end only
	command = sep_command(argv[2], envp);
	execve(command[0], command, envp);
}

void	cmd2(char *argv[], char *envp[], int *pfd)
{
	int		out_fd;
	char	**command;

	out_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (out_fd == -1)
	{
		ft_putstr_fd("Error: Failed to write outfile\n", 2);
		exit(1);
	}
	dup2(pfd[0], 0);
	dup2(out_fd, 1);
	close(pfd[1]);//to not cause dead lock as this function is only used for reading
	command = sep_command(argv[3], envp);
	execve(command[0], command, envp);
}

int	main(int argc, char *argv[], char *envp[])
{
	int	pfd[2];
	int	pid;

	if (argc != 5)
	{
		ft_printf("Error: Arguments wanted = infile cmd1 cmd2 outfile\n");
		exit(1);
	}
	if (pipe(pfd) == -1)
		exit(1);
	pid = fork();
	if (pid < 0)
		exit(1);
	if (pid == 0)
		cmd1(argv, envp, pfd);
	cmd2(argv, envp, pfd);
}
