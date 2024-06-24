/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expender.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:53:54 by ssteveli          #+#    #+#             */
/*   Updated: 2024/06/24 13:49:06 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	len_to_egal(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '=')
		i++;
	return (i);
}

char	*after_egal(char *str)
{
	int		i;
	char	*a;
	int		j;

	i = 0;
	while (str[i] != '=')
		i++;
	i++;
	a = ft_calloc(ft_strlen(str) - i + 1, sizeof(char));
	j = 0;
	while (str[i])
	{
		a[j] = str[i];
		j++;
		i++;
	}
	return (a);
}

char	**hextend(char **a, t_data *data)
{
	int		i;
	char	*str;

	str = 0;
	i = -1;
	a = hextend_bis(a, data, str, i);
	return (a);
}
