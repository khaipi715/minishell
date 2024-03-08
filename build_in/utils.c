// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   utils.c                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: lnaulak <lnaulak@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/03/01 12:31:55 by lnaulak           #+#    #+#             */
// /*   Updated: 2024/03/01 13:02:15 by lnaulak          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../includes/minishell.h"

// void	free_all(char **to_free)
// {
// 	int	i;

// 	i = 0;
// 	while (to_free[i])
// 	{
// 		free(to_free[i]);
// 		i++;
// 	}
// 	free(to_free);
// }

// int	path_check(char *str)
// {
// 	if (str[0] == 'P')
// 		if (str[1] == 'A')
// 			if (str[2] == 'T')
// 				if (str[3] == 'H')
// 					if (str[4] == '=')
// 						return (0);
// 	return (1);
// }

// char	*get_env(char *envp[])
// {
// 	int		i;
// 	char	*ret;

// 	i = 0;
// 	while (envp[i])
// 	{
// 		if (path_check(envp[i]) == 0)
// 			break ;
// 		i++;
// 	}
// 	if (envp[i] == NULL)
// 		return (NULL);
// 	ret = ft_strdup((const char *)&envp[i][5]);
// 	return (ret);
// }

// char	*get_path(char *cmd, char *env)
// {
// 	int		i;
// 	char	**paths;
// 	char	*path;
// 	char	*exec;

// 	paths = ft_split(env, ':');
// 	i = 0;
// 	while (paths[i])
// 	{
// 		path = ft_strjoin(paths[i], "/");
// 		exec = ft_strjoin(path, cmd);
// 		free(path);
// 		if (access(exec, X_OK) == 0)
// 		{
// 			free_all(paths);
// 			return (exec);
// 		}
// 		i++;
// 	}
// 	ft_putstr_fd("Error: Command not found\n", 2);
// 	return (NULL);
// }

// char	**sep_command(char *cmd, char *envp[])
// {
// 	char	**ret;
// 	char	*env;

// 	ret = px_split(cmd);
// 	env = get_env(envp);
// 	ret[0] = get_path(ret[0], env);
// 	return (ret);
// }