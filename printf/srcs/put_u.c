/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:55:56 by nwattana          #+#    #+#             */
/*   Updated: 2022/04/22 06:47:09 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	check_format_u(int number_len, t_format *f1);
static int	put_string_u(const char *str, t_format *f1);
static int	sub_put_u(char *str, t_format *f1);

int	put_u(unsigned int number, t_format *f1)
{
	int		put_len;
	int		num_len;
	char	*num_a;

	put_len = 0;
	num_len = number_base_len(number, 10, f1);
	check_format_u(num_len, f1);
	num_a = ft_itoa_uint(number, num_len);
	if (!num_a)
		return (-1);
	if (f1->left)
	{
		put_len += sub_put_u(num_a, f1);
		put_len += put_charloop(' ', f1->space_area);
	}
	else
	{
		if (f1->zero && !f1->dot)
			put_len += put_charloop('0', f1->space_area);
		else
			put_len += put_charloop(' ', f1->space_area);
		put_len += sub_put_u(num_a, f1);
	}
	free(num_a);
	return (put_len);
}

static int	sub_put_u(char *num_a, t_format *f1)
{	
	int	put_len;

	put_len = 0;
	put_len += put_charloop('0', f1->print_0);
	put_len += put_string_u(num_a, f1);
	return (put_len);
}

static int	check_format_u(int number_len, t_format *f1)
{
	int	width;

	width = number_len;
	if (f1->afterdot < 1 && f1->zero_value && f1->dot)
		width = 0;
	if (f1->afterdot > width)
	{
		f1->print_0 = f1->afterdot - width;
		width = f1->afterdot;
	}
	if (f1->beforedot > width)
	{
		f1->space_area = f1->beforedot - width;
		width = f1->beforedot;
	}
	return (width);
}

static int	put_string_u(const char *str, t_format *f1)
{
	int	i;

	i = 0;
	if (f1->afterdot < 1 && f1->zero_value && f1->dot)
		return (i);
	while (*str != '\0')
	{
		write (1, str++, 1);
		i++;
	}
	return (i);
}
