/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:33:04 by nwattana          #+#    #+#             */
/*   Updated: 2022/09/15 16:01:23 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/// chunksize = 10;
void	medium(t_prog *prog)
{
	int		cs;
	t_ms	*ms;

	cs = 8;
	ms = init_ms(prog->size , cs);
	prog->ms = ms;
	if (!prog->ms)
		prog->error = 1;
	if (!prog->error)
	{
		creat_bo(ms, cs, prog->size);
		put_aint(ms->bo, ms->ngrp);
	}
}

void	creat_bo(t_ms *ms, int cs, int size)
{
	int		i;

	i = 0;
	while (i < ms->ngrp)
	{
		ms->bo[i] = cs * (i + 1);
		i++;
	}
	i--;
	if (ms->bo[i] > size)
		ms->bo[i] = size;
}

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
	ft_printf("res->ngrp %d\n", res->ngrp);
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
