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
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/wait.h>
# include <limits.h>
# include <errno.h>
# include <signal.h>

//buil in
int		exe_token(struct s_cmd *struc);
int		exe_cd(struct s_cmd *struc);
int		exe_echo(struct s_cmd *struc);
int		exe_env(struct s_cmd *struc);
int		exe_exit(struct s_cmd *struc);
int		exe_export(struct s_cmd *struc);
int		exe_pwd(struct s_cmd *struc);
int		exe_unset(struct s_cmd *struc);

//builtin_change
int		is_buitin(char *a);
int		(*ch_bn(t_list **ad_lexer))(struct s_cmd *struc);

//cmd
t_cmd	*get_cmds_bis(t_list *tl, t_cmd *tc, t_cmd *prev, t_list **lx);
int		get_cmds(t_list **lexer, t_cmd **cmds);

//erro_return
void	error_return(int i, char *str);

//free_all
void	ft_lstdel_cmd(t_cmd **cmd);
void	free_all(t_list **lexer, t_cmd **cmd, char **str);

//s_minishell
void	print_lexer(t_list **lexer);

//s_token
void	sup_list2(t_list **lexer, t_list *temp_lexer);
void	get_lexer(t_list **lexer, char **a);
int		get_cmds(t_list **lexer, t_cmd **cmds);

#endif