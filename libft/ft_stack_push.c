/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:20:56 by qtran             #+#    #+#             */
/*   Updated: 2018/07/02 23:14:42 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stack_push(t_list **st, t_list *new_elem)
{
	t_list *tmp;

	if (st)
	{
		if (*st == NULL)
		{
			*st = new_elem;
		}
		else
		{
			tmp = *st;
			while (tmp->next)
			{
				tmp = tmp->next;
			}
			tmp->next = new_elem;
		}
	}
}
