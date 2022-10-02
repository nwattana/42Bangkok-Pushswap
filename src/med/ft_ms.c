/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 20:25:13 by nwattana          #+#    #+#             */
/*   Updated: 2022/09/29 17:58:36 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_ms	*init_ms(int size, int cs)
{
	t_ms	*res;
	int	ng;

	res = malloc(sizeof(t_ms));
	if (!res)
		return (NULL);
	res->csi = cs;
	ng = size / cs + (size % cs != 0);
	res->ngrp = ng;
	res->ch = ft_calloc(sizeof(t_ch), ng);
	res->bo = ft_calloc(sizeof(int), ng);
	res->ata = ft_calloc(sizeof(int), size);
	res->atb = ft_calloc(sizeof(int), size);
	if (!res->bo || !res->ata || !res->atb)
	{
		clear_ms(res);
		return (NULL);
	}
	return (res);
}

int		m_inchunk(int i, int c_ind, t_ms *ms)
{
	t_ch	ch;

	ch = ms->ch[c_ind];
	if (c_ind == ms->ngrp)
		return (i >= ch.low && i < ch.up - 1);
	return (i >= ch.low && i < ch.up);
}

void	clear_ms(t_ms *ms)
{
	if (!ms)
		return ;
	if (ms->bo)
		free(ms->bo);
	if (ms->ata)
		free(ms->ata);
	if (ms->atb)
		free(ms->atb);
	free(ms);
}
