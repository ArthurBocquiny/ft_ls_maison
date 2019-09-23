/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:45:10 by yodana            #+#    #+#             */
/*   Updated: 2018/12/04 15:31:42 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\f' || c == '\n' || c == '\r'
			|| c == '\v')
		return (1);
	return (0);
}
