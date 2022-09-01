/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_collect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:50:29 by nwattana          #+#    #+#             */
/*   Updated: 2022/04/22 06:28:24 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	int	sub_format_collect(char *str, t_format *f1);

int	format_collect(char *str, t_format *f1)
{
	int	i;

	i = 0;
	while (ft_isin(*(str + i), "#+- 0*", 6))
	{
		if (*(str + i) == '-')
			f1->left = 1;
		if (*(str + i) == '#')
			f1->hash = 1;
		if (*(str + i) == '+' || *(str + i) == '*')
			f1->plus = 1;
		if (*(str + i) == ' ')
			f1->space = 1;
		if (*(str + i) == '0')
			f1->zero = 1;
		i++;
	}
	i += sub_format_collect(str + i, f1);
	if (ft_isin(*(str + i), "cspduixX%", 9))
	{
		f1->char_type = *(str + i);
		i++;
		return (i);
	}
	return (-1);
}

static int	sub_format_collect(char *str, t_format *f1)
{
	int	i;

	i = 0;
	if (ft_isdigit(*(str + i)))
	{
		f1->beforedot = ft_atoi((str + i));
		while (ft_isdigit(*(str + i)))
			i++;
	}
	if (*(str + i) == '.')
	{
		f1->dot = 1;
		i++;
		if (ft_isdigit(*(str + i)))
		{
			f1->afterdot = ft_atoi((str + i));
			while (ft_isdigit(*(str + i)))
				i++;
		}
	}
	return (i);
}
