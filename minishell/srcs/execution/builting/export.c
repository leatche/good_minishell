/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:28:47 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/04/27 19:34:58 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// si premier chiffre _ ou lettre bon, et dans la suite les chiffres sont acceptées
// plus se renseigne du coup sur les $?

void	ft_export(int ac, char **av, t_bloc *bloc)
{
	(void)ac;
	ft_export_many(av, bloc);
	ft_export_simple(bloc);
}

void	ft_export_simple(t_bloc *bloc)
{
	int		i;
	char	**env;

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


void	ft_export_many(char **av, t_bloc *bloc)
{
	int		i;
	char	*var;
	char	*str;
	int		a;
	int		sign;
	char	**tmp;

	//dit si oui ou non il y a un +
	sign = ft_plus(av[1]);
	//var donnant la variable a rechercher.
	var = ft_pars_add(av[1]);
	//dit si la variable existe
	a = ft_search(bloc->tab_env, var);
	// si variable existe et qu'il y a un +
	if (a != -1 && sign == 1)
	{
		printf ("b\n");
		str = ft_rest(av[1], bloc->tab_env[a]);
		ft_replace(bloc, a, var);
		free (str);
	}
	// si variable existe et qu'il y pas de +
	else if (a != -1 && sign != 1)
	{
		printf ("c\n");
		ft_replace_all(bloc, a, av[1]);
		free (var);
	}
	// si variable existe pas
	else
	{
		printf ("d\n");
		i = ft_nb_lines_env(bloc->tab_env) + 1;
		//recopie
		tmp = add_to_env(bloc->tab_env, av[1], i);
		bloc->tab_env = tmp;
	}
	free(var);
}

void	ft_replace_all(t_bloc *bloc, int a, char *var)
{
	free (bloc->tab_env[a]);
	bloc->tab_env[a] = malloc(sizeof(char *) * (ft_strlen(var) + 1));
	bloc->tab_env[a] = ft_strdup(var);
	bloc->tab_env[a][ft_strlen(bloc->tab_env[a]) + 1] = '\0';
}

void	ft_replace(t_bloc *bloc, int a, char *var)
{
	int		i;
	int		l;
	char	*tmp;

	i = 0;
	l = 0;
	tmp = malloc(sizeof(char *) * (ft_strlen(var) + 1));
	while (bloc->tab_env[a][i])
	{
		tmp[l++] = bloc->tab_env[a][i];
		i++;
		if (bloc->tab_env[a][i + 1] == '"')
			i++;
	}
	free (bloc->tab_env[a]);
	bloc->tab_env[a] = malloc(sizeof(char *) * (ft_strlen(var) + ft_strlen(tmp) + 1));
	bloc->tab_env[a] = ft_strjoin(tmp, var);
	bloc->tab_env[a][ft_strlen(bloc->tab_env[a]) + 1] = '\0';
	free (tmp);
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
		return (NULL);
	new = malloc(sizeof(char ) * (ft_strlen(av) + 1));
	while (av[i])
	{
		new[i] = av[i];
		if (av[i + 1] && av[i + 2] && ((av[i + 1] == '+' && av[i + 2] == '=') || av[i + 1] == '='))
		{
			new[i + 1] = '\0';
			return (new);
		}
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
