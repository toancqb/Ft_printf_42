/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:05:13 by qtran             #+#    #+#             */
/*   Updated: 2017/11/15 18:12:30 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst)
{
	t_list *tmp;
	t_list *d;

	if (alst)
	{
		tmp = *alst;
		while (tmp)
		{
			d = tmp;
			tmp = tmp->next;
			ft_lstdelone(&d);
		}
		*alst = NULL;
	}
}
