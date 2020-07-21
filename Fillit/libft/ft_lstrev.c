/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eidaho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:37:03 by eidaho            #+#    #+#             */
/*   Updated: 2019/11/08 08:53:17 by eidaho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstrev(t_list *list)
{
	t_list	*curr;
	t_list	*prev;
	t_list	*next;

	prev = NULL;
	curr = list;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	list = prev;
	return (list);
}
