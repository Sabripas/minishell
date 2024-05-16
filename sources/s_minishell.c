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

void	print_lexer(t_list **lexer)
{
	t_list	*temp;
	int		i;

	if (*lexer == 0)
		return ;
	i = -1;
	temp = *lexer;
	while (temp)
	{
		ft_printf("node %d;\n", temp->i);
		ft_printf("str = %s\n", temp->str);
		ft_printf("token = %d\n\n", temp->token);
		temp = temp->next;
	}
	ft_printf("---------------\n");
}

void	print_cmd(t_cmd **cmd)
{
	t_cmd	*temp;
	int		i;
	int		j;

	i = -1;
	temp = *cmd;
	while (temp)
	{
		ft_printf("\nCmd 1\n");
		j = -1;
		ft_printf("str = ");
		while (temp->str[++j])
		{
			ft_printf("%s ", temp->str[j]);
		}
		ft_printf("\n");
		temp->builtin(*cmd);
		print_lexer(&(temp->redirection));
		temp = temp->next;
	}
}

int	main(void)
{
	t_list	**lexer;
	t_cmd	**cmd;
	char	**str;

	while (1)
	{
		str = ft_split(rl_gets("minishell : "), ' ');
		lexer = ft_calloc(1, sizeof(t_list));
		cmd = ft_calloc(1, sizeof(t_cmd));
		get_lexer(lexer, str);
		if (get_cmds(lexer, cmd) == 1)
			return (1);
		print_cmd(cmd);
		free_all(lexer, cmd, str);
	}
	return (0);
	system("leaks minishell.c");
}
