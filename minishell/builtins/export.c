/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:43:55 by yakhay            #+#    #+#             */
/*   Updated: 2023/04/12 14:26:51 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while ((s1[i] && s2[i]))
	{
		if (s1[i] != s2[i])
			return s1[i] - s2[i];
		i++;
	}
	return (s1[i] - s2[i]);
}
int ft_sheack_error(char *str)
{

	int j;

		if (!(str[0] >= 'a' && str[0] <= 'z') && !(str[0] >= 'A' && str[0] <= 'Z') && str[0] != '_')
			return(-1);
		j = 1;
		while(str[j])
		{
			if (str[j] == '=')
				return (0);
			if (str[j] == '+' && str[j + 1] == '=')
				return(0);
			if (!(str[j] >= 'a' && str[j] <= 'z') && !(str[j] >= 'A' && str[j] <= 'Z') && str[j] != '_' && !(str[j] >= '0' && str[j] <= '9'))
				return (-1);
				j++;
		}
	return 0;
}
t_env	*ft_export_sort(t_env **en)
{
	int c;
	t_env *head;
	t_env *env;
	char *str;
	char *ptr;
	head = *en;
	while (head)
	{
		env = head->next;
		while(env)
		{
			//printf("%s===%s\n",head->key,env->key);
			if (ft_strcmp(head->key,env->key) > 0)
			{
				str = head->key;
				head->key = env->key;
				env->key = str;
				ptr = head->val;
				head->val = env->val;
				env->val = ptr;
				c = head->index;
				head->index = env->index;
				env->index = c;
			}
			env = env->next;
		}
		head = head->next;
	}
	return (*en);
}
t_env *ft_sherch_key(t_env *lst, char *key)
{
	while (lst)
	{
		if (ft_strcmp(key,lst->key) == 0)
			return (lst);
		lst = lst->next;
	}
	return(NULL);
}
t_env	*ft_export(t_env *list, char **str)
{
	t_env *tmp;
	t_env *nod;
	char *ptr;
	int i;
	int count;
	int j;

	tmp = list;
	if (str[1] == NULL && ft_strcmp(str[0] , "export") == 0)
	{
		tmp = ft_export_sort(&list);
		while (tmp)
		{
			if (tmp->val != NULL)
				printf("declare -x %s=\"%s\"\n",tmp->key,tmp->val);
			else
				printf("declare -x %s\n",tmp->key);
			tmp = tmp->next;
		}
	}
	else
	{
		i = 1;
		while (str[i])
		{
			j = ft_searsh(str[i], '=');
			if (ft_sheack_error(str[i]) == -1)
				printf("minishell: export: `%s': not a valid identifier\n",str[i]);
			else if (j != -1 )
			{
				if (str[i][j] == '+')
				{
					count = 0;
					ptr = malloc((j +1)* sizeof(char));
					while (str[i][count] != '+')
					{
						ptr[count] = str[i][count];
						count++;
					}
					ptr[count] = '\0';
					nod =ft_sherch_key(list,ptr);
					printf("==%s==\n",ft_strdup(str[i] + j + 2));
					if (nod == NULL)
						ft_lstadd_back(&list,ft_lstnew(ptr,ft_strdup(str[i] + j + 2), ft_lstsize(list)));
					else
					{

						if (nod->val != NULL && nod->val[0] != '\0')
						nod->val =ft_strjoin(nod->val,ft_strdup(str[i] + j + 2));
						else
							nod->val =ft_strdup(str[i] + j + 2);
						free(ptr);
					}
				}
				else
				{
					count = 0;
					ptr = malloc((j + 2) * sizeof(char));
					while (str[i][count] != '=')
					{
						ptr[count] = str[i][count];
						count++;
					}
					ptr[count] = '\0';
					nod =ft_sherch_key(list,ptr);
					if (nod == NULL)
						ft_lstadd_back(&list,ft_lstnew(ptr,ft_strdup(str[i] + j + 2), ft_lstsize(list)));
					else
					{
						free(ptr);
						free(nod->val);
						nod->val =ft_strdup(str[i] + j + 2);
					}
				}
			}
			else
			{
				nod =ft_sherch_key(list,str[i]);
				if (nod == NULL)
					ft_lstadd_back(&list,ft_lstnew(ft_strdup(str[i]),NULL,ft_lstsize(list)));
			}
			i++;
		}
		tmp = ft_export_sort(&list);
	}
	return (list);
}
