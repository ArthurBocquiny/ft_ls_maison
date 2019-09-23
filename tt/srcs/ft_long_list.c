/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbocqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:27:16 by arbocqui          #+#    #+#             */
/*   Updated: 2019/09/23 18:25:18 by arbocqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		show_time(char *time)
{
	int		i;

	i = 4;
	while (i != 16)
	{
		ft_putchar(time[i]);
		i++;
	}
}

void		ft_putstr_space(char *str)
{
	ft_putstr(str);
	ft_putchar(' ');
}

int			find_total(t_file *file)
{
	int		total;

	total = 0;
	while (file)
	{
		total += file->st_blocks;
		file = file->next;
	}
	return (total);
}

void		ft_show_long_list(t_file *file)
{
	t_group		*gid;
	t_passwd	*uid;
	char		*time;

	ft_putstr("total ");
	ft_putnbr(find_total(file));
	ft_putchar('\n');
	while (file)
	{
		check_file_mode(file);
		check_file_perm_user(file);
		check_file_perm_grp(file);
		check_file_perm_other(file);
		ft_putnbr(file->st_nlink);
		ft_putchar(' ');
		uid = getpwuid(file->st_uid);
		ft_putstr_space(uid->pw_name);
		gid = getgrgid(file->st_gid);
		ft_putstr_space(gid->gr_name);
		ft_putnbr(file->st_size);
		ft_putchar(' ');
		time = ctime(&(file->time));
		show_time(time);
		ft_putchar(' ');
		ft_putstr(file->name);
		ft_putchar('\n');
		file = file->next;
	}
}
