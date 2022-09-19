/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:21:31 by nwattana          #+#    #+#             */
/*   Updated: 2022/09/19 20:50:26 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	show_ch_all(t_ch *ch, int size)
{
	int	i;

	i = 0;
	if (!ch)
		return ;
	while (i < size)
	{
		show_ch_i(ch, i);
		ft_putstr_fd("================\n",1);
		i++;
	}
}

void	show_ch_i(t_ch *ch, int i)
{
		ft_printf("ff	%d\n", ch[i].ff);
		ft_printf("lf	%d\n", ch[i].lf);
		ft_printf("rts	%d\n", ch[i].rts);
	
		ft_printf("lower	%d\n", ch[i].low);
		ft_printf("upper	%d\n", ch[i].up);
		ft_printf("index\t	%d\n", ch[i].index);
		ft_printf("m_amount	%d\n", ch[i].m_amount);

		ft_printf("cact	%d\n", ch[i].cact);
		ft_printf("tob	%d\n", ch[i].tob);
		ft_printf("toa	%d\n", ch[i].toa);
		ft_printf("passb	%d\n", ch[i].passb);
		ft_printf("passb	%d\n", ch[i].passa);
}
