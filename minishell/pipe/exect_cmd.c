/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exect_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:32:01 by yakhay            #+#    #+#             */
/*   Updated: 2023/04/12 15:17:53 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exect_cmd.h"

void	ft_putstr2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	write (1, "\n", 1);
}

void	ft_write_error_cmd_not_f(char *cmd)
{
	write(1, "error: command not found :", 26);
	ft_putstr2(cmd);
	exit (127);
}
char	*valider(t_env *env, char **cmd, t_data *var)
{
	char	**path;
	int i;
	t_env *node = ft_sherch_key(env, "PATH");
	if (env == NULL)
	{
			printf("minishell: %s: Permission denied\n",cmd[0]);
			return (NULL);
	}
	path = ft_split(env->val + 5, ':');
	i = 0;
	while (path && path[i])
	{
		var->str = ft_strjoin(path[i], cmd);
		if (access(var->str, F_OK & X_OK) == 0)
		{
			ft_free(path);
			return (var->str);
		}
		free(var->str);
		i++;
	}
	ft_write_error_cmd_not_f(cmd);
	return (NULL);
}

void ft_exec(t_data	*var)
{
	int i;

	i = 0;
	while (i > var->size - 1)
	{
		close(var->pipp[i][0]);
		close(var->pipp[i][1]);
		i++;
	}

}

void	mult_pip(t_data *var,t_info *info)
{
	while (var->i != info->index)
		info = info->next;
	if (valider(info->env, info->cmd,var) == NULL)
		exit(-1);
	if (info->input >= 0)
		dup2(info->input,0);
	else if (info->index > 0)
		dup2(var->pipp[info->index - 1][0],0);
	if (info->output >= 0)
		dup2(info->output, 1);
	else if (info->index != var->size - 1)
		dup2(var->pipp[info->index + 1][1],1);
	ft_exec(var);
	execve(var->str,info->cmd,var->env);

}

int fork_and_pip(t_data *var,t_info *info)
{
	int c;
	var->i = 0;
	while(var->size - 1 > var->i)
	{
		if (pip(var->pipp[var->i++]) == -1);
			return (-1);
	}
	var->i = 0;
	while (var->i < var->size)
	{
		 c = fork();
		 if (c == 0)
		 	mult_pip(var,info);
		var->i++;
	}
	return (0);
}
int main(int ac,char **av,char **env)
{
	t_info *info;
	t_data var;
	var.env = env;
	var.size = ft_lstsize(info);
	var.pipp = malloc((var.size) * sizeof(int *));
	var.i = 0;
	while(var.i < var.size - 1)
		var.pipp[var.i++] = malloc(2 * sizeof(int));
	var.pipp[var.i] = NULL;
	if (fork_and_pip(&var,info) == -1)
		return (write(1, "pip fulre\n", 10), 0);
	ft_exec(&var);
	while (wait(NULL) != -1)
			;
}
