/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaturzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:21:58 by npaturzo          #+#    #+#             */
/*   Updated: 2024/01/16 12:46:30 by npaturzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../lib/ft_printf/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include <fcntl.h>
# include <sys/wait.h>

char	**px_split(char *str);
char	**sep_command(char *cmd, char *envp[]);

#endif
