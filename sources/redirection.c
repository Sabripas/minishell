/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:42:41 by ssteveli          #+#    #+#             */
/*   Updated: 2024/06/05 14:36:52 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void redirection_2(t_cmd *cmd)
{
	ft_printf("redirection 2\n");
}

void redirection_3(t_cmd *cmd)
{
	ft_printf("redirection 3\n");
}

void redirection_4(t_cmd *cmd)
{
	ft_printf("redirection 4\n");
}

void redirection_5(t_cmd *cmd)
{
	char *temp;
	int fd;

	fd = open("herdoc.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);	
	if (fd == 0)
		exit(0);
	temp = 0;
	while (temp == 0 || ft_strncmp(temp, cmd->redirection->str, ft_strlen(temp) + 1) != 0)
	{
		temp = rl_gets("");
		if (ft_strncmp(temp, cmd->redirection->str, ft_strlen(temp)) != 0)
			write(fd, temp, ft_strlen(temp));
	}
	close(fd);
	fd = open("herdoc.txt", O_RDONLY);
	cmd->fd_herdoc = fd;
}

void redirect(t_cmd *cmd)
{
	ft_printf("redirection %d detected\n", cmd->redirection->token);
	if (cmd->redirection->token == 2)
		redirection_2(cmd);
	if (cmd->redirection->token == 3)
		redirection_3(cmd);
	if (cmd->redirection->token == 4)
		redirection_4(cmd);
	if (cmd->redirection->token == 5)
		redirection_5(cmd);
}