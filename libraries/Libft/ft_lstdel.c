/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 09:24:38 by ggane             #+#    #+#             */
/*   Updated: 2024/04/26 22:18:00 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, int))
{
	t_list	*a_effacer;
	t_list	*prochain_maillon;

	a_effacer = *alst;
	while (a_effacer)
	{
		prochain_maillon = a_effacer->next;
		del(a_effacer->i, sizeof(int));
		del(a_effacer->str, ft_strlen(a_effacer->str));
		del(a_effacer->token, sizeof(int));
		free(a_effacer);
		a_effacer = prochain_maillon;
	}
	*alst = NULL;
}
