/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 00:06:43 by nwattana          #+#    #+#             */
/*   Updated: 2022/09/23 00:52:05 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/// b_to_a.c

void	little_swap(t_ms *ms, t_prog *prog);
int		item_in_b(int i, t_list *tb);
static int	go_up(int item, int i, t_ms *ms, t_prog *prog);
static int	go_down(int item, int i, t_ms *ms, t_prog *prog);

void	b_to_a(t_ms *ms, t_prog *prog)
{
	int		i;
	int		item;

	little_swap(ms, prog);
	i = ms->ngrp - 1;
	while (i >= 0)
	{
		item = item_in_b(i, prog->tb);
		while (item > 0)
		{
			item -= go_up(item, i, ms, prog);
			item -= go_down(item, i, ms, prog);
		}
		i--;
	}
//dump_p(prog);
}

int	go_up(int item, int i, t_ms *ms, t_prog *prog)
{
	int		total;
	int		topa;
	int		topb;

	total = 0;
	while (item > 0)
	{
		topa = g_cont_po(prog->ta);
		topb = g_cont_po(prog->tb);
		if (topa - topb == 1) 
		{
			action(pa, prog);
			item--;
			total++;
		}
		else if (item - ms->ch[i].passb > 0)
		{
			action(rb, prog);
			ms->ch[i].passb++;
		}
		if (item - ms->ch[i].passb < 1)
			break;
	}
	return (total);
}

int		go_down(int item, int i, t_ms *ms, t_prog *prog)
{
	int total;
	int topa;
	int topb;

	total = 0;
	while (item > 0 && ms->ch[i].passb > 0)
	{
		topa = g_cont_po(prog->ta);
		topb = g_cont_po(prog->tb);
	//	ft_printf("\t\ttop A %d: top B %d\n", topa, topb);
		if (topa - topb == 1)
		{
			action(pa, prog);
			item--;
			total++;
		}
		action(rrb, prog);
		ms->ch[i].passb--;
	}
	return (total);
}

// input index -- return amount of that index in tb
int		item_in_b(int i, t_list *tb)
{
	int		item;

	item = 0;
	while (tb && g_cont_grp(tb) == i)
	{
		item += (g_cont_grp(tb) == i);
		tb = tb->next;
	}
	return (item);
}

void	little_swap(t_ms *ms, t_prog *prog)
{
	int		topa;
	int		topb;
	int		ftopa;
	int		ftopb;

	topa = g_cont_po(prog->ta);
	topb = g_cont_po(prog->tb);
	ftopa = g_cont_po(prog->ta->next);
	ftopb = g_cont_po(prog->tb->next);
	if (topa > ftopa)	
	{
		if (topb < ftopb)
			action(ss, prog);
		else
			action(sa, prog);
	}
}
