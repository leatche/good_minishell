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

void    ft_cd(int ac, char **av, t_bloc *bloc)
{
    if (ac == 3)
        ft_cd_exe(av, bloc);
    else
    {
        printf("minishell: cd: too many arguments\n");
        bloc->erreur = 1;
    } 
}

void    ft_cd_exe(char **av, t_bloc *bloc)
{

    if (av[2] == "" || av[2] == '~')
        ft_cd_empty(bloc);
    else if (av[2] == '-')
        ft_cd_back(bloc);
    else
        ft_cd_dir(av[2], bloc);
}

void    ft_cd_empty(t_bloc *bloc)
{
    char    *path;
    char    *actual_path;

    actual_path = getcwd(NULL, 0);
    path = getenv("HOME");
    ft_old_pwd(actual_path, bloc);
    chdir(path);
    free (actual_path);
}

void    ft_cd_back(t_bloc *bloc)
{
    char    *future_path;
    char    *actual_path;

    actual_path = getcwd(NULL, 0);
    future_path = getenv("OLDPWD");
    ft_old_pwd(actual_path, bloc);
    chdir(future_path);
    printf("%s\n", future_path);
    free (actual_path);
}

void    ft_cd_dir(char *av, t_bloc *bloc)
{
    char    *actual_path;
    char    *new_path;

    actual_path = getcwd(NULL, 0);
    ft_old_pwd(actual_path, bloc);
    new_path = chdir(av);
    if (new_path != 0)
    {
        printf("bash: cd: %s: No such file or directory", av);
        bloc->erreur = 1;
        return ;
    }
    free (actual_path);
}

void    ft_old_pwd(char *path, t_bloc *bloc)
{

}

