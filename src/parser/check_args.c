/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 10:12:03 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/22 19:21:29 by hisasano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief Check the file extension
 *
 * @param filename File name
 * @param ext Expected extension
 * @return HAS_ERROR if the extension is invalid, otherwise NO_ERROR
 */
int	valid_extension(const char *filename, const char *ext)
{
	size_t	file_len;
	size_t	ext_len;

	if (!filename || !ext)
		return (-1);
	file_len = ft_strlen(filename);
	ext_len = ft_strlen(ext);
	if (file_len <= ext_len)
		return (HAS_ERROR);
	if (filename[file_len - ext_len - 1] == '/')
		return (HAS_ERROR);
	if (ft_strncmp(filename + file_len - ext_len, ext, ext_len + 1) != 0)
		return (HAS_ERROR);
	return (NO_ERROR);
}

/**
 * @brief Check the arguments and file extension
 *
 * @param int argc (passed directly from main)
 * @param char **argv (passed directly from main)
 * @return HAS_ERROR if an error occurs, otherwise NO_ERROR
 */
int	check_args(int argc, char **argv)
{
	if (argc != 2)
		return (print_error("Invalid number of arguments"));
	if (valid_extension(argv[1], ".rt") == HAS_ERROR)
		return (print_error("Invalid file extension"));
	return (NO_ERROR);
}

int	check_int_digits(const char *str, int sign)
{
	long	res;
	long	limit;
	int		digit;

	res = 0;
	limit = INT_MAX;
	if (sign == -1)
		limit = -(long)INT_MIN;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (FALSE);
		digit = *str - '0';
		if (res > (limit - digit) / 10)
			return (FALSE);
		res = res * 10 + digit;
		str++;
	}
	return (TRUE);
}
