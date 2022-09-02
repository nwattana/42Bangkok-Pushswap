/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 04:33:35 by nwattana          #+#    #+#             */
/*   Updated: 2022/09/02 18:05:34 by nwattana         ###   ########.fr       */
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
void	get_input(int argc, char *argv[], t_prog *prog);
void	inputint(int argc, char *argv[], t_prog *prog);
void	inputstr(char *argv[], t_prog *prog);
int		isstrint(char *s);
#endif
