/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:44:18 by ssteveli          #+#    #+#             */
/*   Updated: 2024/06/05 15:08:51 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_lstdel_cmd(t_cmd **cmd)
{
	t_cmd	*a_effacer;
	t_cmd	*prochain_maillon;
	int		i;

	i = -1;
	a_effacer = *cmd;
	while (a_effacer)
	{
		prochain_maillon = a_effacer->next;
		free(a_effacer->str);
		ft_lstdel(&(a_effacer->redirection));
		free(a_effacer);
		a_effacer = prochain_maillon;
	}
	*cmd = NULL;
}

void	free_all(t_list **lexer, t_cmd **cmd, char **str)
{
	int	i;
	int j;

	if ((*cmd)->fd_herdoc != -1)
		close((*cmd)->fd_herdoc);
	ft_lstdel(lexer);
	ft_lstdel_cmd(cmd);
	free(lexer);
	free(cmd);
	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}
