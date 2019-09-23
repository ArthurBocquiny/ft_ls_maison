/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbocqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:42:03 by arbocqui          #+#    #+#             */
/*   Updated: 2019/09/10 17:39:42 by arbocqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		ft_sort_file(char **name, int nb_f)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	i = 0;
	while (i < (nb_f - 1))
	{
		if (ft_strcmp(name[i + 1], name[i]) < 0)
		{
			tmp = name[i];
			name[i] = name[i + 1];
			name[i + 1] = tmp;
			i = 0;
		}
		i++;
	}
}

t_file		*ft_sort_lst_r(t_file *list)
{
	t_file	*cpy;
	t_file	*tmp;

	tmp = NULL;
	cpy = NULL;
	while (list)
	{
		tmp = list->next;
		list->next = cpy;
		cpy = list;
		list = tmp;
	}
	return (cpy);
}

void		ft_set_next(t_file **cpy, t_file **before, t_file **next)
{
	(*cpy)->next = (*next)->next;
	(*next)->next = *cpy;
	(*before) = *next;
	*next = (*cpy)->next;
}

int			ft_resort(t_file *cpy, t_file *before, t_file *next, t_file **first)
{
	int		i;

	i = 0;
	before = NULL;
	cpy = *first;
	next = cpy->next;
	while (next)
	{
		if ((cpy->next->time) > (cpy->time))
		{
			i = 1;
			if (before == NULL)
				*first = next;
			else
				before->next = next;
			ft_set_next(&cpy, &before, &next);
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

t_file		*ft_sort_lst_t(t_file *list)
{
	t_file	*cpy;
	t_file	*before;
	t_file	*next;
	t_file	*first;

	first = list;
	before = NULL;
	cpy = first;
	next = cpy->next;
	while (ft_resort(cpy, before, next, &first))
		;
	return (first);
}
