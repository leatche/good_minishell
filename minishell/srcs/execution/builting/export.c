/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:28:47 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/04/25 20:47:36 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export(int ac, char **av, t_bloc *bloc)
{
	char	**env;

	if (ac == 2)
		ft_export_simple(env, bloc);
	else
		ft_export_many(av, bloc);
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

void	ft_export_simple(char **env, t_bloc *bloc)
{
	int i;

	i = 0;
	env = ft_cpy_tab(bloc);
	env = ft_sorting_env(env);
	while (env[i])
	{
		printf("%s\n", env[i]);
		free(env[i]);
		i++;
	}
	free(env);
}

char	**ft_sorting_alph(char **env)
{
	int i;

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

void	ft_swap(char **a, char **b)
{
	char *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int ft_sorted(char **env)
{
	int i;

	i = 0;
	while (env[i] && env[i + 1])
	{
		if (ft_strcmp(env[i], env[i + 1]) > 0)
			return (-1);
		i++;
	}
	return (1);
}

void	ft_export_many(char **av, t_bloc *bloc)
{
	int		i;
	char	*var;
	int		a;

	var = ft_pars_add(av[2]);
	if (var != NULL)
	{
		a = ft_search(bloc->secon_env, var);
		if (a != -1)
		{
			var = ft_rest(av[2], bloc->secon_env[a]);
			bloc->secon_env[a] = ft_strjoin(bloc->secon_env[a], ft_rest(av, bloc->secon_env[a]));
			free (var);
			return ;
		}
		free (var);
	}
	i = ft_nb_lines_env(bloc->secon_env);
	bloc->secon_env[i] = ft_strdup_cro(av[2], a);
	}

char	**ft_sorting_env(char **env)
{
	int i;
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

char	*ft_strdup_cro(const char *src, int a)
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
		if (a == -1 && src[i] == '+' && src[i + 1] == '=')
			i++;
		new[g] = src[i];
		i++;
		g++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_pars_add(char *av)
{
	int		i;
	char	*new;

	i = 0;
	new = malloc(sizeof(char *) * ft_strlen(av));
	while (av[i])
	{
		if (av[i + 1] && av[i + 2] && av[i + 1] == '+' && av[i + 2] == '=')
			return (new);
		new[i] = av[i];
		i++;
	}
	free (new);
	return (NULL);
}

int	ft_search(char **env, char *var)
{
	int	i;
	int	k;

	i = 0;
	while (env[i])
	{
		k = 0;
		while (var[k] && env[i][k] && env[i][k] == var[k])
			k++;
		if (env[i][k] == '=')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_rest(char *av, char *tab)
{
	int	i;
	int	k;
	char *b;

	i = 0;
	k = 0;
	b = malloc(sizeof(char *) * ft_strlen(av));
	while (av[i - 2] != '+' && av[i - 1] != '=')
		i++;
	if (ft_no_equal(tab) == 1)
		i--;
	while (av[i])
	{
		b[k] = av[i];
		i++;
		k++;
	}
	b[k] = '\0';
	av = b;
	free (b);
	return (av);
}

int	ft_no_equal(char *tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] == '=')
			return (-1);
		i++;
	}
	return (1);
}
