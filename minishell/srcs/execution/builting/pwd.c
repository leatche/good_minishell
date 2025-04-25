/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:29:43 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/04/24 17:29:46 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(int ac, char **av, t_bloc *bloc)
{
	if (ac >= 2)
		ft_exe_pwd(av[2], bloc);
}

void	ft_exe_pwd(char *av, t_bloc *bloc)
{
	char	*path;

	path = getcwd(NULL, 0);
	printf("%s\n", path);
	free (path);
}
