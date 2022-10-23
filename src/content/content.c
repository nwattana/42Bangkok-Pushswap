/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 19:16:45 by nwattana          #+#    #+#             */
/*   Updated: 2022/10/23 11:28:41 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_cont	*cont_init(int n)
{
	t_cont	*cont;

	cont = malloc(sizeof(t_cont));
	if (!cont)
		return (NULL);
	cont->val = n;
	cont->po = 1;
	cont->grp = 0;
	cont->au = 0;
	return (cont);
}

int	g_cont_po(t_list *lst)
{
	if (!lst)
		return (-1);
	return (((t_cont *)(lst->content))->po);
}

int	*ga_cont_po(t_list *lst)
{
	if (!lst)
		return (NULL);
	return (&((t_cont *)(lst->content))->po);
}
