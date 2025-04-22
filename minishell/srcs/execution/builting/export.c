#include "minishell.h"

void    ft_export(int ac, char **av, t_bloc *bloc)
{
    char    **env;

    env = ft_cpy_tab(bloc);
    if (ac == 2)
        ft_export_simple(env);
    else
        ft_export_many();
    tri alphabetique 
    rajoute declare....
    print
    destroy 

    si autre chose
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

void    ft_export_simple(char **env)
{
    int i;

    i = 0;
    env = ft_sorting_alph(env);
    while (env[i])
    {
        //  char *equal = ft_strchr(env[i], '=');
        // if (equal)
        // {
        //     int key_len = equal - env[i];
        //     printf("declare -x ");
        //     write(1, env[i], key_len + 1); // key=
        //     printf("\"%s\"\n", equal + 1); // value
        // }
        // else
        //     printf("declare -x %s\n", env[i]);
        // i++;
    }
}

char    **ft_sorting_alph(char **env)
{
    int i;

    while (ft_sorted(env) != 1)
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

void    ft_swap(char *a, char *b)
{
    char *tmp;

    *tmp = *a;
    *a = *b;
    *b = *tmp;
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
