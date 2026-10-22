/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 10:18:00 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/22 19:22:42 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Display an error message
 *
 * @param msg Message to display after the error prefix
 */
int	print_error(const char *msg)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (msg)
	{
		ft_putstr_fd((char *)msg, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	return (HAS_ERROR);
}
