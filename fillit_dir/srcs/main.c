/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 21:39:47 by alanter           #+#    #+#             */
/*   Updated: 2018/01/22 14:57:49 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	t_linksq	*sq;
	int			sqsizev;

	sq = (t_linksq*)malloc(sizeof(t_linksq));
	if (ft_ors(argc, argv, sq) == -1)
	{
		write(1, "error\n", 6);
		exit(0);
	}
	sqsizev = 2;
	sq->squaresize = &sqsizev;
	initlist(sq);
	if (!((checksq(sq->buff)) && checktetri(sq->buff, sq)))
	{
		write(1, "error\n", 6);
		exit(0);
	}
	fillsq(sq);
	printsq(*sq);
	return (0);
}
