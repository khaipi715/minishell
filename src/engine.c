/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaulak <lnaulak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:27:29 by lnaulak           #+#    #+#             */
/*   Updated: 2024/03/08 15:37:31 by lnaulak          ###   ########.fr       */
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

void	engine(t_monitor *monitor)
{
	int		i;
	pid_t	pid;

	while (1)
	{
		signal(SIGINT, signal_handler);
		pid = fork();
		if (pid == -1)
			return ;
		else if (pid == 0)
		{
			i = 0;
			monitor->input = display_prompt_msg();
			monitor->input_token = ft_tokenizer(monitor->input, monitor);
			monitor->nb_tokens = ft_tlen(monitor->input_token);
			printf("nb token: %d\n", monitor->nb_tokens);
			init_tokens(monitor);
		}
		else
			wait(NULL);
	}
}
