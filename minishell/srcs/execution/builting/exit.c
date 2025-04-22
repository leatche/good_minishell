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

void    ft_exit(int ac, char **av, t_bloc *bloc)
{
    printf("exit\n");
    if (ac == 2)
    {
        free_all(bloc);
        exit(0);
    }  
    else if (ac == 3 || ft_num(av[2]) == -1)
    {
        free_all(bloc);
        ft_exit_complex(av[2], ft_num(av[2]));
    } 
    else
        ft_exit_many();
}

void    ft_exit_complex(char *av, int sign)
{
    if (sign == -1)
    {
        printf("minishell: exit: %s: numeric argument required\n", av);
        exit(2);
    }
    exit((unsigned char)ft_atoi(av));
}

int    ft_num(char *av)
{
    int i;
    int sign;

    i = 0;
    sign = 1;
    if (av[0] == '+' && av[1] >= '0' && av[1] <= '9')
        i++;
    if (av[0] == '-' && av[1] >= '0' && av[1] <= '9')
    {
        sign = 2;
        i++;
    }
    if (ft_strlen(av) >= 20)
        return (-1);
    while (av[i])
    {
        if (av[i] < '0' || av[i] > '9')
            return (-1);
        i++;
    }
    return (sign);
}

int    ft_exit_many()
{
    printf("minishell: exit: too many arguments\n");
    return (1);
}
