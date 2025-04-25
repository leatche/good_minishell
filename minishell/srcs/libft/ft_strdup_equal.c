/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_equal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:07:08 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/04/24 16:13:06 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strdup_equal(const char *src)
{
	int			i;
	char	*new;

	i = 0;
	if (!src)
		return (NULL);
	new = malloc(sizeof(char) * ft_strlen(src) + 1);
	while (src[i])
	{
		while (src[i - 1] != '=')
		{
			new[i] = src[i];
			i++;
		}
		new[i] = '"';
		i++;
		while (src[i - 1])
		{
			new[i] = src[i - 1];
			i++;
		}
		new[i] = '"';
	}
	new[i + 1] = '\0';
	return (new);
}
