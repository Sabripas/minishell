/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:46:32 by ssteveli          #+#    #+#             */
/*   Updated: 2024/06/03 13:50:52 by iait-ouf         ###   ########.fr       */
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

// **************** BUILT-IN *********************

int		exe_token(struct s_cmd *struc);
int		exe_cd(struct s_cmd *struc);
int		exe_echo(struct s_cmd *struc);
// ----------------- ENV -----------------------
int		exe_env(struct s_cmd *struc);
void	old_pwd_update(t_cmd *struc, char *pwd);
void	pwd_update(t_cmd *struc);

int		exe_exit(struct s_cmd *struc);
// -------------- EXPORT ----------------------
int		exe_export(t_cmd *struc);

int		exe_pwd(struct s_cmd *struc);
int		exe_unset(struct s_cmd *struc);

// **************** BUILT-IN UTILS ****************

// -------- EXPORT ---------
void	export_display(t_cmd *struc);
char	**bubble_sort(t_cmd *struc);
void	ft_swap(char **a, char **b);

// -------- ENV ------------
char	**ar_dup_or_raised(t_cmd *struc, char *new_str);
char	*ft_strjoin(char *s1, char *s2);

//builtin_change
int		is_buitin(char *a);
int		(*ch_bn(t_list **ad_lexer))(struct s_cmd *struc, int flag);

//cmd
t_cmd	*get_cmds_bis(t_list *tl, t_cmd *tc, t_cmd *prev, t_list **lx);
int		get_cmds(t_list **lexer, t_cmd **cmds);

//erro_return
void	error_return(int i, char *str);

//execut
void	execut(t_cmd **cmd);

//free_all
void	ft_lstdel_cmd(t_cmd **cmd);
void	free_all(t_list **lexer, t_cmd **cmd, char **str);

//redirection
void	redirect(t_cmd *cmd);

//s_minishell
char	*rl_gets(char *text);
void	print_lexer(t_list **lexer);

//s_token
void	sup_list2(t_list **lexer, t_list *temp_lexer);
void	get_lexer(t_list **lexer, char **a);
int		get_cmds(t_list **lexer, t_cmd **cmds);

#endif
