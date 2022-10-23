/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:53:26 by nwattana          #+#    #+#             */
/*   Updated: 2022/10/23 10:43:21 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int		count_grp(t_list *list);
static void		mt_push_top(t_ms *ms, t_mt *mt, t_prog *prog);
static void		mt_push_bot(t_ms *ms, t_mt *mt, t_prog *prog);
static void		check_state(t_mt *mt, t_prog *prog);

void	a_to_b(t_ms *ms, t_prog *prog)
{
	t_mt	mt;

	mt.c_inb = 0;
	mt.lim = ft_lstsize(prog->ta) - 3;
	while (mt.lim > 0)
	{
		check_state(&mt, prog);
		if (mt.top_a == ms->p_bot)
		{
			mt_push_bot(ms, &mt, prog);
		}
		else if (mt.top_a == ms->p_top)
		{
			mt_push_top(ms, &mt, prog);
		}
		else
		{
			action(ra, prog);
		}
	}
}

static void	mt_push_top(t_ms *ms, t_mt *mt, t_prog *prog)
{
	t_ch	*ch;

	ch = ms->ch;
	action(pb, prog);
	check_state(mt, prog);
	if (mt->c_inb > 1)
		action(rb, prog);
	pushto(1, &ch[ms->p_top]);
	if (ch[ms->p_top].ina == 0)
		ms->p_top--;
	mt->lim--;
}

static void	mt_push_bot(t_ms *ms, t_mt *mt, t_prog *prog)
{
	t_ch	*ch;

	ch = ms->ch;
	action(pb, prog);
	pushto(1, &ch[ms->p_bot]);
	if (ch[ms->p_bot].ina == 0)
		ms->p_bot++;
	mt->lim--;
}

static void	check_state(t_mt *mt, t_prog *prog)
{
	if (prog->ta)
		mt->top_a = g_cont_grp(prog->ta);
	else
		mt->top_a = prog->size + 1;
	if (mt->c_inb < 2)
		mt->c_inb = count_grp(prog->tb);
}

static int	count_grp(t_list *list)
{
	int	grp;
	int	a;

	if (!list)
		return (0);
	a = g_cont_grp(list);
	grp = 1;
	while (list)
	{
		if (a != g_cont_grp(list))
			return (2);
		list = list->next;
	}
	return (grp);
}
