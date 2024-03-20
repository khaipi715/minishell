/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaulak <lnaulak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:27:29 by lnaulak           #+#    #+#             */
/*   Updated: 2024/03/13 14:44:11 by lnaulak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr("\n");
		signal(SIGINT, signal_handler);
	}
}
char	**before_re(t_monitor *monitor)
{
	char	**s;
	int		i;

	i = -1;
	s = monitor->input_token;
	while (monitor->input_token[++i])
		if (ft_isredirect(monitor->input_token[i][0]) != 0)
		{
			s[i] = NULL;
			break ;
		}
	return (s);
}
void	ft_cmd(t_monitor *monitor)
{
	char	**command;
	int		i;

	command = sep_command(monitor->input_token[0], monitor->envp);
	i = -1;//need to use chdir for the 'cd' command
	while (command[++i])
		printf("%s %d\n", command[i], i);
	execve(command[0], monitor->input_token, monitor->envp);
	write_error("execve error\n");
}

char	*input_redirect(t_monitor *monitor)
{
	char	*s;
	int		i;

	i = -1;
	while (monitor->input_token[++i])
		if (ft_isredirect(monitor->input_token[i][0]) != 0)
			s = monitor->input_token[i + 1];//need to make sure there is something in i + 1
	return (s);
}

void	re_cmd(t_monitor *monitor, int *p_fd)
{
	char	**command;

	dup2(p_fd[1], 1);
	close(p_fd[0]);
	command = sep_command(monitor->input_token[0], monitor->envp);
	execve(command[0], before_re(monitor), monitor->envp);//im assuming the reason why we need this is to kill the process
	write_error("redirect execve error\n");
}

void re_output(t_monitor *monitor, int *p_fd)
{
	char	**command;
    int		out_fd;
    char	*file;

    file = input_redirect(monitor);
    printf("\nfile: %s\n", file);
    out_fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (out_fd == -1)
	{
        write_error("Error opening output file\n");
        exit(1);
    }
    dup2(out_fd, 1);
    close(p_fd[1]);
    command = sep_command(monitor->input_token[0], monitor->envp);
    execve(command[0], before_re(monitor), monitor->envp);
    perror("Redirect execve error\n");
    exit(1);
}


void	rev_re_cmd(t_monitor *monitor, int *p_fd)
{
	char	**command;
    int		out_fd;
    char	*file;

    file = input_redirect(monitor);
    printf("\nfile: %s\n", file);
    out_fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (out_fd == -1)
	{
        write_error("Error opening output file\n");
        exit(1);
    }
    dup2(out_fd, 0);
    command = sep_command(monitor->input_token[0], monitor->envp);
    execve(command[0], before_re(monitor), monitor->envp);
    perror("Redirect execve error\n");
    exit(1);
}

void	redirect(t_monitor	*monitor)
{
	int		p_fd[2];
	pid_t	pid;

	if (pipe(p_fd) == -1)
		write_error("pipe error");
	pid = fork();
	if (pid == 0)
	{
		if (monitor->input_token[1][0] == '>')//will need to rework as it wont work with muiplte redirect ls > hello | ls > hi
			re_cmd(monitor, p_fd);
		else if (monitor->input_token[1][0] == '<')
			rev_re_cmd(monitor, p_fd);
	}
	else
	{
		if (monitor->input_token[1][0] == '>')//will need to rework as it wont work with muiplte redirect ls > hello | ls > hi
			re_output(monitor, p_fd);
		waitpid(pid, NULL, 0);
	}
}

void	engine(t_monitor *monitor)
{
	int		i;
	pid_t	pid;

	while (1)
	{
		monitor->input = display_prompt_msg();
		monitor->input_token = ft_tokenizer(monitor->input, monitor);
		monitor->nb_tokens = ft_tlen(monitor->input_token);
		signal(SIGINT, signal_handler);
		pid = fork();
		if (pid == -1)
			return ;
		else if (pid == 0)
		{
			i = -1;
			printf("nb token: %d\n", monitor->nb_tokens);
			init_tokens(monitor);
			if (monitor->has_redirect == true)
			{ 
				redirect(monitor);
				monitor->has_redirect = false;
			}
			else
				ft_cmd(monitor);
		}
		else
			wait(NULL);
	}
}
