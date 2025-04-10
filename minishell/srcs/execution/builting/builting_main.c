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

// il doit mettre dans son parsing que si il y a une commande avec la liste de builtings il renvoie a ft_builtings et que a ce moment les arguments ce soit une grande chaine de caractere et ne pas les separer
void	ft_builtings(t_bloc *bloc)
{
	if (bloc->cmd == "echo ")
		ft_echo(void);
}
