/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:51:26 by nwattana          #+#    #+#             */
/*   Updated: 2022/10/23 12:19:06 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	temp_swap_top(t_prog *prog);
void	add_grp(t_prog *prog, t_ms *ms);

void	medium(int cs, t_prog *prog)
{
	prog->ms = ms_init(cs, prog);
	if (!prog->ms)
		return ;
	add_grp(prog, prog->ms);
	a_to_b(prog->ms, prog);
	move_top(prog->ms, prog);
	sort_3(prog);
	b_to_a(prog->ms, prog);
	ms_exit(prog->ms);
}

void	add_grp(t_prog *prog, t_ms *ms)
{
	t_list		*list;
	int			po;
	int			*g_add;

	list = prog->ta;
	while (list)
	{
		po = g_cont_po(list);
		g_add = ga_cont_grp(list);
		*g_add = is_inchunk(ms, po);
		list = list->next;
	}
}
