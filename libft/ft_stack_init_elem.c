/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_initElem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:28:52 by qtran             #+#    #+#             */
/*   Updated: 2017/11/20 10:46:15 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_stack_init_elem(void const *content, size_t content_size)
{
	t_list *st;

	if (!(st = (t_list *)malloc(sizeof(t_list))) || !st)
		return (NULL);
	if (!content)
	{
		st->content = NULL;
		st->content_size = 0;
	}
	else
	{
		if (!(st->content = (void *)malloc(sizeof(void) * (content_size))))
			return (NULL);
		ft_memcpy(st->content, content, content_size);
		st->content_size = content_size;
	}
	st->next = NULL;
	return (st);
}
