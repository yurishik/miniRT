/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 10:12:03 by yurishik          #+#    #+#             */
/*   Updated: 2026/09/27 11:05:28 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief 拡張子のチェック
 *
 * @param filename ファイル名
 * @param ext 拡張子
 * @return 拡張子が異なる場合はHAS_ERROR, 拡張子が正しければNO_ERROR
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
 * @brief 引数と拡張子のチェック
 *
 * @param int argc (mainからそのまま渡す)
 * @param char **argv (mainからそのまま渡す)
 * @return なにか問題があればHAS_ERROR, 問題なければNO_ERROR
 */
int	check_args(int argc, char **argv)
{
	if (argc != 2)
		return (print_error("Invalid number of arguments"));
	if (valid_extension(argv[1], ".rt") == HAS_ERROR)
		return (print_error("Invalid file extension"));
	return (NO_ERROR);
}
