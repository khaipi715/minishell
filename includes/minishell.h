/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaulak <lnaulak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:45:26 by lnaulak           #+#    #+#             */
/*   Updated: 2024/03/12 15:07:36 by lnaulak          ###   ########.fr       */
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

struct	s_monitor;

typedef struct s_tokens
{
	char				**argv;
	int					id;
	struct s_monitor	*monitor;
}						t_tokens;

typedef struct s_monitor
{
	char				*input;
	char				**envp;
	char				**input_token;
	int					nb_tokens;
	int					token_update;
	int					start;
	int					end;
	int					sub_token;
//philo stuff
	bool				has_redirect;
	t_tokens			*tokens;
}						t_monitor;


//built in
void			ms_echo(int argc, char *args[]);
int				ms_cd(char *path);
void			ms_pwd(void);
void			ms_env(char *env[]);
char			**px_split(char *str);
void			free_env(char **env);
char			**dup_env(char **env);
char			**sep_command(char *cmd, char *envp[]);

//
char			**ft_tokenizer(char *s, t_monitor *monitor);
char			*ft_mal(char *s, int start, int end);
int 			ft_tokens(char *s);
void			engine(t_monitor *monitor);
void			init_tokens(t_monitor *monitor);

//utils
int				write_error(char *str);
int				ft_isspace(char c);
int				ft_isredirect(char c);
char			*display_prompt_msg(void);
int				ft_tlen(char **s);

#endif
