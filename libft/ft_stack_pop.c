/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:21:01 by qtran             #+#    #+#             */
/*   Updated: 2017/11/20 10:57:35 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		pop(void *c, t_list **tmp)
{
	ft_memcpy(c, (*tmp)->content, (*tmp)->content_size);
	ft_stack_clr(tmp);
}

void			*ft_stack_pop(t_list **st)
{
	t_list	*tmp;
	t_list	*tmp2;
	void	*c;

	tmp = *st;
	if (!(*st) || !(c = (void *)malloc(sizeof(void) * tmp->content_size)) || !c)
		return (NULL);
	if (tmp->next == NULL)
	{
		pop(c, &tmp);
		*st = NULL;
	}
	else
	{
		tmp2 = tmp->next;
		while (tmp2->next)
		{
			tmp2 = tmp2->next;
			tmp = tmp->next;
		}
		pop(c, &tmp2);
		tmp->next = NULL;
	}
	return (c);
}
