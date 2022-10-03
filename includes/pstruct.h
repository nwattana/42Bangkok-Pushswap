/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pstruct.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 05:41:49 by nwattana          #+#    #+#             */
/*   Updated: 2022/10/04 01:46:37 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSTRUCT_H
# define PSTRUCT_H

# include "libft.h"

/*
 * value
 * position
 * group
 * auxilary
 * */
typedef struct s_cont
{
	int	val;
	int	po;
	int	grp;
	int	au;
}			t_cont;
/*
 * fr front
 * re rear
 * unsigned int size
 */
typedef struct s_q
{
	t_list	*fr;
	t_list	*re;
	UINT	size;
}			t_q;


/* stack stk
 * unsigned int size
 */
typedef struct s_st
{
	t_list	*stk;
	UINT	size;
}			t_st;

typedef enum e_act
{
	none,
	pa,pb,
	sa,sb,ss,
	ra,rb,rr,
	rra,rrb,rrr
}		t_act;


typedef struct s_sres
{
	t_act	sta[10];
	UINT	size_a;
	t_act	stb[10];
	UINT	size_b;
}			t_sres;

// finish_a = all member chunk have move to b
typedef struct	s_chunk_info
{
	int	index;
	int	lower;
	int	upper;
	int	size;
	// for b to a
	int	inb;
	int ina;
	int	passb;
	int	passa;
}			t_ch;

// last_p lowest number will remaining in A
// ngrp amount of chunk Careful index for array
// p_top Top chunk is process
// p_bot bot chunk is process
typedef struct	s_medium_sort
{
	int	last_p;
	int	ngrp;
	int	p_top;
	int p_bot;

	t_ch *ch;
}		t_ms;

#endif
