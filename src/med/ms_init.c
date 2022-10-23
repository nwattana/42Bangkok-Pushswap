/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 08:33:46 by nwattana          #+#    #+#             */
/*   Updated: 2022/10/23 12:19:09 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_ms	*ms_init(int cs, t_prog *prog)
{
	t_ms	*ms;

	ms = ft_calloc(sizeof(t_ms), 1);
	if (!ms)
		return (NULL);
	ms->last_p = prog->size - 1;
	ms->ngrp = prog->size / cs + (prog->size % cs > 0);
	ms->p_top = ms->ngrp - 1;
	ms->p_bot = 0;
	ms->ch = assign_ch(prog, cs, ms->ngrp);
	return (ms);
}

void	show_ms(t_ms *ms)
{
	ft_printf("last_p %d\n", ms->last_p);
	ft_printf("ngrp %d\n", ms->ngrp);
	ft_printf("p_top %d\n", ms->p_top);
	ft_printf("p_bot %d\n", ms->p_bot);
}

void	show_ms_cs(t_ms *ms)
{
	int	i;

	if (ms == NULL || ms->ch == NULL)
	{
		ft_putstr_fd("Empty\n", 1);
		return ;
	}
	i = 0;
	while (i < ms->ngrp)
	{
		ft_putstr_fd("\t\t===========\n", 1);
		dump_ch(ms->ch[i++]);
	}
}

void	ms_exit(t_ms *ms)
{
	if (!ms)
		return ;
	if (ms->ch)
		free(ms->ch);
	free(ms);
}
