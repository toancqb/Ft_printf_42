/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:38:52 by qtran             #+#    #+#             */
/*   Updated: 2019/02/10 15:38:54 by qtran            ###   ########.fr       */
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

typedef unsigned char t_bool;
typedef long long t_long;

typedef struct s_env
{
    char conv;
    char *conv_type;
    int width;
    int precision;
    t_bool sharp;
    t_bool zero;
    t_bool flag_zero;
    t_bool minus;
    t_bool plus;
    t_bool space;
    t_bool point;
} t_env;

t_env *init_env(); void test_display_env(t_env *vn); //
char *ft_strnew_filled_char(int len, char c);
void flag_s(t_env *vn, char **str);
void sharp_xXo(char *str1, char **str2);
void pad_left(char **buffer, int len, char c);
void pad_right(char **bufer, int len, char c);
t_bool is_flag(char c);
t_bool is_width_precision(char c);
t_bool is_conv_type(char c);
t_bool is_conv(char c);
t_bool set_conv_type(t_env *vn, char **fmt);
void set_conv(t_env *vn, char c);
void set_flag(t_env *vn, char c);
void set_width_precision(t_env *vn, char **fmt);
void intdec_to_hex(char c, uintmax_t d, char **str);
void intdec_to_oct(uintmax_t d, char **str);
void print_s(t_env *vn, va_list args, int *i);
void print_d(t_env *vn, va_list args, int *i);
void print_uU(t_env *vn, va_list args, int *i);
void print_c(t_env *vn, va_list args, int *i);
void print_p(t_env *vn, va_list args, int *i);
void print_xX(t_env *vn, va_list args, int *i);
void print_o(t_env *vn, va_list args, int *i);
void print_f(t_env *vn, va_list args, int *i);
void print_percent(int *i);

void ft_error(char *str_error);
void process_main(char **fmt_ptr, va_list args, int *c_printed_ptr);


#endif
