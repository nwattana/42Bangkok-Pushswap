/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 04:38:10 by nwattana          #+#    #+#             */
/*   Updated: 2022/09/03 21:40:51 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_prog	*prog_init(void)
{
	t_prog	*res;

	res = (t_prog *)malloc(sizeof(t_prog));
	if (!res)
		return (NULL);
	res->size = 0;
	res->error = 0;
	res->ta = NULL;
	res->tb = NULL;

	return (res);
}

void	prog_free(t_prog *prog)
{
	if (prog->ta)
		ft_lstclear(&prog->ta, free);
	if (prog->tb)
		ft_lstclear(&prog->tb, free);
	free(prog);
}
