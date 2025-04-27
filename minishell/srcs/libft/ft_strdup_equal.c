/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_equal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:07:08 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/04/27 19:22:43 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strdup_equal(const char *src)
{
	int		i;
	int		j;
	int		count;
	char	*new;

	i = 0;
	j = 0;
	count = 0;
	if (!src)
		return (NULL);
	new = malloc(sizeof(char) * (ft_strlen(src) + 3));
	while (src[i])
	{
		new[j++] = src[i];
		if (src[i] == '=' && count == 0 && src[i + 1] != '"')
		{
			new[j++] = '"';
			count++;
		}
		i++;
	}
	if (src[ft_strlen(src)] != '"')
		new[j] = '"';
	new[j + 1] = '\0';
	return (new);
}
