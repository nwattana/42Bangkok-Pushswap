/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 11:27:10 by nwattana          #+#    #+#             */
/*   Updated: 2022/10/23 11:28:20 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	g_cont_grp(t_list *lst)
{
	if (!lst)
		return (-1);
	return (((t_cont *)(lst->content))->grp);
}

int	*ga_cont_grp(t_list *lst)
{
	if (!lst)
		return (NULL);
	return (&((t_cont *)(lst->content))->grp);
}

int	*ga_cont_data(t_list *lst)
{
	if (!lst)
		return (NULL);
	return (&((t_cont *)(lst->content))->val);
}

int	g_cont_data(t_list *lst)
{
	if (!lst)
		return (-1);
	return (((t_cont *)(lst->content))->val);
}
