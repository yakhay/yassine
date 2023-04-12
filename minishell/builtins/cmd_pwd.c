/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:58:18 by yakhay            #+#    #+#             */
/*   Updated: 2023/04/01 13:20:55 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include <stdio.h>
#include <unistd.h>
void pwd(void)
{
	char puf[1000];

	if (getcwd(puf, sizeof(puf)) ==  NULL)
		perror("error :");
	else
		printf("%s\n",puf);
}
