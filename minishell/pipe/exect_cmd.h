/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exect_cmd.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:32:50 by yakhay            #+#    #+#             */
/*   Updated: 2023/04/12 14:50:54 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECOT_H
# define EXECOT_H


#include "../libft/libft.h"
#include "../builtins/builtins.h"
# include <fcntl.h>
# include <stdlib.h>
# include<unistd.h>
# include <stdio.h>
# include <errno.h>

typedef struct s_info
{
    int index;
    char **cmd;
    int    input;
    int output;
    //t_list    tok;
    int        exit_staus;
	t_env *env;
    struct s_info *next;
    struct s_info *prev;
}    t_info;
typedef struct data
{
	int		i;
	int size;
    char *str;
    char **env;
	int		**pipp;
}		t_data;

void	ft_write_error_cmd_not_f(char *cmd);
void	child_final_bonus(t_data *info, char **av, char **en, int ac);
char	*valid_path(char **env, char *cmd);
char	*get_next_line(int fd);
void	mult_pip(t_data *var,t_info *info);
//int		ft_strcmp(char *str, char *ptr, int c);
#endif
