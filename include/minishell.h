/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:46:32 by ssteveli          #+#    #+#             */
/*   Updated: 2024/04/23 16:18:51 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libraries/Libft/libft.h"
// # include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <dirent.h>
// # include <sys/wait.h>
# include <limits.h>
# include <errno.h>
# include <signal.h>

//buil in
int	exe_token(struct s_cmd *);
int	exe_cd(struct s_cmd *);
int	exe_echo(struct s_cmd *);
int exe_env(struct s_cmd *);
int exe_exit(struct s_cmd *);
int exe_export(struct s_cmd *);
int exe_pwd(struct s_cmd *);
int exe_unset(struct s_cmd *);

//builtin_change
int is_buitin(char *a);
int (*changebuiltin(t_list **ad_lexer))(struct s_cmd *);

//s_minishell
void print_lexer(t_list **lexer);

//s_token
void sup_list(t_list **lexer, t_list *temp_lexer);
void	get_lexer(t_list **lexer, char **a);
int		get_cmds(t_list **lexer, t_cmd **cmds);
#endif