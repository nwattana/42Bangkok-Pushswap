/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dosort_small.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 21:42:00 by nwattana          #+#    #+#             */
/*   Updated: 2022/10/23 11:25:33 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	so_small(t_prog *prog)
{
	prog->sres = init_sres();
	if (!prog->sres)
		prog->error = 1;
	if (!prog->error)
	{
		add3_sres(prog);
		sres_do(prog->sres, prog, prog->sres->sta);
		free(prog->sres);
	}
}

void	sres_do(t_sres *res, t_prog *prog, t_act *a)
{
	UINT	i;

	i = 0;
	if (res->size_a == 0 && res->size_b == 0)
		return ;
	while (i < res->size_a)
	{
		if (a[i] == sa)
			action(sa, prog);
		else if (a[i] == ra)
			action(ra, prog);
		else if (a[i] == rra)
			action(rra, prog);
		i++;
	}
}

void	add3_sres(t_prog *prog)
{
	t_list	*temp;

	temp = prog->ta;
	if (g_cont_po(temp) == 1)
	{
		aact_a(sa, prog);
		aact_a(ra, prog);
	}
	else if (g_cont_po(temp) == 2)
	{
		if (g_cont_po(temp->next) == 3)
			aact_a(rra, prog);
		else
			aact_a(sa, prog);
	}
	else
	{
		aact_a(ra, prog);
		if (g_cont_po(temp->next) != 1)
			aact_a(sa, prog);
	}
	aact_a(none, prog);
}
