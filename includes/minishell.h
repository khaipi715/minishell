/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaulak <lnaulak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:45:26 by lnaulak           #+#    #+#             */
/*   Updated: 2024/03/01 12:07:00 by lnaulak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <term.h>
# include <curses.h>
# include <termios.h>
# include <stdint.h>
# include <sys/ioctl.h>

# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <errno.h>
# include <signal.h>
# include <dirent.h>
# include <limits.h>

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"

typedef	struct	s_data
{
	char		**env;
	int			fd_in;
	int			fd_out;
	char		*pwd;
	int			redir;
	int			i;
}				t_data;

typedef	struct	s_tokens
{
	char			*s;
	struct s_tokens	*next;
}				t_tokens;

int				ms_cd(char *path);
void			ms_echo(int argc, char *args[]);
void			ms_env(char *env[]);

char			**px_split(char *str);

char			**sep_command(char *cmd, char *envp[]);
char			**ft_tokenizer(char *s);

void			free_env(char **env);
char			**dup_env(char **env);

void			ms_echo(int argc, char *args[]);
int				ms_cd(char *path);
void			ms_pwd(void);
void			ms_env(char *env[]);

int 			ft_tokens(char *s);

#endif
