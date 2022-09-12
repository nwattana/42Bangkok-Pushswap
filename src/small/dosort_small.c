/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dosort_small.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 21:42:00 by nwattana          #+#    #+#             */
/*   Updated: 2022/09/12 13:51:22 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
 * 1 - 3
 * 4 - 6
 * 6 - 12 ??
 *
 */

t_sres	*init_sres(void)
{
	t_sres *sres;

	sres = malloc(sizeof(t_sres));
	if (!sres)
		return (NULL);
	sres->size_a = 0;
	sres->size_b = 0;
	sres->sta[0] = none;
	sres->stb[0] = none;
	return (sres);
}

void so_small(t_prog *prog)
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
		{
			swap(&prog->ta);
			ft_putstr_fd("sa\n", 1);
		}
		else if (a[i] == ra)
		{
			rx(&prog->ta);
			ft_putstr_fd("ra\n", 1);
		}
		else if (a[i] == rra)
		{
			rrx(&prog->ta);
			ft_putstr_fd("rra\n", 1);
		}
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
		if (g_cont_po(temp->next) == 1)
			aact_a(ra, prog);
		else
		{
			aact_a(sa, prog);
			aact_a(rra, prog);
		}
	}
	aact_a(none, prog);
}

void	aact_a(t_act act, t_prog *prog)
{
	prog->sres->sta[prog->sres->size_a] = act;
	prog->sres->size_a += 1;
}

void	aact_b(t_act act, t_prog *prog)
{
	prog->sres->stb[prog->sres->size_b] = act;
	prog->sres->size_b += 1;
}
