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
# include <libc.h>
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

//tokens.c
char	**get_token(char *a);

//buil in
int		exe_token(char **a);
void	exe_cd(char **a);
void	exe_echo(char **a);
void	exe_env(char **a);
void	exe_exit(char **a);
void	exe_export(char **a);
void	exe_pwd(char **a);
void	exe_unset(char **a);

//atom.c
int		*get_atom_level(char **tokens);

//utilises.c
int		number_token(char **tokens);

//pars.c
void 	pars(char **tokens, int *level);

//level.c
void level_1(char **a, int *level, int i);

#endif