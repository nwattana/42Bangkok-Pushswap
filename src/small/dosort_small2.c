/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dosort_small2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 11:17:53 by nwattana          #+#    #+#             */
/*   Updated: 2022/10/23 11:18:15 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

t_sres	*init_sres(void)
{
	t_sres	*sres;

	sres = malloc(sizeof(t_sres));
	if (!sres)
		return (NULL);
	sres->size_a = 0;
	sres->size_b = 0;
	sres->sta[0] = none;
	sres->stb[0] = none;
	return (sres);
}
