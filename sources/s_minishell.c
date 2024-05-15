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

void print_lexer(t_list **lexer)
{
	t_list *temp;
	int i;

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

void print_cmd(t_cmd **cmd)
{
	t_cmd *temp;
	int i;
	int j;

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

void ft_lstdel_cmd(t_cmd **cmd)
{
	t_cmd	*a_effacer;
	t_cmd	*prochain_maillon;
	int i;

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

void free_all(t_list **lexer, t_cmd **cmd, char **str)
{
	int i;

	ft_lstdel(lexer);
	ft_lstdel_cmd(cmd);
	free(lexer);
	free(cmd);
	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

int	main(int ac, char **av)
{
	t_list **lexer;
	t_cmd **cmd;
	char **str;
	int i;
	t_cmd	*temp_cmd;

	lexer = ft_calloc(1, sizeof(t_list));
	cmd = ft_calloc(1, sizeof(t_cmd));
	// while (1)
	// {
	// 	get_lexer(lexer, rl_gets("minishell : "));
	// }
	str = ft_split("cd f > rt| cd a << edf", ' ');
	// if(ac == 1)
	// 	return (1);
	get_lexer(lexer, str);
	//print_lexer(lexer);
	if (get_cmds(lexer, cmd) == 1)
		return (1);
	print_cmd(cmd);
	free_all(lexer, cmd, str);
	return (0);
	system("leaks minishell.c");
}