/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaulak <lnaulak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:52:41 by lnaulak           #+#    #+#             */
/*   Updated: 2024/03/12 18:39:24 by lnaulak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	init_all(int ac, char **av, char **envp, t_monitor *monitor)
{
	(void) ac;
	(void) av;
	monitor->envp = envp;
	monitor->nb_tokens = 0;
	monitor->start = 0;
	monitor->end = 0;
	monitor->has_redirect = false;
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	t_monitor		monitor;

	if (init_all(ac, av, envp, &monitor) == 0)
		engine(&monitor);
	else
		return (1);
	return (0);
}
