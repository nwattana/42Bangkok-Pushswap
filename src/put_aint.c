/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_aint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:08:27 by nwattana          #+#    #+#             */
/*   Updated: 2022/09/12 15:36:01 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	put_aint(int *nu, int size)
{
	int		i;

	i = 0;
	if (!nu)
	{
		return ;
	}
	if (size == 0)
		ft_putstr_fd("Empty\n", 1);
	while (i < size)
	{
		ft_putnbr_fd(nu[i++], 1);
		ft_putstr_fd(", ", 1);
	}
	ft_putstr_fd("\n", 1);
}
