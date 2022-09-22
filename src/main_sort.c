/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 06:23:07 by nwattana          #+#    #+#             */
/*   Updated: 2022/09/23 01:46:17 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	main_sort(t_prog *prog)
{
	UINT len;

	len = prog->size;
	if (len == 2)
		ft_putstr_fd("ra\n", 1);
	else if (len == 3)
		so_small(prog);
	else if (len <= 6)
		small(prog);
	else if (len <= 120)
		medium(15, prog);
	else
		medium(25, prog);
}
