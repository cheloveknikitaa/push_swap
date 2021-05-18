/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 21:00:10 by caugusta          #+#    #+#             */
/*   Updated: 2021/04/19 21:52:06 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t len)
{
	unsigned char		*strc1;
	unsigned char		*strc2;

	strc1 = (unsigned char *)str1;
	strc2 = (unsigned char *)str2;
	while (len-- > 0)
	{
		if (*strc1 != *strc2 || !strc1 || !strc2)
			return (*strc1 - *strc2);
		strc1++;
		strc2++;
	}
	return (0);
}
