/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ff_lf_inx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:21:56 by nwattana          #+#    #+#             */
/*   Updated: 2022/09/18 14:22:05 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ff_lf_intx(t_ms *ms, t_list *tx, int i)
{
	int		j;
	t_list	*tem;
	int		mem;

	while (i < ms->ngrp)
	{
		j = 0;
		tem = tx;
		mem = ms->ch[i].m_amount;
		while (tem)
		{
			if (inlen_new(g_cont_po(tem), ms->ch[i],mem))
			{
				if (mem == ms->ch[i].m_amount)
					ms->ch[i].ff = j;
				mem--;
				if (!mem)
					ms->ch[i].lf = j;
			}
			j++;
			tem = tem->next;
		}
		i++;
	}
}

