/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checktetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 23:05:35 by gofernan          #+#    #+#             */
/*   Updated: 2018/01/14 00:56:00 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		check_linked(int *x, int *y)
{
	int i;
	int j;
	int linked;

	i = -1;
	linked = 0;
	while (i++ < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (y[i] + 1 == y[j] && x[i] == x[j])
				linked++;
			if (y[i] - 1 == y[j] && x[i] == x[j])
				linked++;
			if (x[i] + 1 == x[j] && y[i] == y[j])
				linked++;
			if (x[i] - 1 == x[j] && y[i] == y[j])
				linked++;
			j++;
		}
	}
	if (linked == 6 || linked == 8)
		return (1);
	return (0);
}

void	store_tetri(t_linksq *sqcpy, int *x, int *y)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		sqcpy->y[i] = y[i] - y[0];
		sqcpy->x[i] = x[i] - x[0];
		i++;
	}
}

int		checker(char *file, t_linksq *sq, int *i, int *j)
{
	int			y[4];
	int			x[4];
	t_linksq	*sqcpy;

	sqcpy = sq;
	while (file[*i] != '\0')
	{
		if (file[*i] == '#')
		{
			y[*j] = (*i - (21 * (*i / 21))) / 5;
			x[*j] = (*i - (21 * (*i / 21))) % 5;
			*j += 1;
		}
		if (*j % 4 == 0 && *j != 0)
		{
			if (check_linked(x, y))
				store_tetri(sqcpy, x, y);
			else
				return (0);
			sqcpy = sqcpy->next;
			*j = 0;
		}
		*i += 1;
	}
	return (1);
}

int		checktetri(char *file, t_linksq *sq)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	return (checker(file, sq, &i, &j));
}
