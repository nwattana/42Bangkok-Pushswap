
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

void	cal_way(t_prog *prog, t_msort *st)
{
	t_list	temp;
	int		count_elim;
	int		count_start;

	i = 0;
	ind = 0;
	while (i < st->ngrp)
	{
		counting start = 1;
		count_elim = prog->ngrp; 
		while (temp)
		{
			if (!ind && s_cal_way(temp, i))
				ind = 1;
			if (ind && s_cal_way(temp, i))
				count_elim--;
			if (ind)
				st->way[i] = st->way[i] + 1;
			temp = temp->next;
		}
	}
}

// PRINT ARRAY INT
void	put_inttab(int *a, int size)
{
	int		i;

	if (!a)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ft_putnbr_fd(*a, 1);
		a++;
		i--;
	}
}

static int	s_cal_way(t_list *ls, i, int bo)
{
	int	upper;
	int lowwer;

	upper = bo[i];
	if (i == 0)
		lowwer = 0;
	else
		lowwer = bo[i - 1];
	return (g_cont_po(ls) > lowwer \
		&& g_cont_po(ls) <= upper);
}

void	get_middle(t_msort *sort, int ch_bo)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		sort->bo[i] = ch_bo * i;
		i++;
	}
}

t_msort	*init_msort(int n)
{
	t_msort	*res;

	if (n < 3)
		return (NULL);
	res = malloc(sizeof(t_msort));
	if (!res)
		return (NULL);
	res->bo = ft_calloc(sizeof(int) * n);
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

