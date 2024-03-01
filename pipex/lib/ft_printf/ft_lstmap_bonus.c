/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaturzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:15:56 by npaturzo          #+#    #+#             */
/*   Updated: 2023/07/26 21:27:26 by npaturzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*new;
	int		first;

	first = 1;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (first == 1)
		{
			ret = new;
			first = 0;
		}
		if (new == NULL)
		{
			ft_lstclear(&ret, del);
			return (NULL);
		}
		if (first == 0)
			ft_lstadd_back(&ret, new);
		lst = lst->next;
	}
	return (ret);
}
