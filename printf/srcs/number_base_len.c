/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_base_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:53:33 by nwattana          #+#    #+#             */
/*   Updated: 2022/04/22 03:08:44 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	number_base_len(unsigned int num, unsigned int base, t_format *f1)
{
	int	number_len;

	number_len = 0;
	if (num == 0)
	{
		number_len = 1;
		f1->zero_value = 1;
		return (number_len);
	}
	while (num > 0)
	{
		num = num / base ;
		number_len++;
	}
	return (number_len);
}
