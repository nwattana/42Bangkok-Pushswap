/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:53:26 by nwattana          #+#    #+#             */
/*   Updated: 2022/10/06 02:21:07 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	a_to_b(t_ms *ms, t_prog *prog)
{
	int stop;
	int	now;
	int	trig;

	trig = 0;
	while (ft_lstsize(prog->ta) > 1)
	{
		now = g_cont_grp(prog->ta);
		if (now == ms->p_top)
		{
			trig++;
			action(pb, prog);
			ms->ch[now].ina--;
			ms->ch[now].inb++;
		}
		else if (now == ms->p_bot)
		{
			while (trig > 0)
			{
				action(rb, prog);
				trig--;
			}
			action(pb, prog);
			ms->ch[now].ina--;
			ms->ch[now].inb++;
		}
		else
		{
			if (trig > 0)
			{
				action(rr,prog);
				trig--;
			}	
			else
				action(ra, prog);
		}
		if (ms->ch[ms->p_top].ina == 0)
			ms->p_top--;
		if (ms->ch[ms->p_bot].ina == 0)
			ms->p_bot++;
	//	ft_printf("top %d bot %d now %d\n",ms->p_top, ms->p_bot, now);
	//	ft_printf("size %d ina %d now %d\n",ms->ch[now].size, ms->p_bot, now);
	}
}

