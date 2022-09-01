/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 06:29:13 by nwattana          #+#    #+#             */
/*   Updated: 2022/04/22 03:17:01 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*get_base16(t_format *f1);

char	*ft_itoa_hexa(unsigned int number, int len, t_format *f1)
{
	char	*res;
	int		i;
	char	*base;

	i = 0;
	base = get_base16(f1);
	if (base == NULL)
		return (NULL);
	res = (char *)malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	while (len)
	{
		res[i] = base[number % 16];
		number = number / 16;
		len--;
		i++;
	}
	res[i] = '\0';
	ft_strrev(res);
	free (base);
	return (res);
}

static char	*get_base16(t_format *f1)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * 17);
	if (!res)
		return (NULL);
	if (f1->char_type == 'X')
		ft_strlcpy(res, "0123456789ABCDEF", 17);
	else
		ft_strlcpy(res, "0123456789abcdef", 17);
	return (res);
}
