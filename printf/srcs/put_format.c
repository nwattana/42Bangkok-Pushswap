/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:54:51 by nwattana          #+#    #+#             */
/*   Updated: 2022/04/22 03:20:15 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	format_put_flag(va_list v1, t_format *f1);

int	put_format(va_list v1, t_format *f1)
{
	int	put_len;

	put_len = 0;
	put_len += format_put_flag(v1, f1);
	return (put_len);
}

static int	format_put_flag(va_list v1, t_format *f1)
{
	int	put_len;

	if (f1->char_type == 'c')
		put_len = put_c(va_arg(v1, int), f1);
	else if (f1->char_type == 's')
		put_len = put_s(va_arg(v1, char *), f1);
	else if (f1->char_type == 'p')
		put_len = put_p(va_arg(v1, unsigned long long), f1);
	else if (ft_isin(f1->char_type, "di", 2))
		put_len = put_di(va_arg(v1, int), f1);
	else if (f1->char_type == 'u')
		put_len = put_u(va_arg(v1, unsigned int), f1);
	else if (ft_isin(f1->char_type, "xX", 2))
		put_len = put_x(va_arg(v1, unsigned long), f1);
	else if (f1->char_type == '%')
		put_len = put_percent(f1);
	else
		put_len = -1;
	return (put_len);
}
