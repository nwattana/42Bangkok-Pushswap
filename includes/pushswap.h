/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 04:33:35 by nwattana          #+#    #+#             */
/*   Updated: 2022/09/12 19:03:48 by nwattana         ###   ########.fr       */
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
	t_ms *ms;

}		t_prog;

t_prog		*prog_init(void);
void	prog_free(t_prog *prog);

// input
void	get_input(int argc, char *argv[], t_prog *prog);
void	inputint(int argc, char *argv[], t_prog *prog);
void	inputstr(char *argv[], t_prog *prog);
void	add_cont(t_prog *prog, char *s);
void	lst_addback_po(t_list **h, t_list *node, t_prog *p);
int		isstrint(char *s);
int		issort(t_list *s);

// cont
t_cont *cont_init(int n);
int		g_cont_po(t_list *lst);
int		*ga_cont_po(t_list *lst);
int		g_cont_grp(t_list *lst);
int		*ga_cont_grp(t_list *lst);
int		g_cont_data(t_list *lst);
int		*ga_cont_data(t_list *lst);


// debug
void	dump_p(t_prog *p);
void	dump_s(t_list *p);
void	put_aint(int *nu, int size);

// action
t_list	*pop(t_list **head);
void	push(t_list **h, t_list *n);
void	px(t_list **h, t_list **x);
void	swap(t_list **ta);
void	rx(t_list **ta);
void	rrx(t_list **ta);

// so small main_sort.c dosort_small.c hardcode!!
t_sres	*init_sres(void);
void	so_small(t_prog *prog);
void	sres_do(t_sres *r, t_prog *pro, t_act *a);
void	add3_sres(t_prog *prog);
void	aact_a(t_act act, t_prog *prog);
void	aact_b(t_act act, t_prog *prog);
void	main_sort(t_prog *prog);

void	small(t_prog *prog);
void	add_sep(t_prog *prog);
void	ssort_a(int size, t_prog *s);
void	ssort_b(int size, t_prog *s);
int		find_max(t_list *ta, int size);
void	do_acase(t_list *ta, int max, t_prog *prog);
void	do_bcase(t_list *ta, int max, t_prog *prog);
void	merge_act(t_sres *res, t_prog *prog);
void	action(t_act act, t_prog *pr);
// med

void	medium(t_prog *prog);
void	update_arr(t_list *ta, t_list *tb, t_ms *ms);
void	creat_bo(t_ms *ms, int cs, t_prog *prog);
t_ms	*init_ms(int size, int cs);
void	clear_ms(t_ms *ms);
#endif

