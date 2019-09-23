/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbocqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 17:33:10 by arbocqui          #+#    #+#             */
/*   Updated: 2019/09/23 17:33:18 by arbocqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_error_files(char *name)
{
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
}

void	ft_error_flags(char name)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(name, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("usage: ls [-lRart] [file ...]\n", 2);
	exit(EXIT_FAILURE);
}
