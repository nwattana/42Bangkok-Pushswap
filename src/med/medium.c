/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:51:26 by nwattana          #+#    #+#             */
/*   Updated: 2022/10/23 00:47:33 by nwattana         ###   ########.fr       */
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
//	temp_swap_top(prog); /// wait for change to sort 3 if enough time
//	dump_prog(prog);
//	b_to_a(prog->ms, prog);
//	dump_g_all(prog);
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
