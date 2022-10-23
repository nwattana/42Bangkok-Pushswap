/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 22:23:19 by nwattana          #+#    #+#             */
/*   Updated: 2022/10/23 10:05:26 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

static void		mtb_push(t_ms *ms, t_prog *prog, t_mtb *mtb);
static void		mtb_push_hold(t_ms *ms, t_prog *prog, t_mtb *mtb);
static void		check_state(t_mtb *mtb, t_prog *prog);
int				get_dir(t_mtb *mtb, t_prog *prog);
int		check_free_s(t_prog *prog);

void	b_to_a(t_ms *ms, t_prog *prog)
{
	t_mtb	mtb;
	t_ch	*ch;

	mtb.lim = ft_lstsize(prog->tb);
	mtb.active_ch = ms->ngrp - 1;
	mtb.dir = 0;
	ch = prog->ms->ch;
	check_state(&mtb, prog);
	while (mtb.lim > 0)
	{
		check_state(&mtb, prog);
		mtb.dir = get_dir(&mtb, prog);
		if (mtb.top_a - 1 == mtb.top_b && mtb.lim)
			mtb_push(ms, prog, &mtb);
		else if (mtb.dir)
		{
			action(rb, prog);
		}
		else if (!mtb.dir)
		{
			action(rrb, prog);
		}
		else
			ft_printf("dir%d\n", mtb.dir);
	}
}

int	get_dir(t_mtb *mtb, t_prog *prog)
{
	int			lim;
	t_list		*temp;
	t_ch		ch;
	int		find;

	lim = 0;
	ch = prog->ms->ch[mtb->active_ch];
	temp = prog->tb;
	find = mtb->top_a - 1;
	while (g_cont_po(temp) != find && temp)
	{
		temp = temp->next;
		lim++;
	}
	ft_printf("%d %d\n", ch.inb, lim);
	if (lim < ch.inb)
		return (1);
	return (0);
}

static void	mtb_push_hold(t_ms *ms, t_prog *prog, t_mtb *mtb)
{
	t_ch *ch;

	action(pa, prog);
	ch = ms->ch;
	mtb->lim--;
	pushto(0, &ch[mtb->active_ch]);
}

static void	mtb_push(t_ms *ms, t_prog *prog, t_mtb *mtb)
{
	t_ch	*ch;

	action(pa, prog);
	ch = ms->ch;
	mtb->lim--;
	pushto(0, &ch[mtb->active_ch]);
}

static void	check_state(t_mtb *mtb, t_prog *prog)
{
	if (prog->ta)
		mtb->top_a = g_cont_po(prog->ta);
	else
		mtb->top_b = prog->size + 1;
	if (prog->tb)
		mtb->top_b = g_cont_po(prog->tb);
	else
		mtb->top_b = prog->size + 1;
	if (prog->ms->ch[mtb->active_ch].inb == 0 && mtb->active_ch > 0)
		mtb->active_ch--;
}
