/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 17:10:41 by gofernan          #+#    #+#             */
/*   Updated: 2018/01/23 18:31:01 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	tetricount(t_linksq *sq)
{
	sq->tetnbr = (ft_strlen(sq->buff) / 21) + 1;
}

int		ft_ors(int argc, char **argv, t_linksq *sq)
{
	int		fd;
	int		numr;

	if (argc != 2)
	{
		write(2, "usage: ./fillit source_file\n", 28);
		exit(0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (-1);
	if ((numr = read(fd, sq->buff, 546)) < 0)
		return (-1);
	tetricount(sq);
	return (0);
}
