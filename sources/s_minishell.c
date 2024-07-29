/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:46:03 by ssteveli          #+#    #+#             */
/*   Updated: 2024/06/18 14:21:46 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*rl_gets(char *text)
{
	static char	*line_read;

	line_read = (char *) NULL;
	if (line_read)
	{
		free(line_read);
		line_read = (char *) NULL;
	}
	line_read = readline(text);
	if (line_read && *line_read)
		add_history(line_read);
	return (line_read);
}

int	main(int argc, char **argv, char **envp)
{
	t_list	**lexer;
	t_cmd	**cmd;
	t_data	*data;
	char	**str;

	(void)argc;
	(void)argv;
	init_minishell(&data, &cmd, envp);
	str = 0;
	while (1)
	{
		lexer = ft_calloc(1, sizeof(t_list));
		if (launch_mini(str, data, cmd, lexer) == 0)
		{
			ft_printf("\b\bexit");
			free_all(lexer, cmd, str);
			exit (0);
		}
	}
	free_all(lexer, cmd, str);
	return (0);
	system("leaks minishell.c");
}
