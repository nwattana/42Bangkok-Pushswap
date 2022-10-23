/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 11:05:33 by nwattana          #+#    #+#             */
/*   Updated: 2022/10/23 11:50:00 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	cond_merg(t_act act, t_prog *prog);

void	do_acase(t_list *ta, int max, t_prog *prog)
{
	if (g_cont_po(ta) == max)
	{
		if (g_cont_po(ta->next) == max - 1)
		{
			aact_a(sa, prog);
			aact_a(rra, prog);
		}
		else
			aact_a(ra, prog);
	}
	else if (g_cont_po(ta) == max - 2)
	{
		if (g_cont_po(ta->next) == max)
		{
			aact_a(sa, prog);
			aact_a(ra, prog);
		}
	}
	else
	{
		if (g_cont_po(ta->next) == max)
			aact_a(rra, prog);
		else
			aact_a(sa, prog);
	}
}

int	find_max(t_list *lst, int size)
{
	int	temp;

	if (!lst)
		return (0);
	temp = g_cont_po(lst);
	while (lst && size--)
	{
		if (temp < g_cont_po(lst))
				temp = g_cont_po(lst);
		lst = lst->next;
	}
	return (temp);
}

void	merge_act(t_sres *res, t_prog *prog)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (res->sta[i] != none)
	{
		if (res->stb[j] != none && res->sta[i] + 1 == res->stb[j])
		{
			cond_merg(res->stb[j], prog);
			j++;
		}
		else
		{
			action(res->sta[i], prog);
		}
		i++;
	}
	while (res->stb[j] != none)
	{
		action(res->stb[j++], prog);
	}
}

static void	cond_merg(t_act act, t_prog *prog)
{
	if (act == sb)
		action(ss, prog);
	else if (act == rb)
		action(rr, prog);
	else if (act == rrb)
		action(rrr, prog);
}
