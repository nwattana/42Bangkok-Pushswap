/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_prog.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:23:39 by nwattana          #+#    #+#             */
/*   Updated: 2022/09/03 17:23:42 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	dump_p(t_prog *p)
{
	ft_printf("size : %d\n", p->size);
	if (p->error)
		ft_printf("\033[31merror : %d\033[39m\n", p->error);
	ft_printf("error : %d\n", p->error);
	ft_printf("stack_a :");
	dump_s(p->ta);
	ft_printf("stack_b :");
	dump_s(p->tb);
}

void	dump_s(t_list *st)
{
	while (st)
	{
		ft_printf("%d",g_cont_po(st));
		if (st->next != NULL)
			ft_putstr_fd("->", 1);
		st = st->next;
	}
	ft_putchar_fd('\n', 1);
}
