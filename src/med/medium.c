/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:51:26 by nwattana          #+#    #+#             */
/*   Updated: 2022/10/11 12:15:44 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
void	b_to_a(t_ms *ms, t_prog *prog);
int	rotate_b(t_ms *ms, t_prog *prog, int next, int chunk);
int	r_rotate_b(t_ms *ms, t_prog *prog, int next, int chunk);
void	temp_swap_top(t_prog *prog);
void	add_grp(t_prog *prog, t_ms *ms);
int	get_dir(t_ms *ms, t_prog *prog, int next, int ch);

void	medium(int cs, t_prog *prog)
{
	prog->ms = ms_init(cs, prog);
	if (!prog->ms)
		return ;
	//ft_putstr_fd("=============================\n",1);
	//show_ms(prog->ms);
	//ft_putstr_fd("=============================\n",1);
	add_grp(prog, prog->ms);
	a_to_b(prog->ms, prog);
	move_top(prog->ms, prog);
	//ft_putstr_fd("=====================\n",1);
	//show_ms_cs(prog->ms);
	temp_swap_top(prog);
	b_to_a(prog->ms, prog);
	//ft_printf("\n\n=======%d ngrp=======\n",prog->ms->ngrp);
//	dump_p(prog);
}

void	temp_swap_top(t_prog *prog)
{
	int		mode;

	mode = 0;
	if (g_cont_po(prog->ta) == prog->size)
	{
		action(sa, prog);
	}
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
	int		chunk;
	int		next;
	int		dir;
	int		temp_a;

	// find where node are
	chunk = ms->ngrp - 1;
	// care for pre and min
	next = ms->ch[chunk].upper - 1;
	while (chunk >= 0 && ft_lstsize(prog->tb) > 0)
	{
	while (ms->ch[chunk].inb > 0 && ft_lstsize(prog->tb) > 0)
	{
		dir = get_dir(ms, prog, next, chunk);
	// 1 rb 0 rrb
	//	ft_printf("ta = %d   next = %d  dir%d \n",g_cont_po(prog->ta),next,dir);
		if (dir)
		{
			temp_a = rotate_b(prog->ms, prog, next, chunk);
		}
		else
		{
			temp_a = r_rotate_b(prog->ms, prog, next, chunk);
		}
//		dump_g_all(prog);
//		dump_ch(ms->ch[g_cont_grp(prog->ta)]);
	//	ft_printf("top a %d - top b%d\n\n", g_cont_po(prog->ta), g_cont_po(prog->tb));
		if (temp_a != 2)
			next = next - 1;
		else
		{
			return ;
		}
	//	ft_printf("ms->ch[chunk].inb %d ===\n\n", ms->ch[chunk].inb);
	}
	chunk--;
	}
}

int	r_rotate_b(t_ms *ms, t_prog *prog, int next, int chu)
{
	int stop;

	stop = 0;
	while (!stop)
	{
		if (g_cont_po(prog->tb) == next)
		{
			action(pa, prog);
			pushto(0, &(ms->ch[chu]));
			stop = 1;
		}
		else if (ms->ch[chu].passb > 0)
		{
			action(rrb, prog);
			ms->ch[chu].passb--;
		}
		else 
		{
	//		ft_printf("top b %d\t, stop %d\t, next%d\n",g_cont_po(prog->tb), stop, next);
	//		ft_putstr_fd("something gone wornd about r_rotate\n",1);
			stop = 2;
		}
	}
	return (stop);
}

int	rotate_b(t_ms *ms, t_prog *prog, int next, int chu)
{
	int	stop;
	int	rr_need;

	stop = 0;
	rr_need = 0;
	while (!stop)
	{
		if (g_cont_po(prog->tb) == next)
		{
			action(pa, prog);
			stop = 1;
			pushto(0, &(ms->ch[chu]));
		}
		else if (g_cont_po(prog->tb) == ms->ch[chu].min && !rr_need)
		{
			action(pa, prog);
			ms->ch[chu].passa++;
			pushto(0, &(ms->ch[chu]));
			rr_need = 1;
			ms->ch[chu].min++;
		}
		else if (ms->ch[chu].inb - ms->ch[chu].passb > 0)
		{
			if (rr_need)
			{
				action(rr, prog);
				rr_need = 0;
			}
			else
				action(rb, prog);
			ms->ch[chu].passb++;
		}
		else
		{
	//		ft_putstr_fd("121 Wrong Case at %d\tn", chu);
			stop = 2;
		}
	}
	return (stop);
}

int	get_dir(t_ms *ms, t_prog *prog, int next, int chunk)
{
	// find from top == remining in b - pass b
	// not found use rrb	
	int		lim;
	t_ch	ch;
	t_list	*temp;

	ch = ms->ch[chunk];
	temp = prog->tb;
	lim = ch.inb - ch.passb;
	//ft_printf("From get dir ch.inb %d pass b %d chunk %d\n", ch.inb, ch.passb, chunk);
	if (ch.inb == 0)
		return (1);
   while (lim-- && temp)
   {
		 if (g_cont_po(temp) == next)
				 return (1);
		 temp = temp->next;
   }
	return (0);   
}
