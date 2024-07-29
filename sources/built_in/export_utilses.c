/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utilses.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:44:47 by ssteveli          #+#    #+#             */
/*   Updated: 2024/07/26 14:47:18 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

char	**bubble_sort(t_data *data)
{
	int		i;
	int		j;
	char	**ar_sorted;

	ar_sorted = ar_dup_or_raised(data, data->env, NULL);
	i = 0;
	while (i < data->nb_var - 2)
	{
		j = 0;
		while (j < (data->nb_var - i) - 1)
		{
			if (j == data->nb_var -2)
				break ;
			if (strcmp(ar_sorted[j], ar_sorted[j + 1]) > 0)
				ft_swap(&ar_sorted[j], &ar_sorted[j + 1]);
			j++;
		}
		i++;
	}
	return (ar_sorted);
}

void	free_char_ar(char **ar)
{
	int	i;

	i = 0;
	while (ar != NULL && ar[i])
	{
		free(ar[i]);
		ar[i] = NULL;
		i++;
	}
}

void	display_writer(char **strs, int i, int j)
{
	while (strs[i][j])
	{
		if (j && strs[i][j - 1] == '=')
			break ;
		write (1, &strs[i][j], 1);
		j++;
	}
	write(1, "\"", 1);
	while (strs[i][j])
	{
		write(1, &strs[i][j], 1);
		j++;
	}
}

void	export_display(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->env_tmp = bubble_sort(data);
	while (data->env_tmp != NULL && data->env_tmp[i])
	{
		j = 0;
		write(1, "declare -x ", 11);
		display_writer(data->env_tmp, i, j);
		write(1, "\"\n", 2);
		i++;
	}
	free_char_ar(data->env_tmp);
}
