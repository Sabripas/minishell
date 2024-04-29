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

// char	*rl_gets(char *text)
// {
// 	static char	*line_read;

// 	line_read = (char *) NULL;
// 	if (line_read)
// 	{
// 		free(line_read);
// 		line_read = (char *)NULL;
// 	}
// 	line_read = readline(text);
// 	if (line_read && *line_read)
// 		add_history(line_read);
// 	return (line_read);
// }

int	main(int ac, char **av)
{
	t_list **lexer;
	char **str;

	// while (1)
	// {
	// 	get_lexer(lexer, rl_gets("minishell : "));
	// }
	str = ft_split(av[1], ' ');
	if(ac = 1)
		return (0);
	get_lexer(lexer, str);
	return (0);
	system("leaks minishell.c");
}