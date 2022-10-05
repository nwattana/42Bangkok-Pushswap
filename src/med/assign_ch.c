/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_ch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 08:33:12 by nwattana          #+#    #+#             */
/*   Updated: 2022/10/06 02:20:07 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_ch *assign_ch(t_prog *prog, int cs, int ngrp)
{
	t_ch *ch;
	int		i;

	ch = ft_calloc(sizeof(t_ch), ngrp);
	if (!ch)
		return (NULL);
	i = 0;
	while (i < ngrp)
	{
		ch[i].index = i;
		ch[i].lower = cs * (i);
		ch[i].upper = cs * (i + 1);
		if (i == 0)
			ch[i].lower = 1;
		if (i == ngrp - 1)
			ch[i].upper = prog->size;
			if (ch[i].upper < ch[i].lower)
				ch[i].lower = ch[i].upper;
		ch[i].size = ch[i].upper - ch[i].lower;
		ch[i].ina = ch[i].size;
		i++;
	}
	return (ch);
}

void	dump_ch(t_ch ch)
{
	ft_printf("index\t%d\n",ch.index);
	ft_printf("lower\t%d\n",ch.lower);
	ft_printf("upper\t%d\n",ch.upper);
	ft_printf("size\t%d\n",ch.size);
	ft_printf("ina\t%d\n",ch.ina);
	ft_printf("inb\t%d\n",ch.inb);
	ft_printf("PassB\t%d\n",ch.passb);
	ft_printf("PassA\t%d\n",ch.passa);
}
