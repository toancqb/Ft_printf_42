/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 23:16:02 by qtran             #+#    #+#             */
/*   Updated: 2018/07/03 08:59:13 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		pop(void *c, t_list **tmp)
{
	ft_memcpy(c, (*tmp)->content, (*tmp)->content_size);
	ft_queue_clr(tmp);
}

void			*ft_queue_pop(t_list **st)
{
	t_list	*tmp;
	void	*c;

	tmp = *st;
	if (!(*st) || !(c = (void*)malloc(sizeof(void) * tmp->content_size)) || !c)
		return (NULL);
	*st = (*st)->next;
	pop(c, &tmp);
	return (c);
}
