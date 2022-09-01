/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_di.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:54:30 by nwattana          #+#    #+#             */
/*   Updated: 2022/04/22 06:13:52 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	put_di_sub(t_format *f1, char *num_a);
static int	sub_di_2(t_format *f1);
static int	check_len_di(char *str, int number, t_format *f1);

int	put_di(int number, t_format *f1)
{
	char	*num_a;
	int		res;

	res = 0;
	num_a = ft_itoa(number);
	if (!num_a)
		return (-1);
	check_len_di(num_a, number, f1);
	if (f1->left)
	{
		res += sub_di_2(f1);
		res += put_di_sub(f1, num_a);
		res += put_charloop(' ', f1->space_area);
	}
	else
	{
		res += sub_di_2(f1);
		res += put_di_sub(f1, num_a);
	}
	if (num_a)
		free(num_a);
	return (res);
}

static int	put_di_sub(t_format *f1, char *num_a)
{
	int	res;

	res = 0;
	res += put_charloop('0', f1->print_0);
	res += put_charloop(' ', f1->space - f1->beforedot - \
			f1->plus - f1->signed_num);
	if (!(f1->zero_value && f1->dot && f1->afterdot == 0))
	{
		ft_putstr_fd(num_a + f1->signed_num, 1);
		res += ft_strlen(num_a + f1->signed_num);
	}
	return (res);
}

static int	check_len_di(char *str, int number, t_format *f1)
{
	int	width;

	if (number == 0)
		f1->zero_value = 1;
	if (number < 0)
	{
		f1->plus = 0;
		f1->signed_num = 1;
	}
	width = ft_strlen(str + f1->signed_num);
	if (f1->afterdot >= width)
	{
		f1->print_0 = f1->afterdot - width;
		width = f1->afterdot;
	}
	width += f1->signed_num + f1->plus;
	if (f1->beforedot >= width)
	{
		f1->space_area = f1->beforedot - width;
		if (f1->zero_value && f1->dot && f1->afterdot < 1)
			f1->space_area = f1->beforedot;
	}
	return (width);
}

static int	sub_di_2( t_format *f1)
{
	int	res;

	res = 0;
	if (!f1->left)
	{
		if (f1->zero && !f1->dot)
		{
			res += put_charloop('-', f1->signed_num);
			res += put_charloop('+', f1->plus);
			res += put_charloop('0', f1->space_area);
		}
		else
		{
			res += put_charloop(' ', f1->space_area);
			res += put_charloop('-', f1->signed_num);
			res += put_charloop('+', f1->plus);
		}
	}
	else
	{
		res += put_charloop('-', f1->signed_num);
		res += put_charloop('+', f1->plus);
	}
	return (res);
}
