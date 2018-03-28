/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checksq.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 04:22:52 by alanter           #+#    #+#             */
/*   Updated: 2018/01/17 19:28:09 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_len(char *file)
{
	size_t filelen;

	filelen = ft_strlen(file);
	if ((filelen < 20) || ((filelen > 20) && ((filelen + 1) % 21 != 0)))
		return (0);
	return (1);
}

int		check_sharpdot(char *file, int *sharp)
{
	int i;
	int a;
	int b;

	i = -1;
	a = 1;
	b = 1;
	while (file[++i] != '\0')
	{
		if (i % 21 == 0 && i != 0)
			a--;
		if (((i + a) % 5 == 0) || ((i + 1) % 21 == 0))
		{
			if (file[i] != '\n')
				return (0);
		}
		else if (file[i] != '#' && file[i] != '.')
			return (0);
		else if (file[i] == '#')
			(*sharp)++;
		if (((i == 18) || (i % 21 == 18)) && (!((*sharp / 4 == b++)
						&& (*sharp % 4 == 0))))
			return (0);
	}
	return (1);
}

int		checksq(char *file)
{
	int countsharp;

	countsharp = 0;
	if (!((check_len(file)) && check_sharpdot(file, &countsharp)))
		return (0);
	return (1);
}
