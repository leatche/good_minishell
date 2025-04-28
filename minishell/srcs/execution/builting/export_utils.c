/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:12:28 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/04/28 23:30:01 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_sorted(char **env)
{
	int	i;

	i = 0;
	while (env[i] && env[i + 1])
	{
		if (ft_strcmp(env[i], env[i + 1]) > 0)
			return (-1);
		i++;
	}
	return (1);
}

char	**ft_sorting_env(char **env)
{
	int		i;
	char	*tmp;

	i = 0;
	env = ft_sorting_alph(env);
	while (env[i])
	{
		tmp = env[i];
		env[i] = ft_strjoin("declare -x ", tmp);
		free(tmp);
		i++;
	}
	return (env);
}

char	*ft_pars_add(char *av)
{
	int		i;
	char	*new;

	i = 0;
	if (!av)
		return (NULL); // strdup("") ?
	new = malloc(sizeof(char ) * (ft_strlen(av) + 1)); // too much
	while (av[i]) // strndup(av, 0, len_to_+_or_-)
	{
		new[i] = av[i];
		if (av[i + 1] && av[i + 2]
			&& ((av[i + 1] == '+' && av[i + 2] == '=') || av[i + 1] == '='))
		{
			new[i + 1] = '\0';
			return (new);
		}
		i++;
	}
	free (new);
	return (ft_strdup(av));
}

int	ft_search(char **env, char *var)
{
	int	i;
	int	k;

	i = 0;
	while (env && env[i])
	{
		k = 0;
		while (var[k] && env[i][k] && env[i][k] == var[k])
			k++;
		if (var[k] == '\0' && env[i][k] == '=')
			return (i);
		i++;
	}
	return (-1);
}
