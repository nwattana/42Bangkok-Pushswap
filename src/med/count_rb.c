/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_rb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:23:12 by nwattana          #+#    #+#             */
/*   Updated: 2022/09/20 01:57:52 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int max_ch(t_ms *ms);
static int min_ch(t_ms *ms);
static int	b_size(t_ms *ms);

int	count_rb(int ind, t_prog *prog, t_ms *ms)
{
	int		res;

	res = 0;
	if (ind > max_ch(ms) && ind < min_ch(ms))
	{
		res = movemax_top(ms);
	}
	else
	{
		res = movemiddle_top(ms, prog);
	}
	return (res);
}

// to b = 1 if in b
// mx index that to b = 1
static int max_ch(t_ms *ms)
{
	int		i;
	int		max;

	max = -1;
	i = 0;
	while (i < ms->ngrp)
	{
		if (ms->ch[i].tob == 1)
		{
			if (i > max)
				max = i;
		}
		i++;
	}
	show_ch_all(ms->ch, ms->ngrp);
	return (max);
}

static int min_ch(t_ms *ms)
{
	int		i;
	int		min;

	min = ms->ngrp + 1;
	i = 0;
	while (i < ms->ngrp)
	{
		if (ms->ch[i].tob == 1)
			return (i);
		i++;
	}
	return (-1);
}

static int	b_size(t_ms *ms)
{
	int res;
	int	i;

	i = 0;
	res = 0;
	while (i < ms->ngrp)
	{
		if (ms->ch[i].tob == 1 && ms->ch[i].toa == 0)
		{
			res += ms->ch[i].m_amount;
		}
		i++;
	}
	return (res);
}
