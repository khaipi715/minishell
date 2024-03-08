// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   echo.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: lnaulak <lnaulak@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/02/20 12:44:09 by npaturzo          #+#    #+#             */
// /*   Updated: 2024/03/01 13:38:48 by lnaulak          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// //echo with option -n

// #include "../includes/minishell.h"

// int	ms_echo_ops(char *str)
// {
// 	if (str[0] == '-')
// 		if (str[1] == 'n')
// 			if (str[2] == '\0')
// 				return (1);
// 	return (0);
// }

// void	ms_echo(int argc, char *args[])
// {
// 	int	n;
// 	int	i;
// 	printf("echo build in\n");

// 	n = ms_echo_ops(args[0]);
// 	i = 0;
// 	if (n == 1)
// 	{
// 		i++;
// 		argc--;
// 	}
// 	while (args[i])
// 	{
// 		printf("%s", args[i]);
// 		if (i < argc)
// 			printf(" ");
// 		i++;
// 	}
// 	if (n == 0)
// 		printf("\n");
// }

// //main for testing
// /*
// int	main(int argc, char *argv[])
// {
// 	if (argc == 1)
// 		return (1);
// 	ms_echo(argc - 1, &argv[1]);
// 	return (0);
// }
// */
