/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:38:52 by qtran             #+#    #+#             */
/*   Updated: 2019/02/26 16:30:45 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <inttypes.h>
# include "../libft/libft.h"
# define DEF_SZ_X 8

typedef unsigned char	t_bool;

typedef struct			s_env
{
	char				conv;
	char				*conv_type;
	int					width;
	int					precision;
	t_bool				sharp;
	t_bool				zero;
	t_bool				minus;
	t_bool				plus;
	t_bool				space;
	t_bool				point;
}						t_env;

int						ft_printf(char *format, ...);
t_env					*init_env();
char					*ft_strnew_filled_char(int len, char c);
void					flag_sc(t_env *vn, char **str);
void					flag_unsigned_nbr(t_env *vn, char **buffer);
void					pad_left(char **buffer, int len, char c);
void					pad_right(char **bufer, int len, char c);
void					unsigning(char **buffer);
t_bool					is_flag(char c);
t_bool					is_width_precision(char c);
t_bool					is_conv_type(char c);
t_bool					is_conv(char c);
t_bool					set_conv_type(t_env *vn, char **fmt);
int						ft_nbr_len_intmax(intmax_t d);
void					ft_putnbr_to_buf_intmax(char **buffer,
		intmax_t n, int index);
void					set_conv(t_env *vn, char c);
void					set_flag(t_env *vn, char c);
void					set_width_precision(t_env *vn, char **fmt);
void					intdec_to_hex(char c, uintmax_t d, char **str);
void					intdec_to_oct(uintmax_t d, char **str);
void					print_s(t_env *vn, va_list args, int *i);
void					print_d(t_env *vn, va_list args, int *i);
void					print_u(t_env *vn, va_list args, int *i);
void					print_c(t_env *vn, va_list args, int *i);
void					print_p(t_env *vn, va_list args, int *i);
void					print_x(t_env *vn, va_list args, int *i);
void					print_o(t_env *vn, va_list args, int *i);
void					print_f(t_env *vn, va_list args, int *i);
void					print_percent(t_env *vn, int *i);
void					setuping(int dk, intmax_t *d, char **str, int *c);
void					ft_error(char *str_error);
void					ft_clr(char **buffer);
void					ft_minus_f(char **str, int len, char c);
void					process_main(char **fmt_ptr,
		va_list args, int *c_printed_ptr);

#endif
