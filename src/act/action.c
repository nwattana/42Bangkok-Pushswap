/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 20:38:50 by nwattana          #+#    #+#             */
/*   Updated: 2022/10/23 10:53:57 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*pop(t_list **head)
{
	t_list	*temp;

	if (!head || !*head)
		return (NULL);
	temp = *head;
	*head = (*head)->next;
	temp->next = NULL;
	return (temp);
}

void	push(t_list **head_ref, t_list *node)
{
	if (!head_ref || !node)
	{
		ft_putstr_fd("NULL at push\n", 2);
	}
	ft_lstadd_front(head_ref, node);
}

void	px(t_list **from, t_list **to)
{
	t_list	*tmp;

	if (!(*from))
		ft_putstr_fd("NULL at px\n", 2);
	tmp = pop(from);
	push(to, tmp);
}

void	swap(t_list **ta)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!ta || !(*ta) || !(*ta)->next)
	{
		ft_putstr_fd("NULL at swap\n", 2);
		return ;
	}
	tmp = pop(ta);
	tmp2 = pop(ta);
	push(ta, tmp);
	push(ta, tmp2);
}
