/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_mutan.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:50:16 by ssteveli          #+#    #+#             */
/*   Updated: 2024/06/21 16:21:48 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	error_quot(void)
{
	ft_printf("error quot\n");
	return (-1);
}

int	num_count(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			if (str[i + 1] && str[i + 1] != '\'')
			{
				count++;
				i++;
				while (str[i] && str[i] != '\'')
					i++;
				if (str[i] == 0)
					return (error_quot());
			}
			else
				i += 2;
		}
		else if (str[i] == '\"')
		{
			if (str[i + 1] == '\0')
				return (error_quot());
			if (str[i + 1] != '\"')
			{
				count++;
				i++;
				while (str[i] && str[i] != '\"')
					i++;
				if (str[i] == '\0')
					return (error_quot());
				i++;
			}
			else
				i += 2;
		}
		else if (str[i] != ' ')
		{
			count++;
			while (str[i] && str[i] != ' ' && str[i] != '\'' && str[i] != '\"')
				i++;
		}
		else if (str[i] == ' ')
		{
			while (str[i] == ' ')
				i++;
		}
	}
	return (count);
}

int	len_to_sep(char *str, int i)
{
	int	count;

	count = 0;
	if (str[i] == '\'')
	{
		if (str[i] && str[i + 1] == '\'')
			return (0);
		i++;
		while (str[i] && str[i] != '\'')
		{
			count++;
			i++;
		}
		return (count);
	}
	else if (str[i] == '\"')
	{
		if (str[i] && str[i + 1] == '\"')
			return (0);
		i++;
		while (str[i] && str[i] != '\"')
		{
			count++;
			i++;
		}
		return (count);
	}
	else if (str[i] != ' ')
	{
		while (str[i] && str[i] != ' ' && str[i] != '\'' && str[i] != '\"')
		{
			count++;
			i++;
		}
		return (count);
	}
	return (0);
}

char	**ft_splite_mutan(char *str)
{
	int		count;
	int		i;
	int		j;
	int		size;
	char	**ret;

	count = num_count(str);
	if (count == -1)
		return (0);
	if (count == 0)
		return (0);
	ret = ft_calloc(sizeof(char *), count + 1);
	i = 0;
	j = 0;
	while (str[i] && j <= count)
	{
		size = 0;
		while (str[i] == ' ')
			i++;
		size = len_to_sep(str, i);
		if (size != 0)
		{
			ret[j] = ft_calloc(sizeof(char), size + 1);
			if (str[i] == '\'')
			{
				while (str[i] == '\'')
					i++;
			}
			else if (str[i] == '\"')
			{
				while (str[i] == '\"')
					i++;
			}
			ret[j] = ft_substr(str, i, size);
			j++;
		}
		else
		{
			i += 2;
			count++;
		}
		i += size;
		if (size != 0 && (str[i - size] == '\'' || str[i - size] == '\"'))
		{
			while (str[i] && str[i] != '\'' && str[i] != '\"')
				i++;
			i++;
		}
	}
	return (ret);
}
