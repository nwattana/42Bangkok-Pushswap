/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 01:43:58 by nwattana          #+#    #+#             */
/*   Updated: 2022/08/18 23:38:01 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *src)
{
	int		res;
	int		minus;
	char	*c;

	c = (char *)src;
	res = 0;
	minus = 1;
	while (ft_isspace(*c))
		c++;
	if (*c == '+' || *c == '-')
	{
		if (*c == '-')
		{
			minus *= -1;
		}
		c++;
	}
	while (ft_isdigit(*c))
	{
		res *= 10;
		res += (*c) - '0';
		c++;
	}
	return (res * minus);
}
