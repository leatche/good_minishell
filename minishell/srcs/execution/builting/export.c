/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:28:47 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/04/26 18:52:19 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export(int ac, char **av, t_bloc *bloc)
{
	char	**env;

	env = ft_cpy_tab(bloc);
	if (ac == 2)
	{
		ft_export_many(av, bloc);
		ft_export_simple(env, bloc);
	}
	// 	ft_export_simple(env, bloc);
	// else
	// 	ft_export_many(av, bloc);

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
	env = ft_sorting_env(env);
	while (env[i])
	{
		printf("%s\n", env[i]);
		free(env[i]);
		i++;
	}
	free(env);
	i = 0;
	while (bloc->secon_env[i])
	{
		printf("%s\n", bloc->secon_env[i]);
		free(bloc->secon_env[i]);
		i++;
	}
	free(bloc->secon_env);
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
	int		sign;

	//dit si oui ou non il y a un +
	sign = ft_plus(av[2]);
	//var donnant la variable a rechercher.
	var = ft_pars_add(av[2]);
	//dit si la variable existe
	a = ft_search(bloc->secon_env, var);
	// si variable existe et qu'il y a un +
	if (a != -1 && sign == -1)
	{
		var = ft_rest(av[2], bloc->secon_env[a]);
		bloc->secon_env[a] = ft_strjoin(bloc->secon_env[a], ft_rest(av[2], bloc->secon_env[a]));
		free (var);
	}
	// si variable existe et qu'il y pas de +
	else if (a != -1 && sign == -1)
		bloc->secon_env[a] = ft_strdup_cro(av[2], sign);
	// si variable existe pas
	else
	{
		free (var);
		// a la fin du tableau tu ecris
		i = ft_nb_lines_env(bloc->secon_env);
		//recopie
		bloc->secon_env[i] = ft_strdup_cro(av[2], sign);
	}
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

char	*ft_pars_add(char *av)
{
	int		i;
	char	*new;

	i = 0;
	if (!av)
		return (NULL);
	new = malloc(sizeof(char *) * ft_strlen(av));
	while (av[i])
	{
		new[i] = av[i];
		if (av[i + 1] && av[i + 2] && ((av[i + 1] == '+' && av[i + 2] == '=') || av[i + 1] == '='))
			return (new);
		i++;
	}
	free (new);
	return (NULL);
}

int	ft_search(char **envm, char *var)
{
	int	i;
	int	k;

	i = 0;
	while (envm && envm[i])
	{
		k = 0;
		while (var[k] && envm[i][k] && envm[i][k] == var[k])
			k++;
		if (envm[i][k] == '=')
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
	while (av[i - 1] != '+' && av[i - 2] != '=')
		i++;
	if (ft_no_equal(tab) == 1)
		i--;
	while (av[i])
	{
		b[k] = av[i];
		i++;
		k++;
	}
	av = b;
	b[k] = '\0';
	av = b;
	// free (b);
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

int	ft_plus(char *av)
{
	int	i;

	i = 0;
	if (!av)
		return (0);
	while(av[i])
	{
		if (av[i] == '+' && av[i + 1] == '=')
			return (1);
		i++;
	}
	return (0);
}
