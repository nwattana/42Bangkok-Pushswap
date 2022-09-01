/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 07:20:37 by nwattana          #+#    #+#             */
/*   Updated: 2022/08/17 20:00:36 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *str)
{
	int	len;
	int	temp;
	int	i;

	len = ft_strlen(str);
	i = 0;
	while (i < len - i)
	{
		temp = *(str + i);
		*(str + i) = *(str + len - i - 1);
		*(str + len - i - 1) = temp;
		i++;
	}
}
