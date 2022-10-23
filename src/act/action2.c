/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 10:35:23 by nwattana          #+#    #+#             */
/*   Updated: 2022/10/23 10:56:20 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	rx_action(t_act act, t_prog *prog);
static void	rrx_action(t_act act, t_prog *prog);
static void	px_action(t_act act, t_prog *prog);
static void	sx_act(t_act act, t_prog *pr);

void	action(t_act act, t_prog *prog)
{
	if (act >= ra && act <= rr)
		rx_action(act, prog);
	else if (act >= sa && act <= ss)
		sx_act(act, prog);
	else if (act >= pa && act <= pb)
		px_action(act, prog);
	else if (act >= rra && act <= rrr)
		rrx_action(act, prog);
	prog->total++;
}

static void	rx_action(t_act act, t_prog *prog)
{
	if (act == ra)
	{
		rx(&prog->ta);
		ft_putstr_fd("ra\n", 1);
	}
	if (act == rb)
	{
		rx(&prog->tb);
		ft_putstr_fd("rb\n", 1);
	}
	else if (act == rr)
	{
		rx(&prog->ta);
		rx(&prog->tb);
		ft_putstr_fd("rr\n", 1);
	}
}

static void	rrx_action(t_act act, t_prog *prog)
{
	if (act == rra)
	{
		rrx(&prog->ta);
		ft_putstr_fd("rra\n", 1);
	}
	if (act == rrb)
	{
		rrx(&prog->tb);
		ft_putstr_fd("rrb\n", 1);
	}
	else if (act == rrr)
	{
		rrx(&prog->ta);
		rrx(&prog->tb);
		ft_putstr_fd("rrr\n", 1);
	}
}

static void	sx_act(t_act act, t_prog *pr)
{
	if (act == sa)
	{
		ft_putstr_fd("sa\n", 1);
		swap(&pr->ta);
	}
	else if (act == sb)
	{
		ft_putstr_fd("sb\n", 1);
		swap(&pr->tb);
	}
	else if (act == ss)
	{
		ft_putstr_fd("ss\n", 1);
		swap(&pr->ta);
		swap(&pr->tb);
	}
}

static void	px_action(t_act act, t_prog *pr)
{
	if (act == pa)
	{
		px(&pr->tb, &pr->ta);
		ft_putstr_fd("pa\n", 1);
	}
	else if (act == pb)
	{
		px(&pr->ta, &pr->tb);
		ft_putstr_fd("pb\n", 1);
	}
}
