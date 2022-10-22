/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:51:26 by nwattana          #+#    #+#             */
/*   Updated: 2022/10/22 22:09:53 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
void	b_to_a(t_ms *ms, t_prog *prog);
void	temp_swap_top(t_prog *prog);
void	add_grp(t_prog *prog, t_ms *ms);
void	mtb_push(t_ms *ms, t_prog *prog, t_mtb *mtb);
int		get_dir(t_mtb *mtb, t_prog *prog);
void	check_state(t_mtb *mtb, t_prog *prog);

void	medium(int cs, t_prog *prog)
{
	prog->ms = ms_init(cs, prog);
	if (!prog->ms)
		return ;
	add_grp(prog, prog->ms);
	a_to_b(prog->ms, prog);
	move_top(prog->ms, prog);
//	dump_g_all(prog);
//	temp_swap_top(prog); /// wait for change to sort 3 if enough time
//	dump_prog(prog);
//	b_to_a(prog->ms, prog);
	//dump_prog(prog);
}

void	temp_swap_top(t_prog *prog)
{
	int		mode;

	mode = 0;
	if (g_cont_po(prog->ta) == prog->size)
	{
		action(sa, prog);
	}
}

void	add_grp(t_prog *prog, t_ms *ms)
{
	t_list 	*list;

	list = prog->ta;
	while (list)
	{
		*ga_cont_grp(list) = is_inchunk(ms, g_cont_po(list));
		list = list->next;
	}
}

void	b_to_a(t_ms *ms, t_prog *prog)
{
//
//	ft_putstr_fd("\nLet Put its back\n\n", 1);
//
	t_mtb	mtb;

// init
	mtb.lim = ft_lstsize(prog->tb);
	mtb.active_ch = ms->ngrp - 1;
	mtb.dir = 0;
// shorter

	check_state(&mtb, prog);
	while (mtb.lim > 0)
	{
		check_state(&mtb, prog);
		mtb.dir = get_dir(&mtb, prog);
		if (mtb.top_a - 1 == mtb.top_b && mtb.lim)
			mtb_push(ms, prog, &mtb);
		else if (mtb.dir && mtb.lim)
		{
			action(rb, prog);
		}
		else if (!mtb.dir && mtb.lim)
		{
			action(rrb, prog);
		}
		else
		{
			ft_printf("dir:%d\n",mtb.dir);
		}
	}
}

int get_dir(t_mtb *mtb, t_prog *prog)
{
	int	lim;
	t_list *temp;

// shorter
	t_ch ch;
	ch = prog->ms->ch[mtb->active_ch];
	
	temp = prog->tb;
	lim = ch.inb - ch.passb;
	if (ch.inb == 0)
		return (1);
	while (lim-- && temp)
	{
		if (mtb->top_a - 1 == g_cont_po(temp))
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	mtb_push(t_ms *ms, t_prog *prog, t_mtb *mtb)
{
	t_ch *ch;

	action(pa, prog);
	ch = ms->ch;
	mtb->lim--;
	pushto(0, &ch[mtb->active_ch]);

}

void	check_state(t_mtb *mtb, t_prog *prog)
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


