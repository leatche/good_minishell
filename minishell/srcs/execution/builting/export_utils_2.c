/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:16:08 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/04/28 23:36:27 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_rest(char *av)
{
	char *b = ft_strdup(ft_strchr(av, '=') + 1);
	printf("rest = '%s'\n", b);
	return (b);
}

int	ft_no_equal(char *tab)
{
	int	i;

	i = 0;
	while (tab[i]) // tab == NULL > segfault
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

	if (av[0] != '_' && ft_isalpha(av[0]) == 0)
		return (-1); // TODO: Return 0 instead of -1, so you can use function in a if, as a boolean
	i = 1;
	while (av[i] && av[i] != '+' && av[i] != '=')
	{
		if (av[i] != '_' && ft_isalpha(av[i]) == 0 && ft_isdigit(av[i]) == 0)
			return (-1);
		i++;
	}
	return (1);
}
