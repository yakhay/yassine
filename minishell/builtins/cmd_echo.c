/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:48:57 by yakhay            #+#    #+#             */
/*   Updated: 2023/04/07 16:37:04 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include <stdio.h>
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return s1[i] - s2[i];
		i++;
	}
	return (0);
}
void	printf_arg(char **cmd,int i)
{
	int j;

	j = i;
	while(cmd[j])
	{
		printf("%s",cmd[j++]);
		if (cmd[j])
			printf(" ");
	}
	if (i != 3)
		printf("\n");
}
void ft_echo(char **cmd)
{
	int i, j;

	i = 2;
	while(cmd[i])
	{
		j = 1;
		if (cmd[i][0] == '-' && cmd[i][j] == 'n')
		{
			while (cmd[i][j] == 'n')
				j++;
			if (cmd[i][j] != '\0')
			{
				printf_arg(cmd , i);
				exit(1);
			}
		}
		else
		{
			printf_arg(cmd , i);
				exit(0);
		}
		i++;

	}
}
// int main(int ac, char **av)
// {

// 	ft_echo(av);

// }
