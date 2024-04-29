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
            prev = ft_lstnew(Not_a_token, a[i], i, prev);
            ft_lstadd_back(lexer, prev);
    }
}