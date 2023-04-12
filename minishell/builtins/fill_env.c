/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:02:48 by yakhay            #+#    #+#             */
/*   Updated: 2023/04/11 15:59:45 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
int ft_searsh(char *str, char c)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] == c)
			return (i - 1);
		i++;
	}
	return (-1);
}
void	ft_init_struct(t_env **local_env,char *env, int k)
{
	//int i;
	int	j;
	int count;
	char *str;
	str = NULL;

	j = ft_searsh(env,'=');
	if (j != -1)
	{
		str = malloc((j + 2) *sizeof(char));
		count = 0;
		while(env[count] != '=')
		{
			str[count] = env[count];
			count++;
		}
		 str[count] = '\0';
		ft_lstadd_back(local_env,ft_lstnew(str, ft_strdup(env + j + 2),k));

	}
	else
		ft_lstadd_back(local_env,ft_lstnew(str, NULL, k));

}
t_env *fill_struct(char **env)
{
	t_env *local_env;
	local_env = NULL;
	int i;
	i = 0;
	while(env[i])
	{

		ft_init_struct(&local_env,env[i],i);
		i++;
	}
	return (local_env);
}

// int main(int ac, char **av,char **env)
// {
// 	t_list *local_env;

// 	local_env = fill_struct(env);

// 	while (local_env)
// 	{
// 		printf("%s=%s\n",local_env->key,local_env->val);
// 		local_env = local_env->next;
// 	}
// }
