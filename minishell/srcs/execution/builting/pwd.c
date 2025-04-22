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

void    ft_pwd(int ac, char **av, t_bloc *bloc)
{
    if (ac >= 2)
        ft_exe_pwd(av[2], bloc);
}

void    ft_exe_pwd(char *av, t_bloc *bloc)
{
    char    *path;

    path = getcwd(NULL, 0);
    printf("%s\n", path);
    free (path);
}