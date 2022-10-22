/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:53:26 by nwattana          #+#    #+#             */
/*   Updated: 2022/10/22 22:13:16 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	a_to_b(t_ms *ms, t_prog *prog)
{
	int	now;
	t_aux *ax;

	ax = init_aux();
	if (!ax)
	{
		prog->error = 1;
		return ;
	}
	while (ft_lstsize(prog->ta) > 2)
	{
		now = g_cont_grp(prog->ta);
		if (now == ms->p_top && !ax->tog1)
		{
			ax->xtrig++;
			action(pb, prog);
			pushto(1, &(ms->ch[now]));
		}
		else if (now == ms->p_bot && !ax->tog2)
		{
			while (ax->xtrig > 0)
			{
				action(rb, prog);
				ax->xtrig--;
			}
			action(pb, prog);
			pushto(1, &(ms->ch[now]));
		}
		else
		{
			if (ax->xtrig > 0)
			{
				action(rr,prog);
				ax->xtrig--;
			}	
			else
				action(ra, prog);
		}
		ax_tog((ms->ch[ms->p_top].ina == 0), 1, ax);
		ax_tog((ms->ch[ms->p_bot].ina == 0), 2, ax);
		if (ax->tog1 && ax->tog2)
		{
			ms->p_top--;
			ms->p_bot++;
			if (ms->p_top == ms->p_bot)
				ms->p_top = ms->ngrp + 1;
			ax_retog(ax);
		}
	}
	free(ax);
}

