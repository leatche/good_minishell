/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltcherep <ltcherep@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:09:03 by ltcherep          #+#    #+#             */
/*   Updated: 2025/04/10 15:58:08 by ltcherep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(int ac, char **av)
{
	int		i;
	int		res;
	char	*arg;

	i = 0;
	res = 0;
	arg = ft_one_string(ac, av);
	while (arg[i] && arg[i] == 32)
		i++;
	if (arg[i] && arg[i] == '-' && arg[i + 1] == 'n')
		res = ft_check_echo(arg, i);
	if (res == 0)
		printf ("%s\n", arg);
	else
	{
		while (arg[i + res])
		{
			write(1, &arg[i + res], 1);
			i++;
		}
	}
	free(arg);
}

int	ft_found_n(char arg, char arg2)
{
	if (arg == 32 || arg == 'n')
		return (1);
	if (arg == '-' )
	{
		if (arg2 != 'n')
			return (-1);
		return (1);
	}
	return (-1);
}

int	ft_check_echo (char *arg, int i)
{
	int	res;

	i += 2;
	res = 2;
	while (arg[i] && arg[i] == 'n')
	{
		i++;
		res++;
	}
	if (arg[i] != 32 && (arg[i] != '-' || ( arg[i] == '-' && arg[i + 1] != 'n')))
		return (0);
	while (ft_found_n(arg[i], arg[i + 1]) == 1)
	{
		i++;
		res++;
	}
	return (res);
}

char	*ft_one_string(int ac, char **av)
{
	int		i;
	char	*arg;
	char *tmp;

	arg = NULL;
	i = 1;
	while (++i < ac)
	{
		tmp = arg;
		arg = ft_strjoin(arg, av[i]);
		free(tmp);
		if (i >= ac - 1)
			break;
		tmp = arg;
		arg = ft_strjoin(arg, " ");
		free(tmp);	
	}
	return (arg);
}
