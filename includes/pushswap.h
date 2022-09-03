/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 04:33:35 by nwattana          #+#    #+#             */
/*   Updated: 2022/09/03 21:08:30 by nwattana         ###   ########.fr       */
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
	UINT	size;
	t_list	*ta;
	t_list	*tb;
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

// action
t_list	*pop(t_list **head);
void	push(t_list **h, t_list *n);
void	px(t_list **h, t_list *x);
void	swap(t_list **ta);
void	rx(t_list **ta);
void	rrx(t_list **ta);
#endif

