/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:33:04 by nwattana          #+#    #+#             */
/*   Updated: 2022/09/16 18:02:47 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
void	add_grp(t_ms *ms, t_prog *prog);
int		in_ch(int po, t_ms *ms);
void	boundery(int size, t_ch *ch, int *bo);
void	update_ch(t_ms *ms, t_prog *prog);;
int		inlen_new(int i, t_ch ch, int found);
void	ff_lf_intx(t_ms *ms, t_list *list, int i);
int		min_lf(t_ms *ms, int a, int b);
void	throw_b(int min, t_ms *ms, t_prog *prog);

void	medium(t_prog *prog)
{
	int		cs;
	t_ms	*ms;
	int min_i;

	cs = prog->size / 4;
	ms = init_ms(prog->size , cs);
	prog->ms = ms;
	if (!prog->ms)
		prog->error = 1;
	if (!prog->error)
	{
		creat_bo(ms, cs, prog->size);
	//	put_aint(ms->bo, ms->ngrp); // put array int
		update_ch(ms, prog);
	//	show_ch_all(ms->ch, ms->ngrp); // put array int
		int	need_rb;
		int te;

		te = 0;
		while (te < ms->ngrp)
		{
			min_i = min_lf(ms, prog->size, 0);
			throw_b(min_i, ms, prog);
			ff_lf_intx(ms, prog->ta, 0);
			te++;
		//	ft_printf("min_i = %d\n", min_i);
		}
	}
}

void	throw_b(int ind, t_ms *ms, t_prog *prog)
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
			action(pb, prog);
			stop--;
		}
		else
		{
			action(ra, prog);
		}
	}
	ms->ch[ind].tob = 1;
}

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

int		min_lf(t_ms *ms, int size, int i)
{
	int	min;
	int	res_i;

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

void	ff_lf_intx(t_ms *ms, t_list *tx, int i)
{
	int		j;
	t_list	*tem;
	int		mem;

	while (i < ms->ngrp)
	{
		j = 0;
		tem = tx;
		mem = ms->ch[i].m_amount;
		while (tem)
		{
			if (inlen_new(g_cont_po(tem), ms->ch[i],mem))
			{
				if (mem == ms->ch[i].m_amount)
					ms->ch[i].ff = j;
				mem--;
				if (!mem)
					ms->ch[i].lf = j;
			}
			j++;
			tem = tem->next;
		}
		i++;
	}
}

int		inlen_new(int i, t_ch ch, int founded)
{
	return (i >= ch.low && i < ch.up);
}

void	boundery(int size, t_ch *chi, int *bo)
{
	int		i;

	i = 1;
	if (!chi || !bo)
		return ;
	chi[0].low = 1;
	chi[0].up = bo[0];
	chi[0].m_amount = bo[0] - 1;
	while (i < size)
	{
		chi[i].index = i;
		chi[i].m_amount = bo[i] - bo[i-1];
		chi[i].up = bo[i];
		chi[i].low = bo[i - 1];
		i++;
	}
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
	//ft_printf("res->ngrp %d\n", res->ngrp);
	res->ch = ft_calloc(sizeof(t_ch), ng);

	res->bo = ft_calloc(sizeof(int), ng);
	res->ata = ft_calloc(sizeof(int), size);
	res->atb = ft_calloc(sizeof(int), size);
	if (!res->bo || !res->ata || !res->atb)
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
	if (ms->ata)
		free(ms->ata);
	if (ms->atb)
		free(ms->atb);
	free(ms);
}
