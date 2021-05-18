/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 01:57:59 by caugusta          #+#    #+#             */
/*   Updated: 2021/04/19 22:16:54 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	size_t	i;
	char	*strfind;

	i = 0;
	strfind = (char *)str;
	while (strfind[i] != '\0')
	{
		if (strfind[i] == ch)
			return (strfind + i);
		i++;
	}
	if (ch == '\0')
		return (strfind + i);
	return (0);
}
