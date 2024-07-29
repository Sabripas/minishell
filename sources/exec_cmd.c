/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 09:56:18 by iait-ouf          #+#    #+#             */
/*   Updated: 2024/07/29 14:30:55 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	minishell_case(t_data *data, t_cmd *cmds)
{
	char	*pwd;

	if (ft_strncmp((*data->cmd)->str[0], "./", 2) == 0)
	{
		pwd = ft_strnjoin(getcwd(data->buf, 100),
				ft_substr((*data->cmd)->str[0],
					1, ft_strlen((*data->cmd)->str[0])));
		execve(pwd, cmds->str, data->env);
	}
	else if (ft_strncmp((*data->cmd)->str[0], "minishell", 9) == 0)
	{
		pwd = ft_strnjoin(getcwd(data->buf, 100),
				ft_strnjoin("/", (*data->cmd)->str[0]));
		execve(pwd, cmds->str, data->env);
	}
}

void	sign_quit(int code)
{
	char	*str;

	str = ft_itoa(code);
	write(2, "Quit: ", 6);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
}

int	find_cmd(t_data *data, t_cmd *cmds)
{
	char	*cmd;
	int		i;

	i = 0;
	while (data->paths[i])
	{
		cmd = ft_strnjoin(data->paths[i], cmds->str[0]);
		if (access(cmd, F_OK) == 0 && access(cmd, X_OK) == 0)
			execve(cmd, cmds->str, data->env);
		else if (ft_strncmp((*data->cmd)->str[0], "./", 2) == 0)
			minishell_case(data, cmds);
		else if (ft_strncmp((*data->cmd)->str[0], "minishell", 9) == 0)
			minishell_case(data, cmds);
		i++;
	}
	return (0);
}

void	redirection_check(t_data *data, t_cmd *cmds)
{
	if (cmds->redirection->token == TRUNC
		|| cmds->redirection->token == APPEND)
		outfile_redirection(data, cmds);
	if (cmds->redirection->token == INPUT
		|| cmds->redirection->token == HEREDOC)
		infile_redirection(data, cmds);
}

int	one_command(t_data *data)
{
	t_cmd	*cmds;
	int		status;

	cmds = (*data->cmd);
	signal(SIGQUIT, &sign_quit);
	g_glob.in_heredoc = 1;
	data->pid = fork();
	if (data->pid == 0)
	{
		if (cmds->redirection)
			redirection_check(data, cmds);
		find_cmd(data, cmds);
		ft_printf("%s: minishell: command not found\n", (*data->cmd)->str[0]);
		exit(127);
	}
	else
	{
		waitpid(data->pid, &status, 0);
		data->exit_code = WEXITSTATUS(status);
	}
	signal(SIGQUIT, SIG_IGN);
	g_glob.in_heredoc = 0;
	return (0);
}
