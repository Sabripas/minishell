/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:55:29 by ssteveli          #+#    #+#             */
/*   Updated: 2024/04/23 16:19:55 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void exec_token(char **a, int *level, int i)
{
	// if (level[i] == 3)
	// 	level_3(a, i);
	// if (level[i] == 2)
	// 	level_2(a, i);
	if (level[i] == 1)
		level_1(a, level, i);
}

void 	pars(char **tokens, int *level)
{
	int actu_level;
	int i;

	i = -1;
	actu_level = 3;
	while(actu_level > 0)
	{
		while(level[++i])
		{
			if (actu_level == level[i])
				exec_token(tokens, level, i);
		}
		actu_level--;
		i = -1;
	}
}