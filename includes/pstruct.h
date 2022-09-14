/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pstruct.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 05:41:49 by nwattana          #+#    #+#             */
/*   Updated: 2022/09/14 22:25:45 by nwattana         ###   ########.fr       */
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


// csi base chunk size 
// ngrp chunk amount
// bo chunk boundery
// to path to first chunk member
// way ?? 
// cma chunk member amount
typedef struct	s_msort
{
	int		csi;
	int		ngrp;

	int		*bo;
	int		*to_f;
	int		*way;
	int		*cma;

	int		*ata;
	int		size_a;
	int		*atb;
	int		size_b;

}		t_ms;

#endif
