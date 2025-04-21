/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builting_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltcherep <ltcherep@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:51:58 by ltcherep          #+#    #+#             */
/*   Updated: 2025/04/10 14:02:27 by ltcherep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
il doit mettre dans son parsing que si is_builtin marche, alors il y a une commande avec la liste de builtings il renvoie a ft_builtings et que a ce moment les arguments ce soit une grande chaine de caractere et ne pas les separer

int	is_builtin(char *cmd)
{
	if (!cmd)
		return (-1);
	if (!ft_strncmp("echo", cmd, INT_MAX) || !ft_strncmp("cd", cmd, INT_MAX) \
	|| !ft_strncmp("pwd", cmd, INT_MAX) || !ft_strncmp("export", cmd, INT_MAX) \
	|| !ft_strncmp("unset", cmd, INT_MAX) || !ft_strncmp("env", cmd, INT_MAX) \
	|| !ft_strncmp("exit", cmd, INT_MAX))
		return (1);
	return (-1);
}
	if (bloc->cmd == "echo ")
		ft_echo(void);
}
*/

int main(int ac, char **av, char **env)
{
    ft_exit(ac, av);
	printf("Didn't exited!\n");
}