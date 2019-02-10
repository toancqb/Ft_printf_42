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
# include "../libft/libft.h"


typedef unsigned char bool;

typedef struct s_env
{
    char conv;
    char *conv_type;
    int width;
    int precision;
    bool sharp;
    bool zero;
    bool minus;
    bool plus;
    bool space;
    bool point;
} t_env;

t_env *init_env(); void test_display_env(t_env *vn); //
bool is_flag(char c);
bool is_conv_type(char c);
bool is_conv(char c);
void process_main(char **fmt_ptr, va_list args, int *c_printed_ptr);


#endif
