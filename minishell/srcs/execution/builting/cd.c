/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltcherep <ltcherep@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:09:03 by ltcherep          #+#    #+#             */
/*   Updated: 2025/04/10 15:58:08 by ltcherep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_cd(int ac, char **av) //, char **env
{
    if (ac == 3)
        ft_cd_exe(av);
    else
        printf("cd: too many arguments\n");
}

void    ft_cd_exe(char **av) //, char **env
{

    if (av[2] == "" || av[2] == '~')
        ft_cd_empty();
    else if (av[2] == '-')
        ft_cd_back();
    else
        ft_cd_dir(av[2]);
}

void    ft_cd_empty()
{
    char    *path;

    path = getenv("HOME");
    chdir(path);
}

void    ft_cd_back()
{
    char    *path;

    path = getenv("OLDPWD");
    chdir(path);
    printf("%s\n", path);
}

void    ft_cd_dir(char *av)
{
    char    *previous_path;

    previous_path = getcwd(NULL, 0);
    $OLDPWD = previous_path; // faire deux fonctions
    if (chdir(av) != 0)
    {
        perror("cd");
        return ;
    }
    $PWD = getcwd(NULL, 0); // faire deux fonctions
}