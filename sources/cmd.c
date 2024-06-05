/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:34:27 by ssteveli          #+#    #+#             */
/*   Updated: 2024/06/03 15:59:11 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"	

t_list	*is_token_bis(t_list **lr, t_list	*tp, t_list *pv, t_list *ll)
{
	while (ll && ll->token != Pipe)
	{
		if (ll->token != Not_a_token)
		{
			if (ll->next == 0)
			{
				ft_printf("redirection error\n");
				exit(0);
			}
			if (pv == 0)
			{
				pv = ft_lstnew(ll->token, ll->next->str, 0, 0);
				tp = pv;
			}
			else
			{
				pv = ft_lstnew(ll->token, ll->next->str, 0, pv);
				ft_lstadd_back(&tp, pv);
			}
			sup_list2(lr, ll);
		}
		ll = ll->next;
	}
	return (tp);
}

t_list	*is_t(t_list **lexer)
{
	t_list	*temp;
	t_list	*prev_red;
	t_list	*temp_lexer;

	prev_red = 0;
	temp_lexer = *lexer;
	temp = 0;
	return (is_token_bis(lexer, temp, prev_red, temp_lexer));
}

char	**is_s(t_list **lexer, t_cmd **cmds)
{
	int		i;
	char	**str;
	t_list	*temp;
	t_list	*temp_lexer;

	i = 0;
	temp_lexer = *lexer;
	temp = temp_lexer;
	while (temp && temp->token != Pipe)
	{
		i++;
		temp = temp->next;
	}
	temp = temp_lexer;
	str = ft_calloc(i + 1, sizeof(char *));
	i = -1;
	while (temp && temp->token != Pipe)
	{
		str[++i] = temp->str;
		temp = temp->next;
	}
	return (str);
}

t_cmd	*get_cmds_bis(t_list *tl, t_cmd *tc, t_cmd *prev, t_list **lx)
{
	int	i;

	i = 0;
	while (tl)
	{
		if (prev == 0)
		{
			tc = new_2(ch_bn(lx), is_t(lx), is_s(lx, &tc), 0);
			prev = tc;
		}
		else
		{
			prev = new_2(ch_bn(lx), is_t(lx), is_s(lx, &tc), prev);
			ft_lstadd_back2(&tc, prev);
		}
		while (tl && tl->token != Pipe)
		{
			tl = tl->next;
		}
		if (tl && tl->token == Pipe)
			tl = tl->next;
		i++;
		lx = &(tl);
	}
	return (tc);
}

int	get_cmds(t_list **lexer, t_cmd **cmds)
{
	t_list	*temp_lexer;
	t_cmd	*temp_cmds;
	t_cmd	*prev;
	t_list	**add_lexer;

	add_lexer = lexer;
	temp_lexer = *lexer;
	temp_cmds = *cmds;
	prev = 0;
	temp_cmds = get_cmds_bis(temp_lexer, temp_cmds, prev, lexer);
	*cmds = temp_cmds;
	lexer = add_lexer;
	return (0);
}
