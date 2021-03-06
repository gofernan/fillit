/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 16:52:31 by alanter           #+#    #+#             */
/*   Updated: 2017/12/03 16:52:52 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (ft_isupper(str[i]) == 1 && str != 0)
		i++;
	if (str[i] == 0)
		return (1);
	return (0);
}
