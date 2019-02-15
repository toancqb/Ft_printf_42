/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:39:18 by qtran             #+#    #+#             */
/*   Updated: 2019/02/10 15:39:19 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void processing(t_env *vn, va_list args, int *i)
{
	if (vn->conv == 's')
		print_s(args, i);
	else if (vn->conv == 'd' || vn->conv == 'i')
		print_d(args, i);
	else if (vn->conv == 'c')
		print_c(args, i);
	else if (vn->conv == 'p')
		print_p(args, i);
	else if (vn->conv == 'x' || vn->conv == 'X')
		print_xX(vn, args, i);
	else if (vn->conv == 'o')
		print_o(vn, args, i);
}

void	process_main(char **fmt_ptr, va_list args, int *c_printed_ptr)
{
	t_env *vn;
	char *fmt_cpy;

	vn = init_env();
	fmt_cpy = ++(*fmt_ptr);
	if (is_conv(*fmt_cpy))
		set_conv(vn, *fmt_cpy);
	else
		ft_error("invalid conversion");
	processing(vn, args, c_printed_ptr);
	*fmt_ptr += 1;

}
