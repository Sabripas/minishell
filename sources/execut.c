/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:31:42 by ssteveli          #+#    #+#             */
/*   Updated: 2024/06/05 15:39:24 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void is_not_builtin(t_cmd *cmd)
{
	ft_printf("not buitin\n");
}

void execut_simple(t_cmd *cmd)
{
	if (cmd->redirection != 0)
		redirect(cmd);
	if(is_buitin(cmd->str[0]) == 1)
	{
		cmd->builtin(cmd);
	}
	else
		is_not_builtin(cmd);
}

void execut_pipe(t_cmd **cmd)
{
	ft_printf("it's a pipe\n");
}

void execut(t_cmd **cmd)
{
	t_cmd	*temp_cmd;

	temp_cmd = *cmd;
	if (temp_cmd->next == 0)
	{
		execut_simple(temp_cmd);
	}
	else
	{
		execut_pipe(cmd);
	}
}