/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_cpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:32:16 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/04/28 11:11:12 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strdup_cro(const char *src, int sign)
{
	int			i;
	int			g;
	char		*new;

	i = 0;
	g = 0;
	if (!src)
		return (NULL);
	new = malloc(sizeof(char) * ft_strlen(src) + 1);
	while (src[i])
	{
		if (src[i] == '"')
			i++;
		if (sign == 1 && src[i] == '+' && src[i + 1] == '=')
			i++;
		new[g] = src[i];
		i++;
		g++;
	}
	new[i] = '\0';
	return (new);
}

char	**add_to_env(char **env, char *to_add, int i)
{
	char	**new_env;
	int		k;

	k = 0;
	new_env = malloc(sizeof(char *) * (i + 2));
	while (env[k])
	{
		new_env[k] = ft_strdup(env[k]);
		k++;
	}
	new_env[i] = ft_strdup(to_add);
	new_env[i + 1] = NULL;
	i = 0;
	while (env[i])
	{
		free(env[i]);
		i++;
	}
	free(env);
	return (new_env);
}

char	**ft_cpy_tab(t_bloc *bloc)
{
	int		i;
	char	**env;

	i = 0;
	env = malloc(sizeof (char *) * (ft_nb_lines_env(bloc->tab_env) + 1));
	while (bloc->tab_env[i])
	{
		env[i] = ft_strdup_equal(bloc->tab_env[i]);
		i++;
	}
	env[i] = NULL;
	return (env);
}

char	**ft_sorting_alph(char **env)
{
	int	i;

	while (ft_sorted(env) == -1)
	{
		i = 0;
		while (env[i] && env[i + 1])
		{
			if (ft_strcmp(env[i], env[i + 1]) > 0)
				ft_swap(&env[i], &env[i + 1]);
			i++;
		}
	}
	return (env);
}
