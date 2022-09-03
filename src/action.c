/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 20:38:50 by nwattana          #+#    #+#             */
/*   Updated: 2022/09/03 20:48:57 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*pop(t_list **head)
{
	t_list	*tmp;

	if (!head || !*head)
		return (NULL);
	temp = *head;
	*head = *head->next;
	temp->next = NULL;
	return (temp);
}

void	push(t_list **head_ref, t_list *node)
{
	ft_lstadd_front(head_ref, node);
}

void	push(t_list **from, t_list **to)
{
	t_list *tmp1;
	t_list *tmp2;

	tmp = pop(from);
	push(to, tmp);
}

void	swap(t_list **ta)
{
	t_list *tmp;
	t_list *tmp2;

	if (!ta || !(*ta))
			return ;
	if (ta->next)
		tmp = ta->next;
	tmp = pop(ta);
}
