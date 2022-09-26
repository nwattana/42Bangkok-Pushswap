/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 23:22:20 by nwattana          #+#    #+#             */
/*   Updated: 2022/09/27 00:01:40 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void		throw_b(int ind, t_ms *ms, t_prog *prog, int need_rb);

void	a_to_b(t_ms *ms, t_prog *prog)
{
	int		rotate_b;
	int		chunk_action;
	int		i;

	i = 0;
	while (i < ms->ngrp && ft_lstsize(prog->ta) > 2)
	{
		chunk_action = i;
		rotate_b = count_rb(chunk_action, prog, ms);
		throw_b(chunk_action, ms, prog, rotate_b);
		ff_lf_intx(ms, prog->ta, 0);
		i++;
	}
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
			action(ra, prog);
	}
	ms->ch[ind].tob = 1;
}
