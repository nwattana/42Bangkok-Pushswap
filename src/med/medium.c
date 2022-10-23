/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:51:26 by nwattana          #+#    #+#             */
/*   Updated: 2022/10/23 09:51:31 by nwattana         ###   ########.fr       */
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
	ft_putstr_fd("Move top\n", 1);
	move_top(prog->ms, prog);
	ft_putstr_fd("Sort 3\n", 1);
	sort_3(prog);
	ft_putstr_fd("B_to_A\n",1);
	b_to_a(prog->ms, prog);
	dump_g_all(prog);
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
