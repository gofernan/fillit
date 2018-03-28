/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillsq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 04:13:45 by alanter           #+#    #+#             */
/*   Updated: 2018/01/16 01:18:22 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	clean(t_linksq *sq)
{
	int i;

	i = -1;
	while (i++ < 3)
		sq->square[((sq->y)[i])][((sq->x)[i])] = '.';
}

void	startposition(t_linksq *sq)
{
	int i;

	i = 1;
	while (i < 4)
	{
		sq->x[i] -= sq->x[0];
		sq->y[i] -= sq->y[0];
		i++;
	}
	sq->x[0] -= sq->x[0];
	sq->y[0] -= sq->y[0];
}

void	reinitlist(t_linksq *sq, int tetnbr)
{
	while (tetnbr--)
	{
		sq->next->square = sq->square;
		sq = sq->next;
	}
}

void	squarelarger(t_linksq *sq)
{
	int i;

	i = 0;
	startposition(sq);
	while (i < *(sq->squaresize))
	{
		free(sq->square[i]);
		i++;
	}
	free(sq->square);
	*(sq->squaresize) = (*(sq->squaresize) + 1);
	sq->square = (char **)malloc(sizeof(char *) * (*(sq->squaresize) + 1));
	reinitlist(sq, sq->tetnbr - 1);
	initializesq(sq);
}

void	fillsq(t_linksq *sq)
{
	int mvdwn;
	int mvright;
	int back;

	mvdwn = 0;
	mvright = 0;
	back = 0;
	while (sq != NULL)
	{
		sq->ptrback = &back;
		if (filleach(sq, mvdwn, mvright))
			sq = sq->next;
		else if (sq->tetriletter == 'A')
			squarelarger(sq);
		else
		{
			startposition(sq);
			clean(sq->previous);
			sq = sq->previous;
			back = 1;
		}
	}
}
