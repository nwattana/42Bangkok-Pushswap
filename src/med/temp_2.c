/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_rb_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 01:55:56 by nwattana          #+#    #+#             */
/*   Updated: 2022/09/21 23:43:33 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	findlower_max(int a, t_ms *ms);
static int	findfirst(int bo, t_list *tx);

int		movemax_top(int	max, t_ms *ms, t_prog *prog)
{
	int		res;
	t_list	*temp;
	int		first;

	res = 0;
	if (!prog->tb)
		return (0);
	first = findfirst(max, prog->tb);
	res = first;
	return (res);
}


int		movemid_top(int mid, t_ms *ms, t_prog *prog)
{
	int		res;
	int		next;

	res = 0;
	if (!prog->tb)
		return (0);
	next = findlower_max(mid, ms);
	res = findfirst(next, prog->tb);
	return (res);
}

static int	findfirst(int bo, t_list *tx)
{
	int		i;
	t_list	*temp;

	temp = tx;
	i = 0;
	while (temp)
	{
		if (g_cont_grp(temp) == bo)
			return (i);
		temp = temp->next;
		i++;
	}
	return (i);
}

static int	findlower_max(int a, t_ms *ms)
{
	int		i;

	i = ms->ngrp - 1;
	while (i > 0)
	{
		if (ms->ch[i].tob == 1)
		{
			if ( i < a)
				return (i);
		}
		i--;
	}
	return (i);
}
