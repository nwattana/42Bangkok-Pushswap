/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:34:33 by nwattana          #+#    #+#             */
/*   Updated: 2022/10/22 23:51:13 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_inchunk(t_ms *ms, int n)
{
	int	i;

	if (!ms)
		return (-1);
	i = ms->ngrp - 1;
	while (i >= 0)
	{
		if (is_chunk_mem(ms->ch[i], n))
			return (i);
		i--;
	}
	return (-1);
}

int	is_chunk_mem(t_ch ch, int n)
{
	int upper;
	int lower;
	int bol;

	bol = 0;
	upper = ch.upper;
	lower = ch.lower;
	if (n >= lower && n < upper)
			bol = 1;
	return (bol);
}

// a = 1 ta -> tb
// a = 0 tb -> ta
void	pushto(int a, t_ch *ch)
{
	if (!ch)
		return ;
	if (a)
	{
		ch->ina--;
		ch->inb++;
	}
	else
	{
		ch->ina++;
		ch->inb--;
	}
}
