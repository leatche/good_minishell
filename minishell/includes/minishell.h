/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:01:44 by ltcherep          #+#    #+#             */
/*   Updated: 2025/04/26 17:00:10 by tcherepoff       ###   ########.fr       */
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

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_bloc
{
	char			*cmd;
	char			**arg;
	char			*input_redir;
	char			*output_redir;
	struct s_bloc	*next;
	unsigned int	erreur;
	char			**tab_env;
	char			**secon_env;
	t_list			**list;
}					t_bloc;
//libft
int	ft_strncmp(char *s1, char *s2, unsigned int n);
//parsing
//execution
void	ft_echo(int ac, char **av);
int		ft_found_n(char arg, char arg2);
int		ft_check_echo (char *arg, int i);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *src);
char	*ft_one_string(int ac, char **av);
// void    ft_cd(int ac, char **av);
// void    ft_cd_exe(char **av);
int	ft_atoi(const char *str);

void    ft_exit(int ac, char **av, t_bloc *bloc);
void    ft_exit_complex(char *av, int sign);
int    ft_num(char *av);
int    ft_exit_many();
void    ft_env(t_bloc *bloc);
char *ft_strchr(const char *s, int c);
void	ft_initialized_env(char **envp, t_bloc *bloc);
void	ft_free_all(t_bloc *bloc);
int		ft_nb_lines_env(char **envp);
void    ft_export(int ac, char **av, t_bloc *bloc);
char    **ft_cpy_tab(t_bloc *bloc);
void    ft_export_simple(char **env, t_bloc *bloc);
char    **ft_sorting_alph(char **env);
void    ft_swap(char **a, char **b);
int ft_sorted(char **env);
int ft_strcmp(const char *s1, const char *s2);
void	ft_export_many(char **av, t_bloc *bloc);
char	**ft_sorting_env(char **env);
char	*ft_strdup_cro(const char *src, int sign);
char	*ft_pars_add(char *av);
int	ft_search(char **env, char *var);
char	*ft_rest(char *av, char *tab);
int	ft_no_equal(char *tab);
int	ft_plus(char *av);
char	*ft_strdup_equal(const char *src);
#endif
