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

void    ft_cd(int ac, char **av, char **env)
{
    if (ac == 3)
        ft_cd_exe(av, env);
    else
        printf("cd: too many arguments\n");
}

void    ft_cd_exe(char **av, char **env)
{

    if (av[2] == "" || av[2] == '~')
        ft_cd_empty(env);
    else if (av[2] == '-')
        ft_cd_back(env);
    else
        ft_cd_dir(av[2], env);
}

void    ft_cd_empty(char **env)
{
    char    *path;
    char    *actual_path;

    actual_path = getcwd(NULL, 0);
    path = getenv("HOME");
    ft_old_pwd(actual_path, env);
    chdir(path);
    free (actual_path);
}

void    ft_cd_back(char **env)
{
    char    *future_path;
    char    *actual_path;

    actual_path = getcwd(NULL, 0);
    future_path = getenv("OLDPWD");
    ft_old_pwd(actual_path, env);
    chdir(future_path);
    printf("%s\n", future_path);
    free (actual_path);
}

void    ft_cd_dir(char *av, char **env)
{
    char    *actual_path;
    char    *new_path;

    actual_path = getcwd(NULL, 0);
    ft_old_pwd(actual_path, env);
    new_path = chdir(av);
    if (new_path != 0)
    {
        perror("cd");
        return ;
    }
    free (actual_path);
}

void    ft_old_pwd(char *path, char **env)
{

}

