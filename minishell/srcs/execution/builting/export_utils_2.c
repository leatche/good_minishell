/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:16:08 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/04/28 11:19:34 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_rest(char *av, char *tab)
{
	int		i;
	int		k;
	char	*b;

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
	while (av[i])
	{
		if (av[i] == '+' && av[i + 1] == '=')
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_start(char *av)
{
	int	i;

	i = 0;
	if (av[0] != "_" && ft_isalpha(av[0]) == 0)
		return (-1);
	while (av[++i])
	{
		if (av[i] != "_" && ft_isalpha(av[i]) == 0 && ft_isdigit(av[i]) == 0)
			return (-1);
	}
	return (1);
}
