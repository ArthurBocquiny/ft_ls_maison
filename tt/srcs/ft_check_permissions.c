/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_permissions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbocqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:41:24 by arbocqui          #+#    #+#             */
/*   Updated: 2019/09/23 18:00:14 by arbocqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	check_file_mode(t_file *file)
{
	if (S_ISREG(file->st_mode))
		ft_putchar('-');
	else if (S_ISDIR(file->st_mode))
		ft_putchar('d');
	else if (S_ISBLK(file->st_mode))
		ft_putchar('b');
	else if (S_ISCHR(file->st_mode))
		ft_putchar('c');
	else if (S_ISFIFO(file->st_mode))
		ft_putchar('p');
	else if (S_ISLNK(file->st_mode))
		ft_putchar('l');
	else if (S_ISSOCK(file->st_mode))
		ft_putchar('s');
}

void	check_file_perm_user(t_file *file)
{
	if (S_IRUSR & file->st_mode)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (S_IWUSR & file->st_mode)
		ft_putchar('w');
	else
		ft_putchar('-');
	if ((S_IXUSR & file->st_mode) && !(S_ISUID & file->st_mode))
		ft_putchar('x');
	else if ((S_IXUSR & file->st_mode) && (S_ISUID & file->st_mode))
		ft_putchar('s');
	else if (!(S_IXUSR & file->st_mode) && (S_ISUID & file->st_mode))
		ft_putchar('S');
	else
		ft_putchar('-');

}

void	check_file_perm_grp(t_file *file)
{
	if (S_IRGRP & file->st_mode)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (S_IWGRP & file->st_mode)
		ft_putchar('w');
	else
		ft_putchar('-');
	if ((S_IXGRP & file->st_mode) && !(S_ISUID & file->st_mode))
		ft_putchar('x');
	else if ((S_IXGRP & file->st_mode) && (S_ISUID & file->st_mode))
		ft_putchar('s');
	else if (!(S_IXGRP & file->st_mode) && (S_ISUID & file->st_mode))
		ft_putchar('S');
	else
		ft_putchar('-');
}

void	check_file_perm_other(t_file *file)
{
	if (S_IROTH & file->st_mode)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (S_IWOTH & file->st_mode)
		ft_putchar('w');
	else
		ft_putchar('-');
	if ((S_ISVTX & file->st_mode) && !(S_IXOTH & file->st_mode))
		ft_putchar('T');
	else if ((S_ISVTX & file->st_mode) && (S_IXOTH & file->st_mode))
		ft_putchar('t');
	else if (S_IXOTH & file->st_mode)
		ft_putchar('x');
	else
		ft_putchar('-');
	ft_putchar(' ');
}
