/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 10:54:01 by nwattana          #+#    #+#             */
/*   Updated: 2022/10/23 10:54:50 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rx(t_list **ta)
{
	t_list	*temp;

	if (!ta || !(*ta) || !(*ta)->next)
	{
		ft_putstr_fd("NULL at rx\n", 2);
		return ;
	}
	temp = pop(ta);
	ft_lstlast(*ta)->next = temp;
}

void	rrx(t_list **ta)
{
	t_list	*bf;
	t_list	*ls;

	if (!ta || !(*ta) || !(*ta)->next)
	{
		ft_putstr_fd("NULL at rrx", 2);
		return ;
	}
	ls = *ta;
	while (ls->next)
	{
		bf = ls;
		ls = ls->next;
	}
	bf->next = NULL;
	push(ta, ls);
}
