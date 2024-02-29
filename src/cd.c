/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaturzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:55:35 by npaturzo          #+#    #+#             */
/*   Updated: 2024/02/20 14:01:05 by npaturzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//could just use chdir

int	ms_cd(char *path)
{
	int	ret;

	ret = chdir(path);
	return (ret);
}

//main for testing
/*
int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);
	ms_cd(argv[1]);
}
*/
