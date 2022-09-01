/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:53:57 by nwattana          #+#    #+#             */
/*   Updated: 2022/04/22 01:01:49 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	format_check_c(t_format *f1);

int	put_c(char c, t_format *f1)
{
	int	len;

	len = 0;
	format_check_c(f1);
	if (f1->left)
	{
		ft_putchar_fd(c, 1);
		len++;
		len += put_charloop(' ', f1->space_area);
	}
	else
	{
		if (f1->zero)
			len += put_charloop('0', f1->space_area);
		else
			len += put_charloop(' ', f1->space_area);
		len++;
		ft_putchar_fd(c, 1);
	}
	return (len);
}

static int	format_check_c(t_format *f1)
{
	if (f1->beforedot > 0)
		f1->space_area = f1->beforedot - 1;
	return (0);
}
