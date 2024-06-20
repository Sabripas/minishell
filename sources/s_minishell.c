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

void	print_cmd(t_cmd **cmd, t_data *data)
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
		ft_printf(" multi pipe str = ");
		while (temp->str[++j])
		{
			ft_printf("%s ", temp->str[j]);
		}
		ft_printf("\n");
		if (temp->builtin)
			temp->builtin(data);
		if (temp->redirection)
			print_lexer(&(temp->redirection));
		temp = temp->next;
	}
}

void	sigint_handler(int flags)
{
	ft_printf("\b\b  ");
	ft_printf("\nminishell :  ");
}

void	sigquit_handler(int flags)
{
	ft_printf("\b\b  \b\b");
}

int	main(int argc, char **argv, char **envp)
{
	t_list	**lexer;
	t_cmd	**cmd;
	t_data	*data;
	char	**str;
	(void)	argc;
	(void)	argv;
	int i;

	lexer = ft_calloc(1, sizeof(t_list));
	cmd = ft_calloc(1, sizeof(t_cmd));
	data = init_env(data, envp, cmd);
	// signal(SIGINT, SIG_IGN);
	// signal(SIGINT, sigint_handler);
	// signal(SIGQUIT, SIG_IGN);
	// signal(SIGQUIT, sigquit_handler);
	while (1)
	{
		i = -1;
		str = ft_splite_mutan(rl_gets("minishell :  "));
		if (str != 0)
		{
			hextend(str, data);
			get_lexer(lexer, str);
			//print_lexer(lexer);
			if (get_cmds(lexer, cmd) == 1)
			{
				free_all(lexer, cmd, str);
				return (1);
			}
			if ((*cmd)->redirection && (*cmd)->redirection->token == 6)
			{
				ft_printf("error redirection cant open file");
				return (0);
			}
			print_cmd(cmd, data);
			(*cmd)->fd_herdoc = -1;
			execut(cmd, data);
		}
		else
		{
			ft_printf("\b\bexit");
			free_all(lexer, cmd, str);
			exit (0);
		}
		while ((*cmd) && (*cmd)->str[++i])
			(*cmd)->str[i] = NULL;
	}
	free_all(lexer, cmd, str);
	return (0);
	//system("leaks minishell.c");
}
