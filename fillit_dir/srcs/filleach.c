/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filleach.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 04:18:17 by alanter           #+#    #+#             */
/*   Updated: 2018/01/16 01:12:34 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	put_tetri(t_linksq *sq, int mvdwn, int mvright)
{
	int i;

	i = 0;
	while (i < 4)
	{
		sq->square[((sq->y)[i]) + mvdwn][((sq->x)[i]) + mvright] =
			sq->tetriletter;
		sq->y[i] = sq->y[i] + mvdwn;
		sq->x[i] = sq->x[i] + mvright;
		i++;
	}
}

void	moveleft(t_linksq *sq)
{
	int i;

	i = 1;
	while (sq->x[0])
	{
		while (i <= 3)
		{
			sq->x[i] = sq->x[i] - sq->x[0];
			i++;
		}
		sq->x[0] -= sq->x[0];
	}
}

int		filleach2(t_linksq *sq, int *ptrd, int *ptrr, int *pi)
{
	if (*(sq->ptrback) == 1)
	{
		*(sq->ptrback) = 0;
	}
	if ((((sq->x)[*pi]) + ++(*ptrr)) < (*(sq->squaresize)))
	{
		*pi = 0;
	}
	else if ((((sq->y)[*pi]) + ++(*ptrd)) < (*(sq->squaresize)))
	{
		*pi = 0;
		*ptrr = 0;
		moveleft(sq);
	}
	else
		return (0);
	return (1);
}

int		filleach(t_linksq *sq, int mvdwn, int mvright)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (!((((sq->y)[i]) + mvdwn) < (*(sq->squaresize))))
			return (0);
		if ((sq->square[(((sq->y)[i]) + mvdwn)][(((sq->x)[i]) + mvright)] ==
					'.') && *(sq->ptrback) == 0)
		{
			if (i++ == 3)
				put_tetri(sq, mvdwn, mvright);
		}
		else if (!(filleach2(sq, &mvdwn, &mvright, &i)))
			return (0);
	}
	return (1);
}
