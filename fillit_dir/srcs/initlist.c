/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initfstsq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 01:00:34 by alanter           #+#    #+#             */
/*   Updated: 2018/01/16 00:05:49 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	initnext(t_linksq *sq, int tetnbr)
{
	t_linksq *nextsq;

	if (tetnbr)
	{
		nextsq = (t_linksq*)malloc(sizeof(t_linksq));
		sq->next = nextsq;
		nextsq->previous = sq;
		nextsq->next = NULL;
		nextsq->squaresize = sq->squaresize;
		nextsq->square = sq->square;
		nextsq->tetriletter = ((sq->tetriletter) + 1);
		tetnbr--;
		initnext(nextsq, tetnbr);
	}
}

int		minsqsize(int nb)
{
	int a;

	a = 1;
	if (nb > 0)
	{
		while ((a * a < nb))
			a++;
		if (a * a == nb)
			return (a - 1);
		else
			return (a);
	}
	return (0);
}

void	initlist(t_linksq *sq)
{
	*sq->squaresize = minsqsize(sq->tetnbr * 4);
	sq->tetriletter = 'A';
	sq->next = NULL;
	sq->previous = NULL;
	sq->square = (char **)malloc(sizeof(char *) * (*(sq->squaresize) + 1));
	initializesq(sq);
	initnext(sq, sq->tetnbr - 1);
}
