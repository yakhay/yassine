/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:28:44 by yakhay            #+#    #+#             */
/*   Updated: 2023/04/12 14:29:49 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
t_env *builtins(t_env *lst,char **str)
{

	if (ft_strcmp(str[0], "cd") == 0)
		lst = cd(&lst,str[1]);
	else if (ft_strcmp(str[0], "echo") == 0)
		ft_echo(str);
	else if (ft_strcmp(str[0], "pwd") == 0)
		pwd();
	else if (ft_strcmp(str[0], "export") == 0)
		lst = ft_export(lst, str);
	else if (ft_strcmp(str[0], "env") == 0)
		ft_env(lst);
	else if (ft_strcmp(str[0], "exit") == 0)
		ft_exit(str);
	else if (ft_strcmp(str[0], "unset") == 0)
		ft_unset(&lst, str);
	else
		printf ("commend not found hh\n");
	return (lst);

}

int main(int ac ,char **av , char **env)
{
	char *str;
	char **ptr;
	str = NULL;
	t_env *lst;

	lst = fill_struct(env);
	(void)ac;
	(void)av;

	while ((str = readline("minishell> ")))
	{
		add_history(str);

		ptr = ft_split(str,' ');
		lst = builtins(lst,ptr);

	}
}
