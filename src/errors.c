/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dghonyan <dghonyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:01:13 by dghonyan          #+#    #+#             */
/*   Updated: 2022/09/25 14:24:46 by dghonyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error(char *msg, int syscall)
{
	if (syscall)
		perror(msg);
	else
		ft_putendl_fd(msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	file_error(char *s)
{
	ft_putstr_fd("error: `", STDERR_FILENO);
	ft_putstr_fd(s, STDERR_FILENO);
	ft_putstr_fd("': ", STDERR_FILENO);
	error("", 1);
}
