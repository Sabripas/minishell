/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-ouf <aitouflih.iman@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:27:48 by iait-ouf          #+#    #+#             */
/*   Updated: 2024/06/03 13:51:53 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**ar_dup_or_raised(t_cmd *struc, char *new_str)
{
	int		i;
	char	**new_ar;

	i = 0;
	new_ar = (char **) malloc (struc->nb_var * sizeof(char *));
	if (!new_ar)
		exit(1); // ET FREE EN CONSEQUENCES -> data->env[i] toutes les str
	while (i < struc->nb_var - 1 && struc->env[i])
	{
		new_ar[i] = ft_strdup(struc->env[i]);
		i++;
	}
	new_ar[i] = ft_strdup(new_str);
	i++;
	new_ar[i] = NULL;
	if (new_str != NULL)
		struc->nb_var++;
	return (new_ar);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (str == NULL)
		return (NULL); // ET FREE EN CONSEQUENCES -> data->env toutes les strings
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	// FREE S2 ???? car obtenu par getcwd qui malloc direct mais dans un buf ??
	return (str);
}
