#include "../includes/ft_ls.h"

t_file	*ft_open_dir(char *dir, int flags)
{
	DIR				*files;
	struct	dirent	*read;
	t_file			*lst_dir;
	t_file			*begin;

	begin = NULL;
	lst_dir = NULL;
	files = opendir(dir);
	if (files == NULL)
		return (NULL);
	while ((read = readdir(files)))
	{
		if (read->d_name[0] != '.' || (flags & LS_A))
			if (!(ft_created_file(read->d_name, &lst_dir, &begin
							, ft_strjoin(dir, "/"))))
				return (NULL);
	}
	if (files)
		closedir(files);
	begin = ft_sort_lst_alpha(begin);
	if (flags & LS_T)
		begin = ft_sort_lst_t(begin);
	if (flags & LS_R)
		begin = ft_sort_lst_r(begin);
	return (begin);
}

void	ft_show_files_short(t_file *file, int *i, char path[PATH_MAX])
{
	if (*i == -1)
	{
		*i = 0;
		while (file)
		{
			ft_putstr(file->name);
			if (file->next != NULL)
				ft_putstr(" ");
			file = file->next;
		}
	}
	else
	{
		ft_putstr("\n\n");
		ft_putstr(path);
		ft_putstr(":\n");
		while (file)
		{
			ft_putstr(file->name);
			if (file->next != NULL)
				ft_putstr(" ");
			file = file->next;
		}
	}
	ft_putstr("\n");
}

void	ft_show_files_long(t_file *file, int *i, char path[PATH_MAX])
{
	if (*i == -1)
	{
		*i = 0;
		ft_show_long_list(file);
	}
	else
	{
		ft_putstr("\n");
		ft_putstr(path);
		ft_putstr(":\n");
		ft_show_long_list(file);
	}
}

void	ft_show_files(t_file *file, int *i, char path[PATH_MAX], int flags)
{
	if (flags & LS_L)
		ft_show_files_long(file, i, path);
	else
		ft_show_files_short(file, i, path);
}

int		ft_show(t_file *file, int flags, int i)
{
	t_file				*cpy;

	cpy = file;
	while (cpy)
	{
		if (S_ISDIR(cpy->st_mode))
		{
			file = ft_open_dir(cpy->path, flags);
			if (ft_strcmp(cpy->name, ".") != 0
				&& ft_strcmp(cpy->name, "..") != 0)
				ft_show_files(file, &i, cpy->path, flags);
			if ((flags & LS_RR) && (i == -1 || (ft_strcmp(cpy->name, ".") != 0
				&& ft_strcmp(cpy->name, "..") != 0)))
			{
				ft_show(file, flags, i);
				//free
			}
		}
		cpy = cpy->next;
	}
	return (1);
}
