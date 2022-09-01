/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_charloop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 03:35:56 by nwattana          #+#    #+#             */
/*   Updated: 2022/04/22 03:58:40 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	put_charloop(char a, int times)
{
	int	i;

	i = 0;
	if (times < 0)
		return (0);
	while (times)
	{
		ft_putchar_fd(a, 1);
		times--;
		i++;
	}
	return (i);
}
