/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:48:38 by nwattana          #+#    #+#             */
/*   Updated: 2022/04/22 04:09:40 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	put_string_x(const char *str, t_format *f1);
static int	check_format_x(t_format	*f1, int number_len);
static int	sub_x(char *num_a, t_format *f1);

int	put_x(unsigned int number, t_format *f1)
{
	int		number_len;
	int		res;
	char	*num_a;

	number_len = number_base_len(number, 16, f1);
	check_format_x(f1, number_len);
	num_a = ft_itoa_hexa(number, number_len, f1);
	res = 0;
	if (f1->left)
	{
		res += sub_x(num_a, f1);
		res += put_charloop(' ', f1->space_area);
	}
	else
	{	
		if (f1->zero && !(f1->dot))
			res += put_charloop('0', f1->space_area);
		else
			res += put_charloop(' ', f1->space_area);
		res += sub_x(num_a, f1);
	}
	free(num_a);
	return (res);
}

static int	check_format_x(t_format	*f1, int number_len)
{
	int	width;

	width = number_len;
	if (f1->afterdot > width)
	{
		f1->print_0 = f1->afterdot - width;
		width = f1->afterdot;
	}
	if (f1->dot && f1->afterdot < 1)
		width = width + 2 * f1->hash - f1->zero_value;
	else
		width = width + 2 * f1->hash;
	if (f1->beforedot > width)
	{
		f1->space_area = f1->beforedot - width;
		width = f1->beforedot;
	}
	return (width);
}

static int	put_string_x(const char *str, t_format *f1)
{
	int	i;

	if (f1->dot && f1->zero_value && f1->afterdot < 1)
		return (0);
	i = 0;
	while (*str != '\0')
	{
		write(1, str++, 1);
		i++;
	}
	return (i);
}

static int	sub_x(char *num_a, t_format *f1)
{
	int	res;

	res = 0;
	res += put_charloop('0', f1->hash - f1->zero_value);
	res += put_charloop(f1->char_type, f1->hash - f1->zero_value);
	res += put_charloop('0', f1->print_0);
	res += put_string_x(num_a, f1);
	return (res);
}
