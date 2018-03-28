/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printsq.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 22:13:58 by alanter           #+#    #+#             */
/*   Updated: 2018/01/14 00:04:25 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	printsq(t_linksq sqtoprt)
{
	int		i;
	int		j;
	char	**square;

	j = *(sqtoprt.squaresize);
	i = 0;
	square = sqtoprt.square;
	while (i < j)
	{
		ft_putstr(square[i]);
		ft_putstr("\n");
		i++;
	}
}
