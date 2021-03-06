/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:39:18 by qtran             #+#    #+#             */
/*   Updated: 2019/02/26 14:54:18 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	processing(t_env *vn, va_list args, int *i)
{
	if (vn->conv == 's')
		print_s(vn, args, i);
	else if (vn->conv == 'd' || vn->conv == 'i')
		print_d(vn, args, i);
	else if (vn->conv == 'u' || vn->conv == 'U')
		print_u(vn, args, i);
	else if (vn->conv == 'c')
		print_c(vn, args, i);
	else if (vn->conv == 'p')
		print_p(vn, args, i);
	else if (vn->conv == 'x' || vn->conv == 'X')
		print_x(vn, args, i);
	else if (vn->conv == 'o')
		print_o(vn, args, i);
	else if (vn->conv == 'f')
		print_f(vn, args, i);
	else if (vn->conv == '%')
		print_percent(vn, i);
}

void	process_main(char **fmt_ptr, va_list args, int *c_printed_ptr)
{
	t_env	*vn;
	char	*fmt_cpy;
	int		len;

	len = 0;
	vn = init_env();
	fmt_cpy = ++(*fmt_ptr);
	while (is_flag(*fmt_cpy))
	{
		set_flag(vn, *fmt_cpy);
		fmt_cpy++;
	}
	if (is_width_precision(*fmt_cpy))
		set_width_precision(vn, &fmt_cpy);
	set_conv_type(vn, &fmt_cpy);
	len += (int)(fmt_cpy - *fmt_ptr);
	if (is_conv(*fmt_cpy))
		set_conv(vn, *fmt_cpy);
	else
		ft_error("invalid conversion");
	processing(vn, args, c_printed_ptr);
	*fmt_ptr += len + 1;
	if (vn->conv_type)
		free(vn->conv_type);
	free(vn);
}
