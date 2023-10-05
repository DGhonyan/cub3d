/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dghonyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:07:39 by dghonyan          #+#    #+#             */
/*   Updated: 2022/07/16 18:07:45 by dghonyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst)
		return ;
	temp = *lst;
	if (!(*lst))
	{
		(*lst) = new;
		return ;
	}
	while ((*lst)->next)
		(*lst) = (*lst)->next;
	(*lst)->next = new;
	*lst = temp;
}
