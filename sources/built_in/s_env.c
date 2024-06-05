/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:32:12 by ssteveli          #+#    #+#             */
/*   Updated: 2024/06/03 13:47:52 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*int	exe_env(struct s_cmd *struc)
{
	ft_printf("exe env\n");
	return (0);
}*/

// ATTENTION AU SHELL LVL : commence tjrs a 2 il va falloir le atoi pour le mettre en int selon le level dans lequel on se situe pour le itoa ou alors el print en int et l'ajouter a la chaine de caractere de shell lvl , et l'incrementer comme valeur en int dans la struc principale

void	init_env(t_cmd *struc, char **env)
{
	int	i;

	i = 0;
	struc->nb_var = 35;
	struc->env = (char **)malloc(struc->nb_var * sizeof(char *));
	if (!struc->env)
		exit(EXIT_FAILURE); // ECRIRE MSG ERREUR STRERROR ??
	while (i < struc->nb_var - 1 && env[i])
	{
		if (ft_strncmp("OLDPWD=", env[i], 7) == 0)
		{
			struc->env[i] = ft_strdup("OLDPWD");
			i++;
		}
		struc->env[i] = ft_strdup(env[i]);
		i++;
	}
	struc->env[i] = NULL;
}

// MAIS EN FAIT PAS BESOIN POUR VAR SUPP juste besoin d'update mon tab pas besoin de re malloc
// que faire si je unset PWD puis je export PWD avec une autre valeur qui n'existe pas trouver un moyen de ne pas
// l'update
// mais s'update tout de meme automatiquement si cd fait et OLDPWD prend la valeur qui a ete entre avec export
// ex : unset PWD export PWD=yoyo
// declare -x OLDPWD
// declare -x PAGER="less"
// declare -x PATH="/Users/iait-ouf/.brew/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki"
// declare -x PWD="yoyo"
// puis cd ..
// declare -x OLDPWD="yoyo"
// declare -x PAGER="less"
// declare -x PATH="/Users/iait-ouf/.brew/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki"
// declare -x PWD="/Users/iait-ouf/Desktop"

void	old_pwd_update(t_cmd *struc, char *pwd)
{
	int	i;

	i = 0;
	while (struc->env[i])
	{
		if (ft_strncmp("OLDPWD", struc->env[i], 6) == 0)
		{
			free(struc->env[i]);
			struc->env[i] = NULL;
			struc->env[i] = ft_strjoin("OLD", pwd);
		}
		i++;
	}
}

void	pwd_update(t_cmd *struc)
{
	int	i;

	i = 0;
	while (struc->env[i])
	{
		if (ft_strncmp("PWD=", struc->env[i], 4) == 0)
		{
			old_pwd_update(struc, struc->env[i]);
			free(struc->env[i]);
			struc->env[i] = NULL;
			struc->env[i] = ft_strjoin("PWD=", getcwd(struc->buf, 100));
		}
		i++;
	}
}

int	exe_env(t_cmd *struc)
{
	int	i;

	i = 0;
	while (struc->env[i] && ft_strchr(struc->env[i], '=', ft_strlen(struc->env[i])) != 0)
	{
		printf("%s\n", struc->env[i]);
		i++;
	}
	printf("_=/usr/bin/env\n");
	return (0);
	// else return (127) ou (126) ou (1 a 125) ??
}
