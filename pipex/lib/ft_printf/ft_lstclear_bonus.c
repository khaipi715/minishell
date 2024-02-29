/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaturzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:33:03 by npaturzo          #+#    #+#             */
/*   Updated: 2023/07/26 21:25:24 by npaturzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*pos;

	if (*lst == NULL || del == NULL)
		return ;
	pos = *lst;
	while (pos != NULL)
	{
		ft_lstdelone(pos, del);
		pos = pos->next;
	}
	*lst = NULL;
}
