/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitutils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha < mtiesha@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:40:58 by mtiesha           #+#    #+#             */
/*   Updated: 2022/06/22 19:38:25 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	ft_spldup - calloc and copy char **array
	ft_spllen - count strings
	ft_splfree - free array an arrays
	ft_splarrfree - free arrays an arrays
*/

void	ft_splfree(char **split)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	if (!split)
		return ;
	while (split[i])
		i++;
	while (k < i)
	{
		free(split[k]);
		split[k] = NULL;
		k++;
	}
	free(split);
	split = NULL;
}

void	ft_splarrfree(char ***a_spl)
{
	int	i;

	i = 0;
	while (a_spl[i])
	{
		ft_splfree(a_spl[i]);
		i++;
	}
	free(a_spl);
	a_spl = NULL;
}

int	ft_spllen(char **split)
{
	int	len;

	if (!split)
		return (-1);
	len = 0;
	while (split[len])
		len++;
	return (len);
}

char	**ft_spldup(char **split)
{
	char	**ret;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!split)
		return (NULL);
	while (split[len])
		len++;
	ret = (char **)(ft_calloc(sizeof(char *), len + 1));
	while (split[i])
	{
		ret[i] = ft_strdup(split[i]);
		i++;
	}
	return (ret);
}
