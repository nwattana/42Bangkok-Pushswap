
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:33:04 by nwattana          #+#    #+#             */
/*   Updated: 2022/09/08 00:01:21 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"


/// chunksize = 10;
void	medium(t_prog *prog)
{
	int		cs;

	cs = 10;
	// initer sorter m - mem
	prog->msort = init_msort(n);
	if (!prog->msort)
		prog->error = 1;
	if (!prog->error)
	{

	}
}

/*
 * Count length member of chunk 
 * from first top stack to last member
 * save at way[] -> note its Heap memory
 *
 */

t_msort	*init_msort(int n)
{
	t_msort	*res;

	if (n < 3)
		return (NULL);
	res = malloc(sizeof(t_msort));
	if (!res)
		return (NULL);
	res->bo = ft_calloc(sizeof(int) , n);
	res->way = ft_calloc(sizeof(int) , n);
	res->ngrp = n;
	if (!res->bo || !res->way)
	{
		if (res->bot)
			free(res->bo);
		if (res->way)
			free(res->way);
		free(res);
		return (NULL);
	}
	return (res);
}


