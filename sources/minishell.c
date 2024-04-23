/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:46:03 by ssteveli          #+#    #+#             */
/*   Updated: 2024/04/23 15:55:23 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void print_token(char **a)
{
	int i;

	i = -1;
	while (a[++i])
	{
		ft_printf("token %d = %s\n", i , a[i]);
	}
}

void	print_level(int *a)
{
	int i;

	i = -1;
	while (a[++i])
	{
		ft_printf("level %d = %d\n", i , a[i]);
	}
}

char	*rl_gets(char *text)
{
	static char	*line_read;

	line_read = (char *) NULL;
	if (line_read)
	{
		free(line_read);
		line_read = (char *)NULL;
	}
	line_read = readline(text);
	if (line_read && *line_read)
		add_history(line_read);
	return (line_read);
}

int	main(void)
{
	char **tokens;
	int *level;

	while (1)
	{
		tokens = get_token(rl_gets("minishell : "));
		level = get_atom_level(tokens);
		pars(tokens, level);
	}
	return (0);
	system("leaks minishell.c");
}