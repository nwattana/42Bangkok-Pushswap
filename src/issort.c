/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 07:42:16 by nwattana          #+#    #+#             */
/*   Updated: 2022/10/23 11:29:17 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	issort(t_list *s)
{
	int		a;
	int		b;

	if (s)
		a = g_cont_po(s);
	while (s->next)
	{
		s = s->next;
		b = g_cont_po(s);
		if (a > b)
			return (0);
		a = b;
	}
	return (1);
}
