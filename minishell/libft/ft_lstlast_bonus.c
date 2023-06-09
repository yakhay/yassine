/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:32:32 by yakhay            #+#    #+#             */
/*   Updated: 2023/04/11 15:39:51 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_env	*ft_lstlast(t_env	*lst)
{
	while (lst && lst->next != NULL)
		lst = lst->next;
	return (lst);
}
//#include <stdio.h>
//int main()
//{
//	t_list *yass = NULL;
//	t_list *khay = NULL;
//	t_list *me = NULL;
//	yass = (t_list *)malloc(sizeof(t_list));
//	khay = (t_list *)malloc(sizeof(t_list));
//	me = (t_list *)malloc(sizeof(t_list));
//	int c = 3;
//	int b = 1;
//	int a = 2;
//	yass->content = &b;
//	yass->next = khay;
//	khay->content = &a;
//	khay->next = me;
//	me->content = &c;
//	me->next = NULL;
//	printf("%d\n",*((int *)ft_lstlast(yass)->content));
//
//}
