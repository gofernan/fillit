/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:03:45 by alanter           #+#    #+#             */
/*   Updated: 2018/01/16 01:31:25 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_linksq
{
	int				*squaresize;
	int				tetnbr;
	char			buff[546];
	char			**square;
	char			tetriletter;
	int				x[4];
	int				y[4];
	int				*ptrback;

	struct s_linksq	*next;
	struct s_linksq	*previous;
}				t_linksq;

int				main(int argc, char **argv);
void			printsq(t_linksq sqtoprt);
void			initializesq(t_linksq *fstsq);
int				ft_ors(int argc, char **argv, t_linksq *ptrs);
int				checksq(char *file);
int				checktetri(char *file, t_linksq *sq);
void			fillsq(t_linksq *square);
int				filleach(t_linksq *sq, int mvdwn, int mvright);
void			initlist(t_linksq	*sq);
#endif
