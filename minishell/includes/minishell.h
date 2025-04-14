/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltcherep <ltcherep@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:01:44 by ltcherep          #+#    #+#             */
/*   Updated: 2025/04/10 13:49:27 by ltcherep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

//librairies
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>
# include <limits.h>

//structure
typedef struct s_env
{

}				t_env;

typedef struct s_bloc
{
	char			*cmd;
	char			**arg;
	char			*input_redir;
	char			*output_redir;
	struct s_bloc	*next;
}					t_bloc;
//libft
int	ft_strncmp(char *s1, char *s2, unsigned int n);
//parsing
//execution
void	ft_echo(char **av);
int		ft_found_n(char arg, char arg2);
int		ft_check_echo (char *arg, int i);
int		is_builtin(char *cmd);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *src);
char	*ft_one_string(char **av);
void    ft_cd(int ac, char **av);
void    ft_cd_exe(char **av);
#endif
