/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:09:33 by ssteveli          #+#    #+#             */
/*   Updated: 2024/04/23 16:22:06 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void level_1(char **a, int *level, int i)
{
	char *temp;

	temp = a[i];
	while(level[i] == 1 && i > 0)
		i--;
	if (i == 0)
		 ft_printf("bash: %s: command not found\n", temp);
	else 
		ft_printf("%s: %s: No such file or directory\n", a[i], temp);
}