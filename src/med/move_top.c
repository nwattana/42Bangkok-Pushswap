/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_top.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 01:41:57 by nwattana          #+#    #+#             */
/*   Updated: 2022/10/23 10:34:38 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	move_top(t_ms *ms, t_prog *prog)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = prog->tb;
	while (temp)
	{
		if (g_cont_grp(temp) == ms->ngrp - 1)
			break ;
		i++;
		temp = temp->next;
	}
	l_action(rb, i, prog);
}
