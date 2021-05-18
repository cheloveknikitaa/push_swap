/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 22:40:12 by caugusta          #+#    #+#             */
/*   Updated: 2021/04/20 03:49:15 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	size_t	i;
	size_t	j;
	size_t	g;
	char	*strfind;

	i = 0;
	j = 0;
	g = 0;
	strfind = (char *)str;
	while (strfind[i] != '\0')
	{
		if (strfind[i] == ch)
		{
			j = i;
			g++;
		}
		i++;
	}
	if (ch == '\0')
		return (strfind + i);
	if (g > 0)
		return (strfind + j);
	return (0);
}
