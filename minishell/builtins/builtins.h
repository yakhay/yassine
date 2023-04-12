/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:56:11 by yakhay            #+#    #+#             */
/*   Updated: 2023/04/12 14:31:20 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUILTINS_H
#define BUILTINS_H
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "../libft/libft.h"
#include <readline/readline.h>

t_env *cd(t_env **lst,char *option);
void ft_echo(char **cmd);
void pwd(void);
t_env	*ft_export_sort(t_env **en);
int	ft_strcmp(const char *s1, const char *s2);
t_env	*ft_export(t_env *list, char **str);
t_env *fill_struct(char **env);
int ft_searsh(char *str, char c);
void ft_unset(t_env **list, char **key);
t_env *ft_sherch_key(t_env *lst, char *key);
t_env *builtins(t_env *lst,char **str);
void	ft_exit(char **str);
void ft_env(t_env *list);
#endif
