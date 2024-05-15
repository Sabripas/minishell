/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:47:07 by ssteveli          #+#    #+#             */
/*   Updated: 2024/04/24 16:47:07 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void sup_list(t_list **lexer, t_list *temp_lexer)
{
	if (temp_lexer->prev && temp_lexer->prev->token == Pipe)
		temp_lexer->prev->next = temp_lexer->next;
	temp_lexer = *lexer;
	*lexer = temp_lexer->next;
	temp_lexer->next->prev = 0;
	free(temp_lexer);
}
		

void sup_list2(t_list **lexer, t_list *temp_lexer)
{
	if (temp_lexer->prev != 0 && temp_lexer->next->next != 0)
	{
		temp_lexer->prev->next = temp_lexer->next->next;
		temp_lexer->next->next->prev = temp_lexer->prev;
		free(temp_lexer->next);
		temp_lexer->next = temp_lexer->next->next;
	}
	else if(temp_lexer->next->next == 0)
	{
		temp_lexer->prev->next = 0;
		free(temp_lexer->next);
		temp_lexer->next = 0;
	}
	else 
	{
		*lexer = temp_lexer->next->next;
		temp_lexer->next->next->prev = 0; 
		free(temp_lexer->next);
	}
	free(temp_lexer);
}

t_list *is_token(t_list **lexer)
{
	t_list	*temp;
	t_list 	*prev_red;
	t_list	*temp_lexer;

	prev_red = 0;
	temp_lexer = *lexer;
	temp = 0;
	while (temp_lexer && temp_lexer->token != Pipe)
	{
		if(temp_lexer->token != Not_a_token)
		{
			if(prev_red == 0)
			{
				prev_red = ft_lstnew(temp_lexer->token, temp_lexer->next->str, 0, 0);
				temp = prev_red;
			}
			else
			{
				prev_red = ft_lstnew(temp_lexer->token, temp_lexer->next->str, 0, prev_red);
				ft_lstadd_back(&temp, prev_red);
			}
			sup_list2(lexer, temp_lexer);
		}
		temp_lexer = temp_lexer->next;
	}
	return (temp);
}

char	**its_str(t_list **lexer, t_cmd **cmds)
{
	int		i;
	int		j;
	char	**str;
	t_list	*temp;
	t_cmd	*temp_cmds;
	t_list	*temp_lexer;

	temp_cmds = *cmds;
	i = 0;

	temp_lexer = *lexer;
	temp = temp_lexer;
	while(temp && temp->token != Pipe)
	{
		i++;
		temp = temp->next;
	}
	temp = temp_lexer;
	str = ft_calloc(i + 1, sizeof(char *));
	j = i;
	i = -1;
	while(temp && temp->token != Pipe)
	{
		str[++i] = temp->str;
		temp = temp->next;
	}
	return (str);
}

int get_cmds(t_list **lexer, t_cmd **cmds)
{
	t_list  *temp_lexer;
	t_list  *redirection;
	t_cmd   *temp_cmds;
	t_cmd   *prev;
	t_list	**add_lexer;
	int		i;
	int			(*builtin)(struct s_cmd *);
	char **str;

	add_lexer = lexer;
	temp_lexer = *lexer;
	temp_cmds = *cmds;
	prev = 0;
	i = 0;
	while(temp_lexer)
	{
		builtin = changebuiltin(lexer);
		redirection = is_token(lexer);
		str = its_str(lexer, &temp_cmds);
		ft_printf("%s\n", str[0]);
		if (prev == 0)
		{
			temp_cmds = ft_lstnew_2(str, builtin, i, 0, redirection, 0);
			prev = temp_cmds;
		}
		else 
		{ 
			prev = ft_lstnew_2(str, builtin, i, 0, redirection, prev);
			ft_lstadd_back2(&temp_cmds, prev);
		}
		while (temp_lexer && temp_lexer->token != Pipe)
		{
			temp_lexer = temp_lexer->next;
		}
		if (temp_lexer && temp_lexer->token == Pipe)
			temp_lexer = temp_lexer->next;
		i++;
		lexer = &(temp_lexer);
	}
	*cmds = temp_cmds;
	lexer = add_lexer;
	return (0);
}

void    get_lexer(t_list **lexer, char **a)
{
	int i;
	t_list *prev;

	i = -1;
	while(a[++i])
	{
		if (ft_strncmp(a[i], "|", 1)== 0)
		{
			prev = ft_lstnew(Pipe, 0, i, prev);
			ft_lstadd_back(lexer, prev);
		}
		else if (ft_strncmp(a[i], "<", 1) == 0)
		{
			prev = ft_lstnew(Lower, 0, i, prev);
			ft_lstadd_back(lexer, prev);
		}
		else if (ft_strncmp(a[i], ">", 1) == 0)
		{
			prev = ft_lstnew(Greater, 0, i, prev);
			ft_lstadd_back(lexer, prev);
		}
		else if (ft_strncmp(a[i], ">>", 2) == 0)
		{
			prev = ft_lstnew(D_Greater, 0, i, prev);
			ft_lstadd_back(lexer, prev);
		}
		else if (ft_strncmp(a[i], "<<", 2)== 0)
		{
			prev = ft_lstnew(D_Lower, 0, i, prev);
			ft_lstadd_back(lexer, prev);
		}
		else
		{
			prev = ft_lstnew(Not_a_token, a[i], i, prev);
			ft_lstadd_back(lexer, prev);
		}
	}
}