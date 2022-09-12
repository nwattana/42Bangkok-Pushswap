/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 08:26:14 by nwattana          #+#    #+#             */
/*   Updated: 2022/09/04 12:34:25 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	small(t_prog *prog)
{
	prog->sres = init_sres();
	if (!prog->sres)
			prog->error = 1;
	if (!prog->error)
	{
		add_sep(prog);
		//dump_p(prog);
		ssort_a(ft_lstsize(prog->ta), prog);
		ssort_b(ft_lstsize(prog->tb), prog);
		merge_act(prog->sres, prog);
		while (ft_lstsize(prog->tb))
		{
			action(pa, prog);
		}
	}
}

void	add_sep(t_prog *prog)
{
	int middle;

	middle = prog->size / 2;
	while (ft_lstsize(prog->tb) != middle)
	{
		if (g_cont_po(prog->ta) <= middle)
		{
			px(&prog->ta, &prog->tb);
			ft_putstr_fd("pb\n", 1);
		}
		else
		{
			rx(&prog->ta);
			ft_putstr_fd("ra\n", 1);
		}
	}
}

void	ssort_b(int size, t_prog *prog)
{
	int	max;

	if (size == 2)
	{
		if (g_cont_po(prog->tb) < g_cont_po(prog->tb->next))
			aact_b(sb, prog);
	}
	else
	{
		max = find_max(prog->tb, ft_lstsize(prog->tb));
		do_bcase(prog->tb, max, prog);
	}
	aact_b(none, prog);
}

void	do_bcase(t_list *tb, int max, t_prog *prog)
{
	if (g_cont_po(tb) == max)
	{
		if (g_cont_po(tb->next) == max - 2)
		{
			aact_b(sb, prog);
			aact_b(rb, prog);
		}
	}
	else if (g_cont_po(tb) == max - 1)
	{
		if (g_cont_po(tb->next) == max - 2)
			aact_b(rrb, prog);
		else
			aact_b(sb, prog);	
	}
	else
	{
		if (g_cont_po(tb->next) == max - 1)
		{
			aact_b(sb, prog);
			aact_b(rrb, prog);
		}
		else
			aact_b(rb, prog);
	}
}

void	ssort_a(int size, t_prog *prog)
{
//	ft_printf("Do something\n");
	int	max;
	if (size == 2)
	{
		if (g_cont_po(prog->ta) > g_cont_po(prog->ta->next))
				aact_a(sa, prog);
	}
	else
	{
		max = find_max(prog->ta, ft_lstsize(prog->ta));
		do_acase(prog->ta, max, prog);
	}
	aact_a(none, prog);

}

void	do_acase(t_list *ta, int max, t_prog *prog)
{
//	ft_printf("%d == %d\n", g_cont_po(ta), max);
//	ft_printf("%d == %d\n", g_cont_po(ta->next), max);
	if (g_cont_po(ta)  == max)
	{
		if (g_cont_po(ta->next) == max - 1)
		{
			aact_a(sa,prog);
			aact_a(rra, prog);
		}
		else
			aact_a(ra, prog);
	}
	else if (g_cont_po(ta) == max - 2)
	{
		if (g_cont_po(ta->next) == max)
		{
			aact_a(sa, prog);
			aact_a(ra, prog);
		}
	}
	else
	{
		if (g_cont_po(ta->next) == max)
			aact_a(rra, prog);
		else
			aact_a(sa, prog);
	}
}

int		find_max(t_list *lst, int size)
{
	int	temp;

	if (!lst)
		return (0);
	temp = g_cont_po(lst);
	while (lst && size--)
	{
		if (temp < g_cont_po(lst))
				temp = g_cont_po(lst);
		lst = lst->next;
	}
	return (temp);
}

void	merge_act(t_sres *res, t_prog *prog)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (res->sta[i] != none)
	{
		if (res->stb[j] != none && res->sta[i] + 1 == res->stb[j])
		{
			if (res->stb[j] == sb)
				action(ss, prog);
			if (res->stb[j] == rb)
				action(rr, prog);
			if (res->stb[j] == rrb)
				action(rrr, prog);
			j++;
		}
		else
		{
			action(res->sta[i] , prog);
		}
		i++;
	}
	while (res->stb[j] != none)
	{
		action(res->stb[j++], prog);
	}
}
