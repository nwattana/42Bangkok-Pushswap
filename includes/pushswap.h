/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 04:33:35 by nwattana          #+#    #+#             */
/*   Updated: 2022/10/23 11:46:48 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libftprintf.h"
# include "const_type.h"
# include "pstruct.h"

typedef struct s_prog
{
	int		error;
	int		size;
	t_list	*ta;
	t_list	*tb;
	t_sres	*sres;
	int		total;
	t_ms	*ms;
}		t_prog;

t_prog		*prog_init(void);
void		prog_free(t_prog *prog);
void		get_input(int argc, char *argv[], t_prog *prog);
void		inputint(int argc, char *argv[], t_prog *prog);
void		inputstr(char *argv[], t_prog *prog);
void		add_cont(t_prog *prog, char *s);
void		lst_addback_po(t_list **h, t_list *node, t_prog *p);
int			isstrint(char *s);
int			issort(t_list *s);
t_cont		*cont_init(int n);
int			g_cont_po(t_list *lst);
int			*ga_cont_po(t_list *lst);
int			g_cont_grp(t_list *lst);
int			*ga_cont_grp(t_list *lst);
int			g_cont_data(t_list *lst);
int			*ga_cont_data(t_list *lst);
void		dump_prog(t_prog *p);
void		dump_position(t_list *p);
void		dump_grp(t_list *p);
void		dump_g_all(t_prog *p);
void		dump_node(t_list *p);
void		put_aint(int *nu, int size);
t_list		*pop(t_list **head);
void		push(t_list **h, t_list *n);
void		px(t_list **h, t_list **x);
void		swap(t_list **ta);
void		rx(t_list **ta);
void		rrx(t_list **ta);
void		l_action(t_act act, int times, t_prog *prog);
t_sres		*init_sres(void);
void		so_small(t_prog *prog);
void		sres_do(t_sres *r, t_prog *pro, t_act *a);
void		add3_sres(t_prog *prog);
void		aact_a(t_act act, t_prog *prog);
void		aact_b(t_act act, t_prog *prog);
void		main_sort(t_prog *prog);
void		small(t_prog *prog);
void		add_sep(t_prog *prog);
void		ssort_a(int size, t_prog *s);
void		ssort_b(int size, t_prog *s);
int			find_max(t_list *ta, int size);
void		do_acase(t_list *ta, int max, t_prog *prog);
void		do_bcase(t_list *ta, int max, t_prog *prog);
void		merge_act(t_sres *res, t_prog *prog);
void		action(t_act act, t_prog *pr);
t_ch		*assign_ch(t_prog *prog, int cs, int ngrp);
void		dump_ch(t_ch ch);
int			is_inchunk(t_ms *ms, int n);
int			is_chunk_mem(t_ch ch, int n);
void		pushto(int a, t_ch *ch);
void		medium(int a, t_prog *prog);
t_ms		*ms_init(int a, t_prog *prog);
void		show_ms(t_ms *ms);
void		show_ms_cs(t_ms *ms);
void		a_to_b(t_ms *ms, t_prog *prog);
void		b_to_a(t_ms *ms, t_prog *prog);
void		move_top(t_ms *ms, t_prog *prog);
void		sort_3(t_prog *prog);
#endif
