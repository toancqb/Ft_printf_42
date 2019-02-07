/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:47:55 by qtran             #+#    #+#             */
/*   Updated: 2018/07/02 23:15:17 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **lst, t_list *new_elem)
{
	t_list *tmp;

	if (lst)
	{
		if (*lst == NULL)
		{
			*lst = new_elem;
			(*lst)->next = 0;
		}
		else
		{
			tmp = *lst;
			*lst = new_elem;
			new_elem->next = tmp;
		}
	}
}
