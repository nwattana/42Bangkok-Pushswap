/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 23:22:20 by nwattana          #+#    #+#             */
/*   Updated: 2022/09/19 20:52:38 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void		throw_b(int ind, t_ms *ms, t_prog *prog, int need_rb);
static int		min_lf(t_ms *ms, int size, int i);

void	a_to_b(t_ms *ms, t_prog *prog)
{
	int		rotate_b;
	int		chunk_in_b;
	int		chunk_action;

	chunk_in_b = 0;
	while (chunk_in_b < ms->ngrp)
	{
		chunk_action = min_lf(ms, prog->size, 0);
		rotate_b = count_rb(chunk_action, prog, ms);
		throw_b(chunk_action, ms, prog, rotate_b);
		ff_lf_intx(ms, prog->ta, 0);
		chunk_in_b++;
	}
	ft_putstr_fd("last ",1);
	rotate_b = count_rb(chunk_action, prog, ms);
}

static void	throw_b(int ind, t_ms *ms, t_prog *prog, int need_rb)
{
	t_ch	ch;
	int		po;
	int		stop;

	ch = ms->ch[ind];
	stop = ms->ch[ind].m_amount;
	while (prog->ta && stop)
	{
		po = g_cont_po(prog->ta);
		if (po >= ch.low && po < ch.up)
		{
			l_action(rb, need_rb, prog);
			need_rb = 0;
			action(pb, prog);
			stop--;
		}
		else if (need_rb)
		{
			action(rr, prog);
			need_rb--;
		}
		else
		{
			action(ra, prog);
		}
	}
	ms->ch[ind].tob = 1;
}

int		min_lf(t_ms *ms, int size, int i)
{
	int		min;
	int		res_i;

	min = size + 1;
	res_i = -1;
	while (i < ms->ngrp)
	{
		if (!ms->ch[i].tob)
		{
			if (min > ms->ch[i].lf)
			{
				min = ms->ch[i].lf;
				res_i = i;
			}
		}
		i++;
	}
	return (res_i);
}
