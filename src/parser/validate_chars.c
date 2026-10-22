/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 11:20:13 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/22 19:41:07 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Check whether a line is blank
 *
 * @param line 
 * @return TRUE if blank, otherwise FALSE
 */
int	is_blank_line(const char *line)
{
	size_t	i;

	if (!line)
		return (TRUE);
	i = 0;
	while (line[i])
	{
		if (!ft_isspace(line[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

/**
 * @brief Check whether a character is allowed
 *
 * @param c
 * @return TRUE if allowed, otherwise FALSE
 */
int	is_allowed_char(char c)
{
	if (ft_strchr("ACLsplcy0123456789+-. ,\n\f\r\t\v", c))
		return (TRUE);
	return (FALSE);
}

/**
 * @brief Check whether all characters in a line are allowed
 *
 * @param line
 * @return TRUE if all characters are allowed, otherwise FALSE
 */
int	is_valid_chars_line(const char *line)
{
	size_t	i;

	if (!line)
		return (FALSE);
	i = 0;
	while (line[i])
	{
		if (!is_allowed_char(line[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}
