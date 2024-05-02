/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sigunay <sigunay@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 08:54:37 by sigunay           #+#    #+#             */
/*   Updated: 2024/05/02 17:03:10 by sigunay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	char	**ft_free2(char **strs, int i)
{
	while (i-- > 0)
		free(strs[i]);
	free(strs);
	return (NULL);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start >= s_len || len <= 0)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	s2 = (char *)malloc(len + 1);
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s + start, len + 1);
	return (s2);
}

static int	word_counter(char const *s, char c)
{
	int	i;
	int	counter;
	int	j;

	i = 0;
	j = 0;
	counter = 0;
	while (s[i])
	{
		if (s[i] != c && j == 0)
		{
			counter++;
			j = 1;
		}
		else if (s[i] == c)
			j = 0;
		i++;
	}
	return (counter);
}

static	int	ft_size_word(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	char	**new_list;
	int		len;
	int		i;
	int		j;

	j = 0;
	i = 0;
	len = word_counter(s, c);
	new_list = (char **)malloc(sizeof(char *) * (len + 1));
	if (!new_list)
		return (NULL);
	while (j < len)
	{
		while (s[i] == c)
			i++;
		new_list[j] = ft_substr(s, i, ft_size_word(s, c, i));
		if (!(new_list[j]))
			return (ft_free2(new_list, j));
		i += ft_size_word(s, c, i);
		j++;
	}
	new_list[j] = NULL;
	return (new_list);
}
