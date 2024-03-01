/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaulak <lnaulak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:52:41 by lnaulak           #+#    #+#             */
/*   Updated: 2024/03/01 13:06:58 by lnaulak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// void	end_of_file(t_data *data, char *user_input)
// {
// 	// free_env(data->env);//free env
// 	free(user_input);
// 	free(data->pwd);
// 	ft_putstr_fd("exit\n", 2);
// 	exit(EXIT_SUCCESS);
// }

int	init_data(int ac, char **av, char **env, t_data *data)
{
	ac = 0;
	av = NULL;
	data->env = (env);//get malloc of enviroment
	data->pwd = getcwd(NULL, 0);//might need to change
	data->fd_in = 0;
	data->fd_out = 1;
	data->redir = 1;
	if (!(data->env))
		return (1);
	else
		return (0);
}

// t_list	*ft_newtoken(char *content)
// {
// 	t_list	*rtn;

// 	rtn = (t_list *)malloc(sizeof(t_list));
// 	if (!rtn)
// 		return (rtn = NULL);
// 	rtn->next = NULL;
// 	rtn->content = content;
// 	return (rtn); 
// }

void	ft_cmd(int argc, char *argv[], char *envp[])
{
	char	**command;

	if (ft_strcmp(argv[0], "echo") == 0 || ft_strcmp(argv[0], "env") == 0 || ft_strcmp(argv[0], "pwd") == 0|| ft_strcmp(argv[0], "cd") == 0)
	{
		if (ft_strcmp(argv[0], "echo") == 0)
			ms_echo(argc, argv);//not working
		else if (ft_strcmp(argv[0], "env") == 0)
			ms_env(envp);//working
		else if (ft_strcmp(argv[0], "pwd") == 0)
			ms_cd(*envp);//not working
		else if (ft_strcmp(argv[0], "cd") == 0)
			ms_cd(*argv);//not working
		return ;
	}
	printf("not build in\n");
	command = sep_command(argv[0], envp);
	execve(command[0], argv, envp);
}

int	main(int ac, char **av, char **env)
{
	t_data		data;
	char	*input;
	char	**s;
	int		i;
	pid_t	pid;


	if (init_data(ac, av, env, &data) == 1)
		return (1);
	while (1)
	{
		pid = fork();
		if (pid == -1)
			return (1);
		else if (pid == 0)
		{
			i = 0;
			input = readline("minshell$ ");
			s = ft_tokenizer(input);
			ft_cmd(ac, s, env);//for all in build function it should be in the first argument so arg[0]
		}
		else
			wait(NULL);
	}
	return (0);
}
