/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_cpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:32:16 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/04/28 23:22:52 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_env(char **env)
{
	int	i;

	i = 0;
	while (env && env[i])
	{
		free(env[i]);
		i++;
	}
	free(env);
}

char	**add_to_env(char **env, char *to_add)
{
	char	**new_env;
	int		k;
	int		size;

	if (!env)
		return (NULL);
	size = ft_nb_lines_env(env);
	new_env = malloc(sizeof(char *) * (size + 2));
	k = 0;
	while (env[k])
	{
		new_env[k] = ft_strdup(env[k]);
		k++;
	}
	new_env[k] = ft_strdup(to_add);
	new_env[k + 1] = NULL;
	free_env(env);
	return (new_env);
}

char	**ft_cpy_tab(char **env)
{
	int		i;
	char	**dest;

	i = 0;
	dest = malloc(sizeof (char *) * (ft_nb_lines_env(env) + 1));
	while (env[i])
	{
		dest[i] = ft_strdup(env[i]);
		i++;
	}
	dest[i] = NULL;
	return (dest);
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
