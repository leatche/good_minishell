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

    chdir(av[2]);
    // if (res == 0)
    //     ft_update_path();
    // else
    // {
    //     write(2, "cd: ", 5);
    //     perror(av[1]);
    // }
}
       