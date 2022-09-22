/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 00:06:43 by nwattana          #+#    #+#             */
/*   Updated: 2022/09/23 01:37:54 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/// b_to_a.c

void	little_swap(t_ms *ms, t_prog *prog);
int		item_in_b(int i, t_list *tb);
static int	go_up(int item, int i, t_ms *ms, t_prog *prog);
static int	go_down(int item, int i, t_ms *ms, t_prog *prog);
int	direction(int item, int a, t_ch ch, t_list *ta);

void	b_to_a(t_ms *ms, t_prog *prog)
{
	int		i;
	int		item;
	int		drt;

	little_swap(ms, prog);
	i = ms->ngrp - 1;
	while (i >= 0)
	{
		item = item_in_b(i, prog->tb);
		while (item > 0)
		{
			drt = direction(item, g_cont_po(prog->ta) - 1, ms->ch[i], prog->tb);
		//ft_printf("top A %d top B %d drt %d\n",g_cont_po(prog->ta), g_cont_po(prog->tb), drt);
		//	dump_p(prog);
		//	ft_putstr_fd("\n\n\n", 1);
		///	usleep(3000000);
			if (drt >= 0)
				item -= go_up(item, i, ms, prog);
			else
				item -= go_down(item, i, ms, prog);
		}
		i--;
	}
}


int	direction(int item, int a, t_ch ch, t_list *ta)
{
	int	di;
	int	i;
	int	remain;

	i = 0;
	remain = item - ch.passb;
	while (ta)
	{
		if (g_cont_po(ta) == a)
			break;
		ta = ta->next;
		i++;
	}
//	ft_printf("i=%d remain %d\n",i , remain);
	if (i == 0)
		return (0);
	else if (i <= remain)
		return (1);
	else
		return (-1);
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
			break;
		}
		else if (item - ms->ch[i].passb > 0)
		{
			action(rb, prog);
			ms->ch[i].passb++;
		}
		if (item - ms->ch[i].passb <= 1)
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
	//while (item > 0 && ms->ch[i].passb > 0)
	topa = g_cont_po(prog->ta);
	while (item > 0 && ms->ch[i].passb > 0)
	{
		topb = g_cont_po(prog->tb);
		if (topa - topb == 1)
		{
			action(pa, prog);
			item--;
			total++;
		}
		else
		{
			action(rrb, prog);
			ms->ch[i].passb--;
		}
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
