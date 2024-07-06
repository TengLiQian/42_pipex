/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                   :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:30:39 by lteng             #+#    #+#             */
/*   Updated: 2023/09/16 16:30:40 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*current;
	t_list	*new_list;
	t_list	*new_elem;

	if (!lst || !del || !lst)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		current = f((*lst).content);
		new_elem = ft_lstnew(current);
		if (!new_elem)
		{
			if (current)
				del(current);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_elem);
		lst = (*lst).next;
	}
	return (new_list);
}
