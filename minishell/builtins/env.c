/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:36:57 by yakhay            #+#    #+#             */
/*   Updated: 2023/04/12 14:29:21 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
void ft_env(t_env *list)
{
	t_env *node;
	int i = 0;
	t_env *ptr;
	ptr = list;
	node = list;
	while(list)
	{
		node = ptr;
		while (node)
		{
			if (i == node->index && node->val != NULL)
				printf("%s=%s\n",node->key,node->val);
			node = node->next;
		}
		list = list->next;
		i++;
	}
}
