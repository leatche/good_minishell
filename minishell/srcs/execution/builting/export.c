#include "minishell.h"

void    ft_export(int ac, char **av, t_bloc *bloc)
{
    char    **env;

    if (ac == 2)
        ft_export_simple(env, bloc);
    else
        ft_export_many(av, bloc);
}

char    **ft_cpy_tab(t_bloc *bloc)
{
    int     i;
    char    **env;

    i = 0;
    env = malloc(sizeof (char *) * (ft_nb_lines_env(bloc->tab_env) + 1));
    while (bloc->tab_env[i])
	{
		env[i] = ft_strdup(bloc->tab_env[i]);
		i++;
	}
	env[i] = NULL;
    return (env);
}

void    ft_export_simple(char **env, t_bloc *bloc)
{
    int i;

    i = 0;
    env = ft_cpy_tab(bloc);
    env = ft_sorting_env(env);
    while (env[i])
    {
        printf("%s\n", env[i]);
        free(env[i]);
        i++;
    }
    free(env);
}

char    **ft_sorting_alph(char **env)
{
    int i;

    while (ft_sorted(env) == -1)
    {
        i = 0;

        while (env[i] && env[i + 1])
        {
            if (ft_strcmp(env[i], env[i + 1]) > 0)
                ft_swap(&env[i], &env[i + 1]);
            i++;
        }
    }
    return (env);

}

void    ft_swap(char **a, char **b)
{
    char *tmp;


    tmp = *a;
    *a = *b;
    *b = tmp;
}

int ft_sorted(char **env)
{
    int i;

    i = 0;
    while (env[i] && env[i + 1])
    {
        if (ft_strcmp(env[i], env[i + 1]) > 0)
            return (-1);
        i++;
    }
    return (1);
}

void    ft_export_many(char **av, t_bloc *bloc)
{
    int i;

    i = 0;


}

char    **ft_sorting_env(char **env)
{
    int i;
    char    *tmp;

    i = 0;
    env = ft_sorting_alph(env);
    while (env[i])
    {
        tmp = env[i];
        env[i] = ft_strjoin("declare -x ", tmp);
        free(tmp);
        i++;
    }
    return (env);
}