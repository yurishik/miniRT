/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 13:23:01 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/09 12:53:23 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <limits.h>

/**
 * @brief 正しい浮動小数点数の書式(符号、整数部、小数点、小数部)か判定する
 *        (整数部分が11桁以内、小数点以下が10桁以内飲みを認めるとする // TODO仮置きなので後で変えるかも)
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
 * @brief 符号と数字のみの整数文字列か、INT_MIN - INT_MAXの範囲に入っているかを判定する
 */
int	is_valid_int_str(const char *str)
{
	int		sign;
	long	res;

	if (!str || !*str)
		return (FALSE);
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!*str)
		return (FALSE);
	res = 0;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (FALSE);
		if (((sign == 1 && (res > (INT_MAX - (*str - '0')) / 10)))
			|| ((sign == -1 && (-res < (INT_MIN + (*str - '0')) / 10))))
			return (FALSE);
		res = res * 10 + (*str - '0');
		str++;
	}
	return (TRUE);
}

/**
 * @brief "x,y,z"のカンマ区切り3要素かつ各値が正しい書式の浮動小数点数か判定する
 */
int is_valid_vector_format(const char *str)
{
	char **split;
	int is_valid;

	split = comma_split_elements(str, 3);
	if (!split)
		return (FALSE);
	is_valid = (is_valid_double_str(split[0])
			&& is_valid_double_str(split[1])
			&& is_valid_double_str(split[2]));
	free_str_array(split);
	return (is_valid);
}

/**
 * @brief "r,g,b"のカンマ区切り3要素かつ各値が0-255の整数か判定する
 */
int is_valid_rgb_format(const char *str)
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
 * @brief  3D normalized vectorかどうかを確認する[-1,1]
 */
int is_valid_orientation_format(const char *str)
{
	char **split;
	double x;
	double y;
	double z;

	split = comma_split_elements(str, 3);
	if (!split)
		return (FALSE);
	x = ft_atof(split[0]);
	y = ft_atof(split[1]);
	z = ft_atof(split[2]);
	free_str_array(split);
	if (x < MIN_NORM_VEC || x > MAX_NORM_VEC
		|| y < MIN_NORM_VEC || y > MAX_NORM_VEC
		|| z < MIN_NORM_VEC || z > MAX_NORM_VEC)
		return (FALSE);
	if (x == 0.0 && y == 0.0 && z == 0.0)
		return (FALSE);
	return (TRUE);
}
