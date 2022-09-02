/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 19:16:45 by nwattana          #+#    #+#             */
/*   Updated: 2022/09/02 21:48:15 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_cont cont_init(int n)
{
	t_cont *cont;

	cont = malloc(sizeof(t_cont));
	if (!cont)
		return (NULL);
	cont->data = n;
	cont->po = 0;
	cont->grp = 0;
	cont->au = 0;
	return (cont);
}

