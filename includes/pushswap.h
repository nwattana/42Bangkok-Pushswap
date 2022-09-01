/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 04:33:35 by nwattana          #+#    #+#             */
/*   Updated: 2022/09/02 04:44:31 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include "libftprintf.h"


typedef struct s_prog
{
	t_list	*stack_a;
	t_list	*stack_b;
}		t_prog;


t_prog	*prog_init(void);

#endif
