
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:33:04 by nwattana          #+#    #+#             */
/*   Updated: 2022/09/08 00:01:21 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/// chunksize = 10;
void	medium(t_prog *prog)
{

	int		cs;
	t_ms	*ms;

	cs = 8;
	// initer sorter m - mem
	ms = init_ms(prog->size , cs);
	prog->ms = ms;
	if (!prog->ms)
		prog->error = 1;
	if (!prog->error)
	{
		creat_bo(ms, cs, prog->size);
		put_aint(ms->bo, ms->ngrp);
		put_chunk(prog, ms);
	}
}

void	put_chunk(t_prog *prog, t_ms *ms)
{
	int	i;
	int	size_b;

	i = 0;
	while (i < ms->ngrp)
	{
		ft_printf("chunk no. %d\n", i);
		size_b = ms->csi * (i + 1) - 1;
		while (ft_lstsize(prog->tb) < size_b\
				&& ft_lstsize(prog->ta) > 3)
		{
			if (inlen(prog, ms, i))
				action(pb, prog);
			if (i == 0 && 
				g_cont_po(ft_lstlast(prog->tb)) != 1)
				action(rr,prog);
			else
				action(ra, prog);
		}
		i++;
	}
}

int	inlen(t_prog *pr, t_ms *ms, int ind)
{
	int	up;
	int low;
	int	num;

	num = g_cont_po(pr->ta);
	if (ind == 0)
		low = 1;
	else
		low = ms->bo[ind - 1];
	up = ms->bo[ind];
	return (num >= low && num < up);
}


void	update_arr(t_list *ta, t_list *tb, t_ms *ms)
{
	int		i;

	i = 0;
	while (ta)
	{
		ms->ata[i] = g_cont_po(ta);
		ta = ta->next;
		i++;
	}
	ms->size_a = i;
	i = 0;
	while (tb)
	{
		ms->atb[i] = g_cont_po(tb);
		tb = tb->next;
		i++;
	}
	ms->size_b = i;
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

t_ms	*init_ms(int size, int cs)
{
	t_ms	*res;
	int	ng;

	res = malloc(sizeof(t_ms));
	if (!res)
		return (NULL);
	res->csi = cs;
	ng = size / cs + (size % cs != 0);
	res->ngrp = ng;
	ft_printf("res->ngrp %d\n", res->ngrp);
	res->bo = ft_calloc(sizeof(int) , ng);
	res->way = ft_calloc(sizeof(int) , ng);
	res->ata = ft_calloc(sizeof(int) , size);
	res->atb = ft_calloc(sizeof(int) , size);
	if (!res->bo || !res->way || !res->ata || !res->atb)
	{
		clear_ms(res);
		return (NULL);
	}
	return (res);
}

void	clear_ms(t_ms *ms)
{
	if (!ms)
		return ;
	if (ms->bo)
		free(ms->bo);
	if (ms->way)
		free(ms->way);
	if (ms->to_f)
		free(ms->to_f);
	if (ms->ata)
		free(ms->ata);
	if (ms->atb)
		free(ms->atb);
	free(ms);
}
