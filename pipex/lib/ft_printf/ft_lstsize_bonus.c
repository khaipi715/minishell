/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npaturzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:46:16 by npaturzo          #+#    #+#             */
/*   Updated: 2023/07/25 12:43:46 by npaturzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*pos;

	if (lst == NULL)
		return (0);
	i = 1;
	pos = lst;
	while (pos->next != NULL)
	{
		pos = pos->next;
		i++;
	}
	return (i);
}
