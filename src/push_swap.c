/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 06:18:59 by nwattana          #+#    #+#             */
/*   Updated: 2022/10/22 20:31:51 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char *argv[])
{
	t_prog	*prog;

	prog = prog_init();
	if (argc == 1 || (argc == 2 &&\
			ft_strlen(argv[1]) == 0) || !prog)
	{
		ft_printf("Something fail\n");
	}
	else
	{
		get_input(argc, argv, prog);
		if (issort(prog->ta))
			prog->error = 2;
		else
		{
			main_sort(prog);	
		}
	}
/*	if (issort(prog->ta))
	{
		ft_printf("sorted\n");
	}
	else
	{
		ft_printf("Nosort\n :(");
		dump_prog(prog);
	}*/
//	ft_printf("ToTal action = %d\n",prog->total);
	prog_free(prog);
	return (0);
}
