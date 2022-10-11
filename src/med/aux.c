/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:04:13 by nwattana          #+#    #+#             */
/*   Updated: 2022/10/11 10:58:08 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_aux *init_aux()
{
	t_aux *ax;

	ax = ft_calloc(sizeof(t_aux), 1);
	if (!ax)
		return (NULL);
	return (ax);
}

void	dump_ax(t_aux *ax)
{
	ft_printf("min %d\t", ax->min);
	ft_printf("xtrig %d\t", ax->xtrig);
	ft_printf("ytrig %d\t", ax->ytrig);
	ft_printf("stop %d\t", ax->stop);
	ft_printf("Loop %d\n", ax->loop);
}

void	ax_retog(t_aux *ax)
{
	ax->tog1 = 0;
	ax->tog2 = 0;
}

void	ax_tog(int a, int nu, t_aux *ax)
{
	if (nu == 1)
			ax->tog1 = a;
	if (nu == 2)
			ax->tog2 = a;
}
