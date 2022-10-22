/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 00:23:39 by nwattana          #+#    #+#             */
/*   Updated: 2022/10/23 00:37:05 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

static int	findmax_po(t_list *lst);

void	sort_3(t_prog *prog)
{
	int		max;

	max = findmax_po(prog->ta);
	if (g_cont_po(prog->ta) == max)
		action(ra, prog);
	if (g_cont_po(prog->ta) == max - 1)
	{
		if (g_cont_po(prog->ta->next) == max)
			action(rra, prog);
		else if (g_cont_po(prog->ta->next) == max - 2)
			action(sa, prog);	
	}
	else if (g_cont_po(prog->ta) == max - 2)
	{
		if (g_cont_po(prog->ta->next) == max)
		{
			action(rra, prog);
			action(sa, prog);
		}
	}
}

static int	findmax_po(t_list *lst)
{
	int max;
	int lim;

	max = -1;
	lim = 3;
	while (lst && lim--)
	{	
		if (g_cont_po(lst) > max)
			max = g_cont_po(lst);
		lst = lst->next;
	}
	return (max);
}
