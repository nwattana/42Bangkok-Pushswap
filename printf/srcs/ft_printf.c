/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 10:02:31 by nwattana          #+#    #+#             */
/*   Updated: 2022/04/22 03:16:22 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	process(char *str, va_list v1);
static void	format_reset(t_format *f1);

int	ft_printf(const char *str, ...)
{
	va_list	v1;
	int		len;
	char	*format;

	format = (char *)str;
	if (str == NULL)
		return (-1);
	va_start(v1, str);
	len = process(format, v1);
	va_end(v1);
	return (len);
}

static int	process(char *str, va_list v1)
{
	t_format	f1;
	int			len;
	int			mptr;

	len = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			format_reset(&f1);
			mptr = format_collect(++str, &f1);
			if (mptr < 0)
				return (-1);
			len += put_format(v1, &f1);
			str += mptr;
		}
		else
		{
			write(1, str++, 1);
			len++;
		}
	}
	return (len);
}

static void	format_reset(t_format *f1)
{
	f1->zero = 0;
	f1->space = 0;
	f1->plus = 0;
	f1->left = 0;
	f1->hash = 0;
	f1->dot = 0;
	f1->afterdot = 0;
	f1->beforedot = 0;
	f1->signed_num = 0;
	f1->zero_value = 0;
	f1->space_area = 0;
	f1->print_0 = 0;
	f1->char_type = 0;
}
