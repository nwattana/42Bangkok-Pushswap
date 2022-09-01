/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:55:36 by nwattana          #+#    #+#             */
/*   Updated: 2022/04/22 03:23:02 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	format_check_s(t_format *f1, char *str);
static int	printn_char(const char *str, int a);

int	put_s(char *str, t_format *f1)
{
	int	len;

	format_check_s(f1, str);
	len = 0;
	if (f1->left)
	{
		if (str == NULL)
			len += printn_char("(null)", f1->print_0);
		else
			len += printn_char(str, f1->print_0);
		len += put_charloop(' ', f1->space_area);
	}
	else
	{
		if (f1->zero)
			len += put_charloop('0', f1->space_area);
		else
			len += put_charloop(' ', f1->space_area);
		if (str == NULL)
			len += printn_char("(null)", f1->print_0);
		else
			len += printn_char(str, f1->print_0);
	}
	return (len);
}

static int	format_check_s(t_format *f1, char *str)
{
	int	string_amount;

	string_amount = 0;
	if (str == NULL)
	{
		f1->zero_value = 1;
		string_amount = 6;
	}
	else
		string_amount = ft_strlen(str);
	if (f1->dot)
	{
		if (string_amount >= f1->afterdot)
		{
			f1->print_0 = f1->afterdot;
			string_amount = f1->print_0;
		}
		else
			f1->print_0 = string_amount;
	}
	else
		f1->print_0 = string_amount;
	if (f1->beforedot > string_amount)
			f1->space_area = f1->beforedot - string_amount;
	return (string_amount);
}

static int	printn_char(const char *str, int a)
{
	int	i;

	i = 0;
	while (a > 0 && *str != '\0')
	{
		ft_putchar_fd(*str, 1);
		str++;
		a--;
		i++;
	}
	return (i);
}
