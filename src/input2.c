/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 17:52:15 by nwattana          #+#    #+#             */
/*   Updated: 2022/09/03 15:41:37 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	free2d(char **a);

void	inputstr(char *argv[], t_prog *prog)
{
	char	**stra;
	int		i;

	i = 0;
	stra = ft_split(argv[1], ' ');
	if (!stra)
	{
		prog->error = 1;
		return ;
	}
	while (stra[i] != NULL && !prog->error)
	{
		if (!isstrint(stra[i]))
			prog->error = 1;
		else
			add_cont(prog, stra[i]);
		i++;
	}
	free2d(stra);
}

static void	free2d(char **a)
{
	int	i;

	i = 0;
	if (!a)
		return ;
	while (a[i] != NULL)
	{
		free(a[i]);
		i++;
	}
	free(a);
}
