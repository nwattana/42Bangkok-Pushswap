/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:51:59 by nwattana          #+#    #+#             */
/*   Updated: 2022/04/22 03:18:21 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_itoa_uint(unsigned int number, int len)
{
	char	*res;
	int		i;

	i = 0;
	res = (char *)malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	while (len > 0)
	{
		res[i] = '0' + number % 10;
		number = number / 10;
		i++;
		len--;
	}
	res[i] = '\0';
	ft_strrev(res);
	return (res);
}
