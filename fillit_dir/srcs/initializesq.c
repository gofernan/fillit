/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializesq.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 21:40:25 by alanter           #+#    #+#             */
/*   Updated: 2018/01/16 00:05:56 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	initializesq(t_linksq *fstsq)
{
	int		i;
	int		j;
	char	**square;

	j = *(fstsq->squaresize);
	i = 0;
	square = fstsq->square;
	while (i < j)
	{
		square[i] = ft_memalloc(j + 1);
		ft_memset(square[i], '.', j);
		i++;
	}
}
