/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:59:37 by jerdos-s          #+#    #+#             */
/*   Updated: 2022/08/10 15:54:23 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_safe_lst_new(t_list **current, void *data)
{
	t_list	*tmp;

	tmp = ft_lstnew(data);
	if (!tmp)
	{
		*current = NULL;
		return (0);
	}
	*current = tmp;
	return (1);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current_new;
	t_list	*new_map_list;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	current_new = NULL;
	if (!ft_safe_lst_new(&tmp, f(lst->content)))
		return (NULL);
	ft_lstadd_back(&(current_new), tmp);
	new_map_list = current_new;
	lst = lst->next;
	while (lst)
	{
		if (!ft_safe_lst_new(&tmp, f(lst->content)))
		{
			ft_lstclear(&current_new, del);
			return (NULL);
		}
		ft_lstadd_back(&(current_new->next), tmp);
		lst = lst->next;
		current_new = current_new->next;
	}
	return (new_map_list);
}
