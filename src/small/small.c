/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 08:26:14 by nwattana          #+#    #+#             */
/*   Updated: 2022/10/23 11:05:06 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	small(t_prog *prog)
{
	prog->sres = init_sres();
	if (!prog->sres)
			prog->error = 1;
	if (!prog->error)
	{
		add_sep(prog);
		ssort_a(ft_lstsize(prog->ta), prog);
		ssort_b(ft_lstsize(prog->tb), prog);
		merge_act(prog->sres, prog);
		while (ft_lstsize(prog->tb))
			action(pa, prog);
	}
}

void	add_sep(t_prog *prog)
{
	int		middle;

	middle = prog->size / 2;
	while (ft_lstsize(prog->tb) != middle)
	{
		if (g_cont_po(prog->ta) <= middle)
			action(pb, prog);
		else
			action(ra, prog);
	}
}

void	ssort_b(int size, t_prog *prog)
{
	int	max;

	if (size == 2)
	{
		if (g_cont_po(prog->tb) < g_cont_po(prog->tb->next))
			aact_b(sb, prog);
	}
	else
	{
		max = find_max(prog->tb, ft_lstsize(prog->tb));
		do_bcase(prog->tb, max, prog);
	}
	aact_b(none, prog);
}

void	do_bcase(t_list *tb, int max, t_prog *prog)
{
	if (g_cont_po(tb) == max)
	{
		if (g_cont_po(tb->next) == max - 2)
		{
			aact_b(sb, prog);
			aact_b(rb, prog);
		}
	}
	else if (g_cont_po(tb) == max - 1)
	{
		if (g_cont_po(tb->next) == max - 2)
			aact_b(rrb, prog);
		else
			aact_b(sb, prog);
	}
	else
	{
		if (g_cont_po(tb->next) == max - 1)
		{
			aact_b(sb, prog);
			aact_b(rrb, prog);
		}
		else
			aact_b(rb, prog);
	}
}

void	ssort_a(int size, t_prog *prog)
{
	int	max;

	if (size == 2)
	{
		if (g_cont_po(prog->ta) > g_cont_po(prog->ta->next))
			aact_a(sa, prog);
	}
	else
	{
		max = find_max(prog->ta, ft_lstsize(prog->ta));
		do_acase(prog->ta, max, prog);
	}
	aact_a(none, prog);
}
