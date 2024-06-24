/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expender_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:47:08 by ssteveli          #+#    #+#             */
/*   Updated: 2024/06/24 13:49:22 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**replace_exp(char **a, char *str)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (a[++i])
	{
		if (a[i][0] == '$')
		{
			a[i] = ft_strdup(str);
		}
	}
	return (a);
}

int	multi_condi(t_data *data, int j, char *str_temp)
{
	if (ft_strchr(data->env[j], '=', ft_strlen(data->env[j])) == 1)
	{
		if (ft_strncmp(str_temp, data->env[j], len_to_egal(data->env[j])) == 0)
		{
			return (0);
		}
	}
	return (1);
}

char	**hextend_bis(char **a, t_data *data, char *str, int i)
{
	char	*str_temp;
	int		j;

	while (a[++i])
	{
		j = -1;
		if (ft_strchr(a[i], '~', 2) == 1)
			a[i] = ft_strdup(data->user);
		if (ft_strncmp(a[i], "$?", 3) == 0)
			a[i] = ft_strdup(ft_itoa(data->exit_code));
		while (data->env[++j])
		{
			str_temp = ft_substr(a[i], 1, ft_strlen(a[i]));
			if (multi_condi(data, j, str_temp) == 0)
			{
				str = after_egal(data->env[j]);
				a = replace_exp(a, str);
				free(str_temp);
				return (a);
			}
			free(str_temp);
		}
	}
	replace_exp(a, "");
	return (a);
}
