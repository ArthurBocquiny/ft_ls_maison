/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbocqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 17:46:49 by arbocqui          #+#    #+#             */
/*   Updated: 2019/09/10 14:30:43 by arbocqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_file	*ft_create_file(char *name_file, t_stat *stat, char path[PATH_MAX])
{
	t_file	*created;

	if (!(created = (t_file*)malloc(sizeof(t_file)))
	|| (!(created->name = ft_strdup(name_file)))
	|| (!(created->path = ft_strdup(ft_strjoin(path, name_file)))))
		ft_error_files(NULL);
	created->st_mode = stat->st_mode;
	created->st_nlink = stat->st_nlink;
	created->st_uid = stat->st_uid;
	created->st_gid = stat->st_gid;
	created->st_size = stat->st_size;
	created->st_rdev = stat->st_rdev;
	created->time = stat->st_mtimespec.tv_sec;
	created->ntime = stat->st_mtimespec.tv_nsec;
	created->st_blocks = stat->st_blocks;
	created->next = NULL;
	return (created);
}

int		ft_created_file(char *f_name, t_file **lst_files,
		t_file **start, char *path)
{
	t_stat	files_stat;
	char	*temp;

	temp = ft_strjoin(path, f_name);
	if (lstat(temp, &files_stat) == -1)
	{
		ft_error_files(temp);
		return (-1);
	}
	if (!*lst_files)
	{
		*lst_files = ft_create_file(f_name, &files_stat, path);
		*start = *lst_files;
	}
	else
	{
		while ((*lst_files)->next)
		{
			*lst_files = (*lst_files)->next;
		}
		(*lst_files)->next = ft_create_file(f_name, &files_stat, path);
	}
	return (1);
}

t_file	*ft_add_file(int nbr_file, char **files)
{
	int		i;
	t_file	*lst_files;
	t_file	*start;

	i = -1;
	lst_files = NULL;
	if (nbr_file == 0)
	{
		if (!(ft_created_file(".", &lst_files, &start, "")))
			return (NULL);
	}
	else
		ft_sort_file(files, nbr_file);
	while (++i < nbr_file)
	{
		if (!(ft_created_file(files[i], &lst_files, &start, "")))
			return (NULL);
	}
	return (start);
}
