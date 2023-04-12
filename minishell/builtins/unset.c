/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:42:25 by yakhay            #+#    #+#             */
/*   Updated: 2023/04/12 14:30:29 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
void ft_unset(t_env **list, char **key)
{
	t_env *node;
	t_env *del;
	int i;
	i = 0;
	while (key[++i])
	{
		node = *list;
		if (ft_strcmp(node->key, key[i]) == 0)
		{
			free(node->key);
			free(node->val);
			*list = (*list)->next;
			free(node);
			return ;
		}
		while (node)
		{
			if (node->next && ft_strcmp(node->next->key, key[i]) == 0)
			{
				free(node->next->key);
				free(node->next->val);
				del = node->next;
				node->next = node->next->next;
				free(del);
			}
			node = node->next;
		}
	}
}
