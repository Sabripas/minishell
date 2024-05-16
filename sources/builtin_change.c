/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_change.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:34:59 by ssteveli          #+#    #+#             */
/*   Updated: 2024/05/07 18:34:59 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	is_exist_cmd(char *a)
{
	return (1);
}

int	is_buitin(char *a)
{
	if (a == 0)
		return (0);
	if (ft_strncmp(a, "cd", 1) == 0)
		return (1);
	else if (ft_strncmp(a, "echo", 1) == 0)
		return (1);
	else if (ft_strncmp(a, "env", 1) == 0)
		return (1);
	else if (ft_strncmp(a, "exit", 2) == 0)
		return (1);
	else if (ft_strncmp(a, "export", 2) == 0)
		return (1);
	else if (ft_strncmp(a, "pwd", 2) == 0)
		return (1);
	else if (ft_strncmp(a, "unset", 2) == 0)
		return (1);
	else
		return (0);
}

int	(*ch_bn(t_list **ad_lexer))(struct s_cmd *struc)
{
	t_list	*lexer;

	lexer = *ad_lexer;
	while (lexer && lexer->token != Pipe)
	{
		if (ft_strncmp(lexer->str, "cd", 1) == 0)
			return (&(exe_cd));
		else if (ft_strncmp(lexer->str, "echo", 1) == 0)
			return (&(exe_echo));
		else if (ft_strncmp(lexer->str, "env", 1) == 0)
			return (&(exe_env));
		else if (ft_strncmp(lexer->str, "exit", 2) == 0)
			return (&(exe_exit));
		else if (ft_strncmp(lexer->str, "export", 2) == 0)
			return (&(exe_export));
		else if (ft_strncmp(lexer->str, "pwd", 2) == 0)
			return (&(exe_pwd));
		else if (ft_strncmp(lexer->str, "unset", 2) == 0)
			return (&(exe_unset));
		else if (is_exist_cmd(lexer->str) == 1)
			error_return(1, lexer->str);
		else
			return (0);
	}
	return (0);
}
