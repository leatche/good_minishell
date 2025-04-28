/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builting_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:51:58 by ltcherep          #+#    #+#             */
/*   Updated: 2025/04/28 11:46:37 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	ft_dispersion(int ac, char **av, t_bloc *bloc)
// {
// 	if (bloc->cmd == "echo")
// 		ft_echo(ac, av);
// 	else if (bloc->cmd == "cd")
// 		ft_cd(ac, av, bloc);
// 	else if (bloc->cmd == "pwd")
// 		ft_pwd(ac, av, bloc);
// 	else if (bloc->cmd == "exit")
// 		ft_exit(ac, av, bloc);
// 	else if (bloc->cmd == "env")
// 		ft_env(bloc);
// 	else if (bloc->cmd == "unset")
// 		ft_unset();
// 	else if (bloc->cmd == "export")
// 		ft_export();
// 	else
// 		ft_execve();
// }

int	main(int ac, char **av, char **envp)
{
	t_bloc	*bloc;

	if (ac == 2)
	{
		bloc = malloc(sizeof(t_bloc));
		ft_initialized_env(envp, bloc);
		// /* while (42)
		// // ft_dispersion(ac, av, bloc);
		// */
		ft_export(ac, av, bloc);
		ft_free_all(bloc);
		printf("end!\n");
	}
}

void	ft_initialized_env(char **envp, t_bloc *bloc)
{
	int		i;
	int		size;

	i = 0;
	size = ft_nb_lines_env(envp);
	bloc->tab_env = malloc(sizeof(char *) * (size + 1));
	while (envp[i])
	{
		bloc->tab_env[i] = ft_strdup(envp[i]);
		i++;
	}
	bloc->tab_env[i] = NULL;
}

void	ft_free_all(t_bloc *bloc)
{
	int	i;

	i = 0;
	while (bloc->tab_env[i])
	{
		free(bloc->tab_env[i]);
		i++;
	}
	free(bloc->tab_env);
	free(bloc);
}

int	ft_nb_lines_env(char **envp)
{
	int	i;

	i = 0;
	if (!envp)
		return (0);
	while (envp[i])
		i++;
	return (i);
}
