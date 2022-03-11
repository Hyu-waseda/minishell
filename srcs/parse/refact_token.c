/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refact_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaneko <kkaneko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:04:42 by kkaneko           #+#    #+#             */
/*   Updated: 2022/03/11 21:46:30 by kkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	del_empty_node(t_list **now, t_list **top)
{
	t_list	*now_after_refact;

	if ((*now)->prev == NULL)
	{
		*now = (*now)->next;
		lstdel_head(top);
	}
	else if ((*now)->next == NULL)
	{
		now_after_refact = (*now)->prev;
		lstdel_tail(*now);
		*now = now_after_refact;
	}
	else
	{
		now_after_refact = (*now)->next;
		lstdel_mid(*now);
		*now = now_after_refact;
	}
}

void	refact_token(t_list **top)
{
	t_list	*now;
	t_list	*del;
	size_t	i;

	i = 0;
	now = *top;
	while (now != NULL)
	{
		if (now->content == NULL || ft_strncmp(now->content, "\0", 1) == 0)
			del_empty_node(&now, top);
		else
		{
			remove_quotes(&(now->content));
			now = now->next;
		}
	}
}
