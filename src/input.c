/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:58:42 by nwattana          #+#    #+#             */
/*   Updated: 2022/09/02 18:07:34 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
/*
 * Check input is number
 * Check input string group or only num
 * Check Duplicate
 * Check only int lenght
 * Store data in sta
 */

/*
 * "12 32 -12 132"
 */
void	get_input(int argc, char *argv[], t_prog *prog)
{
	if (argc == 2)
		inputstr(argv, prog);
	else
		inputint(argc, argv, prog);
}

void	inputint(int argc, char *argv[], t_prog *prog)
{
	int		i;

	i = 1;
	while (i < argc && !prog->error)
	{
		if (!isstrint(argv[i]))
			prog->error = 1;
		i++;
	}
}

int	isstrint(char *s)
{
	int		prefix;

	prefix = 1;
	if (*s == '-')
	{
		prefix = 0;
		s++;
	}
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
		prefix = 1;
	}
	if (!prefix)
		return (0);
	return (1);
}
