/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:25:00 by ssteveli          #+#    #+#             */
/*   Updated: 2024/04/23 16:03:19 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	not_buil_in_cmd(char *a)
{
	return (1);
}

int	find_level(char *a)
{
	size_t	len;

	len = ft_strlen(a);
	if (strncmp(a, ">>", len) == 0 || strncmp(a, ">", len) == 0 || strncmp(a,
			"<<", len) == 0 || strncmp(a, "<", len) == 0 || strncmp(a, "|",
			len) == 0)
		return (3);
	if (ft_strncmp(a, "echo", ft_strlen(a)) == 0)
		return (2);
	if (ft_strncmp(a, "cd", ft_strlen(a)) == 0)
		return (2);
	if (ft_strncmp(a, "pwd", ft_strlen(a)) == 0)
		return (2);
	if (ft_strncmp(a, "export", ft_strlen(a)) == 0)
		return (2);
	if (ft_strncmp(a, "unset", ft_strlen(a)) == 0)
		return (2);
	if (ft_strncmp(a, "env", ft_strlen(a)) == 0)
		return (2);
	if (ft_strncmp(a, "exit", ft_strlen(a)) == 0)
		return (2);
	if (not_buil_in_cmd(a) == 0)
		return (2);
	else
		return (1);
}

int	*get_atom_level(char **tokens)
{
	int *level;
	int i;

	i = -1;
	level = ft_calloc(number_token(tokens) + 1, sizeof(int));
	while (tokens[++i])
	{
		level[i] = find_level(tokens[i]);
	}
	return (level);
}