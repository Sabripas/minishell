/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:26:29 by ssteveli          #+#    #+#             */
/*   Updated: 2023/10/24 13:39:54 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cmd	*ft_lstnew_2(char **str, int (*builtin)(struct s_cmd *), int num_redirections, char *hd_file_name, t_list *redirection, t_cmd *prev)
{
	t_cmd	*list;

	list = malloc(sizeof(t_cmd));
	if (!list)
		return (0);
	list->str = str;
	list->builtin = builtin;
	list->num_redirection = num_redirections;
	list->hd_files_name = hd_file_name;
	list->redirection = redirection;
	list->prev = prev;
	list->next = 0;
	return (list);
}
