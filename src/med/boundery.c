/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boundery.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:22:19 by nwattana          #+#    #+#             */
/*   Updated: 2022/09/18 14:22:36 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	boundery(int size, t_ch *chi, int *bo)
{
	int		i;

	i = 1;
	if (!chi || !bo)
		return ;
	chi[0].low = 1;
	chi[0].up = bo[0];
	chi[0].m_amount = bo[0] - 1;
	while (i < size)
	{
		chi[i].index = i;
		chi[i].m_amount = bo[i] - bo[i-1];
		chi[i].up = bo[i];
		chi[i].low = bo[i - 1];
		i++;
	}
}

