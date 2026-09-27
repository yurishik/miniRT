/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 10:18:00 by yurishik          #+#    #+#             */
/*   Updated: 2026/09/27 10:43:03 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief エラー文言の表示
 *
 * @param msg 続けて表示するメッセージ
 */
int print_error(const char *msg)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (msg)
	{
		ft_putstr_fd((char *)msg, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	return (HAS_ERROR);
}
