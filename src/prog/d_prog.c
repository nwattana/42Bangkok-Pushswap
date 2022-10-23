/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_prog.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:23:39 by nwattana          #+#    #+#             */
/*   Updated: 2022/10/23 11:00:24 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	dump_prog(t_prog *p)
{
	ft_printf("size : %d\n", p->size);
	if (p->error)
		ft_printf("\033[31merror : %d\033[39m\n", p->error);
	ft_printf("error : %d\n", p->error);
	ft_printf("stack_a : ");
	dump_position(p->ta);
	ft_printf("stack_b : ");
	dump_position(p->tb);
}

void	dump_g_all(t_prog *p)
{
	ft_putstr_fd("TA: ", 1);
	dump_grp(p->ta);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("TB: ", 1);
	dump_grp(p->tb);
	ft_putchar_fd('\n', 1);
}

void	dump_node(t_list *st)
{
	if (!st)
		return ;
	ft_printf("PO : %d\n", g_cont_po(st));
	ft_printf("Value : %d\n", g_cont_data(st));
	ft_printf("grp : %d\n", g_cont_grp(st));
}

void	dump_grp(t_list *st)
{
	if (!st)
	{
		ft_putstr_fd("Empty\n", 1);
		return ;
	}
	while (st)
	{
		ft_printf("%d => ", g_cont_grp(st));
		st = st->next;
	}
}

void	dump_position(t_list *st)
{
	if (!st)
	{
		ft_putstr_fd("Empty\n", 1);
		return ;
	}
	while (st)
	{
		ft_printf("%d", g_cont_po(st));
		if (st->next != NULL)
			ft_putstr_fd("->", 1);
		st = st->next;
	}
	ft_putchar_fd('\n', 1);
}
