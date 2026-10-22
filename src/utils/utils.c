/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 11:12:51 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/22 19:11:45 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Check whether a character is whitespace
 *
 * @param c
 * @return TRUE/FALSE
 */

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (TRUE);
	return (FALSE);
}

/**
 * @brief Remove the trailing \n from a line returned by get_next_line
 *
 * @param fd
 * @return The line with its trailing \n removed
 */
char	*get_next_line_trim(int fd)
{
	char	*line;
	size_t	len;

	line = get_next_line(fd);
	if (line == NULL)
		return (NULL);
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}

/**
 * @brief Free an array of strings
 *
 * @param arr The array to free
 */
void	free_str_array(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

/**
 * @brief Handle the fractional part separately (for Norminette)
 */
static double	parse_fraction(const char *str)
{
	double	fraction;
	double	factor;

	fraction = 0.0;
	factor = 0.1;
	while (ft_isdigit(*str))
	{
		fraction += (*str++ - '0') * factor;
		factor *= 0.1;
	}
	return (fraction);
}

/**
 * @brief Convert a string to a double
 */
double	ft_atof(const char *str)
{
	double	result;
	double	sign;

	result = 0.0;
	sign = 1.0;
	if (!str)
		return (0.0);
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign = -1.0;
	}
	while (ft_isdigit(*str))
		result = result * 10.0 + (*str++ - '0');
	if (*str == '.')
		result += parse_fraction(str + 1);
	return (result * sign);
}
