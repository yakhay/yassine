/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:36:48 by yakhay            #+#    #+#             */
/*   Updated: 2023/04/11 16:02:19 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_env **lst, t_env *new)
{
	t_env	*list;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else if (*lst && new)
	{
		list = *lst;
		while (list->next != NULL)
			list = list->next;
		list->next = new;
	}
}
