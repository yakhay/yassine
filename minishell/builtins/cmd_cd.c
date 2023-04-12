/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:53:14 by yakhay            #+#    #+#             */
/*   Updated: 2023/04/12 14:25:14 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include <stdio.h>
#include <unistd.h>
t_env *cd(t_env **lst,char *option)
{

	char buf[10000];
	t_env *node;
	// t_list *node2;
	int ret;
	char *path;
	char buf1[1000];
	ret = 0;
	path = NULL;
	getcwd(buf1 ,sizeof(buf1));
	if (option)
		ret = chdir(option);
	if (!option)
	{
		node = ft_sherch_key(*lst,"HOME");
		path = ft_strjoin(path,ft_strdup(node->val));
	}
	else if (ret == -1)
	{
		path = ft_strjoin(ft_strdup(buf),ft_strdup("/"));
		path = ft_strjoin(path,ft_strdup(option));
	}
	if (path)
		ret = chdir(path);
	//printf("--%s--\n",path);//printf("%s\n",getcwd(buf ,sizeof(buf)));
	if (ret == -1)
		printf("cd: no such file or directory: %s\n",option);
	else
	{
		if (getcwd(buf ,sizeof(buf)) ==NULL)
			perror("getcwd() error");
		printf("hna str = %s buf = %s\n", buf1 , buf);
		builtins(*lst,ft_split(ft_strjoin(ft_strdup("export PWD="),ft_strdup(buf)),' '));
		builtins(*lst,ft_split(ft_strjoin(ft_strdup("export OLDPWD="),ft_strdup(buf1)),' '));
		// node = ft_sherch_key(*lst,"OLDPWD");
		// node2 =ft_sherch_key(*lst,"PWD");
		// free(node->val);
		// node->val = ft_strdup(node2->val);
		// free(node2->val);
		// node2->val = ft_strdup(buf);
	}
	free(path);
	return (*lst);
}
// int main()
// {
// 	cd("../libft");
// 	system("leaks a.out");
// }
