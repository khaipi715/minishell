/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaulak <lnaulak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:52:41 by lnaulak           #+#    #+#             */
/*   Updated: 2024/03/08 13:35:45 by lnaulak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// void	end_of_file(t_data *data, char *user_monitor.input)
// {
// 	// free_env(data->env);//free env
// 	free(user_monitor.input);
// 	free(data->pwd);
// 	ft_putstr_fd("exit\n", 2);
// 	exit(EXIT_SUCCESS);
// }

// int		ft_cmd(t_monitor *data)
// {
// 	char	**command;

// 	command = sep_command(argv[0], envp);
// 	i = -1;
// 	while (command[++i])
// 		printf("%s %d\n", command[i], i);
// 	execve(command[0], argv, envp);
// }

int	init_all(int ac, char **av, char **env, t_monitor *monitor)
{
	(void) ac;
	(void) av;
	monitor->env = env;
	monitor->nb_tokens = 0;
	monitor->start = 0;
	monitor->end = 0;
	return (0);
}

int	main(int ac, char **av, char **env)
{
	t_monitor		monitor;

	if (init_all(ac, av, env, &monitor) == 0)
		engine(&monitor);
	else
		return (1);
	return (0);
}
