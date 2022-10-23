/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 06:23:07 by nwattana          #+#    #+#             */
/*   Updated: 2022/10/23 10:58:47 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	main_sort(t_prog *prog)
{
	unsigned int	len;

	len = prog->size;
	if (len == 2)
		ft_putstr_fd("ra\n", 1);
	else if (len == 3)
		so_small(prog);
	else if (len <= 6)
		small(prog);
	else if (len <= 50)
		medium(5, prog);
	else if (len <= 100)
		medium(10, prog);
	else
		medium(25, prog);
}
