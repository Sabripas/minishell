/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expender.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:53:54 by ssteveli          #+#    #+#             */
/*   Updated: 2024/06/18 18:50:45 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int len_to_egal(char *str)
{
	int i;

	i = 0;
	while (str[i] != '=')
		i++;
	return (i);
}

char *after_egal(char *str)
{
	int i;
	char *a;
	int j;

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

char **replace_exp(char **a, char *str)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while(a[++i])
	{
		if (a[i][0] == '$')
		{
			a[i] = ft_strdup(str);
		}
	}
	return (a);
}

char	**hextend(char **a, t_data *data)
{
	int i;
	int j;
	int k;
	char *str;
	char *str_temp;

	i = -1;
	k = 0;
	while (a[++i])
	{
		j = -1;
		if (ft_strchr((int *)a[i], '~', 2) == 1)
			a[i] = ft_strdup(data->user);
		if (ft_strncmp(a[i], "$?", 3) == 0)
			a[i] = ft_strdup(ft_itoa(data->exit_code));
		while (data->env[++j])
		{
			str_temp = ft_substr(a[i], 1, ft_strlen(a[i]));
			if (ft_strchr((int *)data->env[j], '=', ft_strlen(data->env[j])) == 1 && ft_strncmp(str_temp, data->env[j], len_to_egal(data->env[j])) == 0)
			{
				str = after_egal(data->env[j]);
				a = replace_exp(a, str);
				k = 1;
			}
			free(str_temp);
		}
	}
	if (k == 0)
		replace_exp(a, "");
	return (0);
}
