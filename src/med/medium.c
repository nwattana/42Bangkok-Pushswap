/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:51:26 by nwattana          #+#    #+#             */
/*   Updated: 2022/10/06 03:00:11 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
void	b_to_a(t_ms *ms, t_prog *prog);
void	add_grp(t_prog *prog, t_ms *ms);
int	get_dir(t_ms *ms, t_prog *prog, int next);

void	medium(int cs, t_prog *prog)
{
	prog->ms = ms_init(cs, prog);
	if (!prog->ms)
		return ;
	ft_putstr_fd("=============================\n",1);
	show_ms_cs(prog->ms);
	show_ms(prog->ms);
	ft_putstr_fd("=============================\n",1);
	add_grp(prog, prog->ms);
	a_to_b(prog->ms, prog);
	move_top(prog->ms, prog);
	b_to_a(prog->ms, prog);
}

void	add_grp(t_prog *prog, t_ms *ms)
{
	t_list 	*list;

	list = prog->ta;
	while (list)
	{
		*ga_cont_grp(list) = is_inchunk(ms, g_cont_po(list));
		list = list->next;
	}
}

void	b_to_a(t_ms *ms, t_prog *prog)
{
	int next;
	int	pre;
	int	direc;

	ms->p_top = g_cont_grp(prog->tb);
	pre = 0;
	direc = 0;
	while (prog->tb)
	{
		if (!pre)
		{
			next = g_cont_po(prog->ta) - 1;
			direc = get_dir(ms ,prog, next);
		}
		ft_printf("\ttop b %d next %d pre %d ",g_cont_po(prog->tb), next, pre);
	//	ft_printf("top b%d\t pass b %d in b %d\n",ms->ch[ms->p_top].index, ms->ch[ms->p_top].passb, ms->ch[ms->p_top].inb);
	//	ft_printf("direct %d p_top %d\n", direc, ms->p_top);
		ft_printf("grp %d\n", g_cont_grp(prog->tb));
		if (g_cont_po(prog->tb) == next)
		{
			action(pa, prog);
			
			if (pre)
			{
				action(sa, prog);
				pre = 0;
			}
		}
		else if (g_cont_po(prog->tb) == next - 1)
		{
			action(pa, prog);
			pre = 1;
		}
		else
		{

			if (direc)
			{
				action(rb, prog);
				ms->ch[ms->p_top].passb++;
			}
			else
			{
				action(rrb, prog);
				ms->ch[ms->p_top].passb--;
			}
		}
	}
}

int	get_dir(t_ms *ms, t_prog *prog, int next)
{
	t_ch ch;
	t_list *temp;
	int		i;

	ch = ms->ch[ms->p_top];
	temp = prog->tb;
	if (ch.inb == 0)
	{
		ms->p_top--;
		return (1);
	}
	else if (ch.passb == ch.inb)
	{
		return (0);
	}
	else if (g_cont_grp(prog->tb) != ms->p_top)
	{
		return (0);
	}
	i = ch.inb - ch.passb;
	while (temp && i--)
	{
		if (g_cont_po(temp) == next)
			return (1);
		temp = temp->next;
	}
	return (0);
}
