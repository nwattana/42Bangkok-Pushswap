/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:58:42 by nwattana          #+#    #+#             */
/*   Updated: 2022/09/03 16:46:29 by nwattana         ###   ########.fr       */
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
		else
		{
			add_cont(prog, argv[i]);
		}
		i++;
	}
}

void	add_cont(t_prog *prog, char *s)
{
	long	num;
	t_list	*tmp;

	num = ft_atol(s);
	if (num > MAX_INT && num < MIN_INT)
			prog->error = 1;
	if (!prog->error)
	{
		tmp = ft_lstnew(cont_init(num));
		if (!tmp)
			prog->error = 1;
		if (!prog->error)
			lst_addback_po(&prog->ta, tmp, prog);
		prog->size++;
	}
}

void	lst_addback_po(t_list **h, t_list *node, t_prog *prog)
{
	t_list	*temp;

	if (!node || !h)
		return ;
	if (!*h)
	{
		*h = node;
		return ;
	}
	temp = *h;
	while (temp)
	{
		if (g_cont_data(node) > g_cont_data(temp))
			(*ga_cont_po(node))++;
		else if (g_cont_data(node) == g_cont_data(temp))
			prog->error = 1;
		else
			(*ga_cont_po(temp))++;
		if (temp->next == NULL)
		{
			temp->next = node;
			return ;
		}
		temp = temp->next;
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
