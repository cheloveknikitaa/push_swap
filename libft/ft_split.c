/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:49:34 by caugusta          #+#    #+#             */
/*   Updated: 2021/04/23 14:27:48 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	counts(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != c && *s != '\0')
			count++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (count);
}

static size_t	lengstr(char const **s, char c)
{
	size_t	count;

	count = 0;
	while (**s != c && **s != '\0')
	{
		count++;
		(*s)++;
	}
	return (count);
}

static void	cs_2d_arr(char **s, size_t count)
{
	while (count >= 0)
	{
		free(s[count]);
		s[count] = NULL;
		count--;
	}
	free (s);
	s = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**splits;
	size_t	count;
	size_t	maxcounts;

	if (s == NULL)
		return (NULL);
	splits = malloc(sizeof(char *) * (counts(s, c) + 1));
	if (splits == NULL)
		return (NULL);
	count = 0;
	maxcounts = counts(s, c);
	while (*s != '\0' && count < maxcounts)
	{
		while (*s == c)
			s++;
		splits[count] = ft_substr(s, 0, lengstr(&s, c));
		if (splits[count] == NULL)
		{
			cs_2d_arr(splits, count - 1);
			return (NULL);
		}
		count++;
	}
	splits[count] = NULL;
	return (splits);
}
