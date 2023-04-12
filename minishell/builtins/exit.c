/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:02:51 by yakhay            #+#    #+#             */
/*   Updated: 2023/04/09 15:46:11 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int cheak_valid_arg(char **str)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (str[i][j])
	{
		if (j == 0 && (str[i][j] == '-' || str[i][j] == '+'))
			j++;
		if (!(str[i][j] >= '0' && str[i][j] <= '9'))
			return (-2);
		j++;
	}
	if(str[2])
		return (write(2,"exit\nminishell : too many arguments\n",25),-1);
	return (0);
}
void	ft_exit(char **str)
{
	int c;
	if (str[1] == NULL)
		exit(1);
	if (cheak_valid_arg(str) == -1)
		return ;
	else if (cheak_valid_arg(str) == -2)
	{
		write(2,"exit\n",5);
		write(2,"exit:",5);
		printf("%s: numeric argument required\n",str[1]);
		exit (255);
	}
	c = ft_atoi(str[1]);
	write(2,"exit\n",5);
	exit(c);
}

