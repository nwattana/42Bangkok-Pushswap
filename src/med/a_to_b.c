/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 23:22:20 by nwattana          #+#    #+#             */
/*   Updated: 2022/10/01 00:20:20 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// move max
int	count_member(int grp, t_list *tb);
void	move_max_ch(t_prog *prog, t_ms *ms);
int	find_first(t_list *temp, int max, int aux);
void	move_max_ch(t_prog *prog, t_ms *ms);

int		lent(int next, t_list *ta);
static void		throw_b(int ind, t_ms *ms, t_prog *prog, int need_rb);
static int		find_next(int high, int low, t_ms *ms, t_prog *prog);
static int		get_high(t_ms *ms);

void	a_to_b(t_ms *ms, t_prog *prog)
{
	int		low;
	int		high;
	int		stop;
	int		tick;

	stop = 0;
	low = 0;
	high = ms->ngrp - 1;
	while (ch_action < high && ft_lstsize(prog->ta) > 2)
	{
		low_t(ch_action, ms, prog);
		high_t(ch_action, ms, prog);
		ch_action++;
		high--;
	}
	move_max_ch(prog, ms);
}

void	low_t(int ch, t_ms *ms, t_prog *prog)
{
}

void	high_t(int ch, t_ms *ms, t_prog *prog)
{

}

void	move_max_ch(t_prog *prog, t_ms *ms)
{
	int	ch_in_b;
	int	aux;
	t_list *temp;
	int	max;
	int	first_index;

	max = ms->ngrp - 1;
	aux = 0;
	temp = prog->tb;
	ch_in_b = count_member(max, temp);
	while (g_cont_grp(temp) == max)
	{
		aux++;
		temp = temp -> next;
	}
	if (aux == ch_in_b)
		return ;
	first_index = find_first(temp, max, aux);
	if (first_index > ft_lstsize(prog->tb) / 2 + 1)
	{
		l_action(rrb, ft_lstsize(prog->tb) - first_index, prog);
	}
	else
	{
		l_action(rb, first_index, prog);
	}
}

int	find_first(t_list *temp, int max, int aux)
{
	int		len;

	len = 0;
	while (temp)
	{
		if (g_cont_grp(temp) == max)
			break;
		len++;
		temp =temp->next;
	}
	return (len);
}

int	count_member(int grp, t_list *tb)
{
	int	member;

	member = 0;
	while (tb)
	{
		if (g_cont_grp(tb) == grp)
			member++;
		tb = tb->next;
	}
	return (member);
}

int		lent(int next, t_list *ta)
{
	int		i;

	i = 0;
	while (ta)
	{
		if (g_cont_po(ta) == next)
		{
			ft_printf("lent = %d\n",i);
			return (i);
		}
		i++;
		ta=ta->next;
	}
	return (-1);
}

// next value we will push
int		find_next(int high, int low, t_ms *ms, t_prog *prog)
{
	int		po;
	t_list *temp;
	int		po1;
	
	po = 0;
	temp = prog->ta;
	while (temp)
	{
		po1 = g_cont_po(temp);
		if (m_inchunk(po1, high, ms) || m_inchunk(po1, low, ms))
		{
			po = po1;
			break;
		}
		temp=temp->next;
	}
	return (po);
}
int		get_high(t_ms *ms)
{
	int	i;

	i = ms->ngrp - 1;
	while (i >= 0)
	{
		if (ms->ch[i].finish_a == 0)
			return (i);
		i--;
	}
	return (0);
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


