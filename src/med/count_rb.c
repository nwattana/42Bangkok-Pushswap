/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_rb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:23:12 by nwattana          #+#    #+#             */
/*   Updated: 2022/09/18 14:23:25 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	count_rb(int ind, t_prog *prog, t_ms *ms)
{
	int		res;
	int		prev;
	int		next;
	int		size;
	t_list	*temp;

	res = 0;
	size = ft_lstsize(prog->tb);
	if (!prog->tb)
		return (0);
	temp = prog->tb;
	while (temp && res < size)
	{
		prev = g_cont_grp(temp);
		temp = temp->next;
		if (temp)
			next = g_cont_grp(temp);
		if (ind > prev && ind < next)
			break;
		res++;
	}
	if (res == size)
		return (0);
	return (res);
}

