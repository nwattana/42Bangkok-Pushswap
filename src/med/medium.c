/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:51:26 by nwattana          #+#    #+#             */
/*   Updated: 2022/10/11 00:11:12 by nwattana         ###   ########.fr       */
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
	ft_putstr_fd("=====================\n",1);
	show_ms_cs(prog->ms);
	//temp_swap_top(prog);
	//b_to_a(prog->ms, prog);
	ft_printf("\n\n=======%d ngrp=======\n",prog->ms->ngrp);
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
	while (chunk >= 0)
	{
	while (ms->ch[chunk].inb > 0)
	{
		dir = get_dir(ms, prog, next, chunk);
	// 1 rb 0 rrb
	//	ft_printf("ta = %d   next = %d\n",g_cont_po(prog->ta),next);
		if (dir)
		{
			temp_a = rotate_b(prog->ms, prog, next, chunk);
		}
		else
		{
			temp_a = r_rotate_b(prog->ms, prog, next, chunk);
		}

	//	ft_printf("top a %d - top b%d\n\n", g_cont_po(prog->ta), g_cont_po(prog->tb));
		if (temp_a != 2)
			next = next - 1;
		else
		{
			dump_ch(ms->ch[chunk]);
			return ;
		}
		dump_p(prog);
		usleep(100000);
	}

	//
	// get neibor ss sa
	//
	//
	// get min  --> min update adding passA rr ra rb
	// reset passA rra half chunk
	//
	//
	chunk--;
	}
}

int	r_rotate_b(t_ms *ms, t_prog *prog, int next, int chu)
{
	int stop;

	//ft_printf("Look for %d\n", next);
	stop = 0;
	while (!stop)
	{
	//	ft_printf("find next %d, remaining to pass %d\n", next, ms->ch[chu].passb);
		if (g_cont_po(prog->tb) == next)
		{
			action(pa, prog);
			ms->ch[chu].inb--;
			ms->ch[chu].ina++;
			stop = 1;
		}
		else if (ms->ch[chu].passb > 0)
		{
			action(rrb, prog);
			ms->ch[chu].passb--;
		}
		else 
		{
			ft_putstr_fd("something gone wornd about r_rotate\n",1);
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
			ms->ch[chu].inb--;
			ms->ch[chu].ina++;
		}
		else if (g_cont_po(prog->tb) == ms->ch[chu].min && !rr_need)
		{
			action(pa, prog);
			ms->ch[chu].passa++;
			ms->ch[chu].inb--;
			ms->ch[chu].ina++;
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
			ft_putstr_fd("121 Wrong Case\n", 1);
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
   while (lim-- && temp)
   {
		 if (g_cont_po(temp) == next)
				 return (1);
		 temp = temp->next;
   }
	return (0);   
}
