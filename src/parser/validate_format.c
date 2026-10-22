/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 13:23:01 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/22 19:43:23 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <limits.h>

/**
 * @brief Validate the sign, integer, and fractional parts of a number
 *        (Allow up to 11 integer and 10 fractional digits // TODO provisional)
 * @return TRUE/FALSE
 */
int	is_valid_double_str(const char *str)
{
	int	dots;
	int	digits[2];

	if (!str || !*str)
		return (FALSE);
	if (*str == '+' || *str == '-')
		str++;
	while (*str == '0' && *(str + 1) != '.' && *(str + 1) != '\0')
		str++;
	if (!ft_isdigit(*str))
		return (FALSE);
	dots = 0;
	digits[0] = 0;
	digits[1] = 0;
	while (*str)
	{
		if (*str == '.' && (++dots > 1 || !ft_isdigit(*(str + 1))))
			return (FALSE);
		else if (ft_isdigit(*str))
			digits[dots]++;
		else if (*str != '.')
			return (FALSE);
		str++;
	}
	return (digits[0] <= 11 && digits[1] <= 10);
}

/**
 * @brief Check integer format and range from INT_MIN to INT_MAX
 */

int	is_valid_int_str(const char *str)
{
	int	sign;

	if (!str || !*str)
		return (FALSE);
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!*str)
		return (FALSE);
	return (check_int_digits(str, sign));
}

/**
 * @brief Validate three comma-separated floating-point values (x,y,z)
 */
int	is_valid_vector_format(const char *str)
{
	char	**split;
	int		is_valid;

	split = comma_split_elements(str, 3);
	if (!split)
		return (FALSE);
	is_valid = (is_valid_double_str(split[0]) && is_valid_double_str(split[1])
			&& is_valid_double_str(split[2]));
	free_str_array(split);
	return (is_valid);
}

/**
 * @brief Validate three comma-separated RGB integers in [0,255]
 */
int	is_valid_rgb_format(const char *str)
{
	char	**split;
	int		i;
	int		val;

	split = comma_split_elements(str, 3);
	if (!split)
		return (FALSE);
	i = 0;
	while (i < 3)
	{
		if (!is_valid_int_str(split[i]))
			return (free_str_array(split), FALSE);
		val = ft_atoi(split[i]);
		if (val < MIN_RGB || val > MAX_RGB)
			return (free_str_array(split), FALSE);
		i++;
	}
	free_str_array(split);
	return (TRUE);
}

/**
 * @brief Check 3D orientation vector components in [-1,1]
 */
int	is_valid_orientation_format(const char *str)
{
	char	**split;
	double	x;
	double	y;
	double	z;

	split = comma_split_elements(str, 3);
	if (!split)
		return (FALSE);
	x = ft_atof(split[0]);
	y = ft_atof(split[1]);
	z = ft_atof(split[2]);
	free_str_array(split);
	if (x < MIN_NORM_VEC || x > MAX_NORM_VEC || y < MIN_NORM_VEC
		|| y > MAX_NORM_VEC || z < MIN_NORM_VEC || z > MAX_NORM_VEC)
		return (FALSE);
	if (x == 0.0 && y == 0.0 && z == 0.0)
		return (FALSE);
	return (TRUE);
}
