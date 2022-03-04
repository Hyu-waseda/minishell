/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:47:26 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/03/03 22:44:02 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	echo(t_cmd *input)
{
	int		argc;
	t_list	*p;
	int		need_new_line;

	argc = ft_lstsize(input->args);
	p = input->args;
	need_new_line = 1;
	if (p != NULL && ft_strncmp(p->content, "-n", 2) == 0)
	{
		need_new_line = 0;
		p = p->next;
	}
	while (p != NULL)
	{
		printf("%s", p->content);
		p = p->next;
		if (p != NULL)
			printf(" ");
	}
	if (need_new_line)
		printf("\n");
}
/* 
//debug
int main(int ac, char **av, char **envp)
{
	t_cmd	*res;
	t_envp	*envp_list;

	res = parser(av[1]);
	envp_list = get_envp_list(envp);
	exec(res, envp_list);
	return (0);
} */