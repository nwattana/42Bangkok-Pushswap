/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:55:17 by nwattana          #+#    #+#             */
/*   Updated: 2022/04/22 03:09:57 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	put_p(unsigned long long number, t_format *f1)
{
	int	put_len;

	put_len = 0;
	f1->hash = 1;
	put_len += put_x_p(number, f1);
	return (put_len);
}
