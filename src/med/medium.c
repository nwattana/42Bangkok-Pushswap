/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:33:04 by nwattana          #+#    #+#             */
/*   Updated: 2022/09/22 23:52:00 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
void	update_ch(t_ms *ms, t_prog *prog);;
void	add_grp(t_ms *ms, t_prog *prog);
void	b_to_a(t_ms *ms, t_prog *prog);
int		in_ch(int po, t_ms *ms);

void	medium(t_prog *prog)
{
	int		cs;
	t_ms	*ms;

	cs = 11;
	ms = init_ms(prog->size , cs);
	prog->ms = ms;
	if (!prog->ms)
		prog->error = 1;
	if (!prog->error)
	{
		creat_bo(ms, cs, prog->size);
		update_ch(ms, prog);
		a_to_b(ms, prog);
		b_to_a(ms, prog);
	}
}

/// b_to_a.c

void	little_swap(t_ms *ms, t_prog *prog);
int		item_in_b(int i, t_list *tb);
void	b_to_a(t_ms *ms, t_prog *prog)
{
	int		i;
	int		item;
	int		topa;
	int		topb;
	int		wait;
	int		rev;
	int		stop;

	little_swap(ms, prog);
	i = ms->ngrp - 1;
	wait = 0;
	rev = 0;
	while (i >= 0)
	{
		item = item_in_b(i, prog->tb);
		while (item > 0)
		{
			topa = g_cont_po(prog->ta);
			topb = g_cont_po(prog->tb);

			if (topa - topb == 1) 
			{
				action(pa, prog);
				item--;
			}
			else if (item - ms->ch[i].passb > 0)
			{
				action(rb, prog);
				ms->ch[i].passb++;
			}
			else if (item - ms->ch[i].passb <= 0)
			{
				l_action(rrb, ms->ch[i].passb,prog);
				ms->ch[i].passb = 0;
			}
		}
		i--;
	}
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
//	ft_printf("A top %d  %d\nb top %d  %d\n", topa, ftopa, topb, ftopb);

}

//// end of b_to_a
void	update_ch(t_ms *ms, t_prog *prog)
{
	int		i;

	if (!ms || !prog)
		return ;
	boundery(ms->ngrp, ms->ch, ms->bo);
	ff_lf_intx(ms, prog->ta, 0);
	add_grp(ms, prog);
}

void	add_grp(t_ms *ms, t_prog *prog)
{
	t_list *temp;
	int	in;

	temp = prog->ta;
	while (temp)
	{
		in = in_ch(g_cont_po(temp), ms);
		*ga_cont_grp(temp) = in_ch(g_cont_po(temp), ms);
		temp = temp -> next;
	}
}

int	in_ch(int po, t_ms *ms)
{
	int	i;

	i = 0;
	while (i < ms->ngrp)
	{
		if (po >= ms->ch[i].low && po < ms->ch[i].up)
			return (i);
		i++;
	}
	return (-1);
}

void	creat_bo(t_ms *ms, int cs, int size)
{
	int		i;

	i = 0;
	while (i < ms->ngrp)
	{
		ms->bo[i] = cs * (i + 1);
		i++;
	}
	i--;
	if (ms->bo[i] > size)
		ms->bo[i] = size;
}
