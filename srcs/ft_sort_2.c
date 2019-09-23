/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbocqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 18:58:49 by arbocqui          #+#    #+#             */
/*   Updated: 2019/09/23 19:11:15 by arbocqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			ft_set_next_2(t_file **cpy, t_file **before, t_file **next)
{
	(*cpy)->next = (*next)->next;
	(*next)->next = *cpy;
	(*before) = *next;
	*next = (*cpy)->next;
}

int				ft_resort_2(t_file *cpy, t_file *before, t_file *next
							, t_file **first)
{
	int			i;

	i = 0;
	before = NULL;
	cpy = *first;
	next = cpy->next;
	while (next)
	{
		if (ft_strcmp(cpy->next->name, cpy->name) < 0)
		{
			i = 1;
			if (before == NULL)
				*first = next;
			else
				before->next = next;
			ft_set_next_2(&cpy, &before, &next);
		}
		else
		{
			before = cpy;
			cpy = cpy->next;
			next = cpy->next;
		}
	}
	return (i);
}

t_file        *ft_sort_lst_alpha(t_file *list)
{
	t_file    *cpy;
	t_file    *before;
	t_file    *next;
	t_file    *first;

	first = list;
	before = NULL;
	cpy = first;
	next = cpy->next;
	while (ft_resort_2(cpy, before, next, &first))
		;
	return (first);
}
