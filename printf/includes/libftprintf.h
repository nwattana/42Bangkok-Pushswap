/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:52:37 by nwattana          #+#    #+#             */
/*   Updated: 2022/04/22 07:07:02 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef struct s_format
{
	int	zero;
	int	space;
	int	plus;
	int	left;
	int	hash;
	int	dot;
	int	afterdot;
	int	beforedot;
	int	signed_num;
	int	zero_value;
	int	space_area;
	int	print_0;
	int	char_type;
}			t_format;

int		format_collect(char *str, t_format *f1);
int		ft_printf(const char *str, ...);
int		ft_isin(char str, char *set, int len);
int		put_format(va_list v1, t_format *f1);
int		put_c(char c, t_format *f1);
int		put_s(char *str, t_format *f1);
int		put_di(int number, t_format *f1);
int		put_format_di(int number, t_format *f1);
int		put_x(unsigned int number, t_format *f1);
int		put_x_p(unsigned long long number, t_format *f1);
int		put_p(unsigned long long number, t_format *f1);
int		put_u(unsigned int number, t_format *f1);
int		put_percent(t_format *f1);
int		number_base_len(unsigned int num, unsigned int base, t_format *f1);
int		number_base_len_p(unsigned long long num, unsigned int b, t_format *f);
char	*ft_itoa_uint(unsigned int number, int len);
char	*ft_itoa_hexa(unsigned int number, int len, t_format *f1);
char	*ft_itoa_hexa_p(unsigned long long number, int len, t_format *f1);
int		put_charloop(char a, int timse);

#endif
