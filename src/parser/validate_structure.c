/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_structure.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 12:12:59 by yurishik          #+#    #+#             */
/*   Updated: 2026/10/03 12:42:00 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief 識別子の完全一致を判定する
 * 
 * @param str 文字列
 * @param id 判定したい識別子
 * @return 識別子が完全一致していた場合TRUE, そうでなければFALSE
 */
static int	is_id_match(const char *str, const char *id)
{
	size_t	id_len;

	id_len = ft_strlen(id);
	if (ft_strncmp(str, id, id_len) != 0)
		return (FALSE);
	if (ft_isspace(str[id_len]))
		return (TRUE);
	return (FALSE);
}

/**
 * @brief 行先頭の空白をスキップし、どの識別子かを返す
 * 
 * @param line
 * @return 合致した識別子
 */
static const char	*find_matching_id(const char *line)
{
	static const char	*valid_ids[] = {
		ID_AMBIENT, ID_CAMERA, ID_LIGHT,
		ID_SPHERE, ID_PLANE, ID_CYLINDER,
		NULL
	};
	int					i;

	while (ft_isspace(*line))
		line++;
	if (*line == '\0')
		return (NULL);
	i = 0;
	while (valid_ids[i])
	{
		if (is_id_match(line, valid_ids[i]))
			return (valid_ids[i]);
		i++;
	}
	return (NULL);
}

/**
 * @brief 識別子に応じて構造体内それぞれの個数を加算
 * 
 * @param id 識別子
 * @param counts 構造体
 */
static void	increment_count(const char *id, t_element_counts *counts)
{
	if (ft_strcmp(id, ID_AMBIENT) == 0)
		counts->ambient_count++;
	else if (ft_strcmp(id, ID_CAMERA) == 0)
		counts->camera_count++;
	else if (ft_strcmp(id, ID_LIGHT) == 0)
		counts->light_count++;
	else if (ft_strcmp(id, ID_SPHERE) == 0)
		counts->sphere_count++;
	else if (ft_strcmp(id, ID_PLANE) == 0)
		counts->plane_count++;
	else if (ft_strcmp(id, ID_CYLINDER) == 0)
		counts->cylinder_count++;
}

/**
 * @brief 各要素の出現回数をカウント、objectsの全体の個数もここで取得しておく(TODO 不要なら削除)
 * 
 * @param lines 文字列配列
 * @param counts 個数を保持する構造体
 * @return HAS_ERROR/NO_ERROR
 */
static int	count_all_elements(char **lines, t_element_counts *counts)
{
	int			i;
	const char	*id;

	i = 0;
	while (lines[i])
	{
		id = find_matching_id(lines[i]);
		if (!id)
			return (print_error("Invalid identifier"));
		increment_count(id, counts);
		i++;
	}
	counts->total_objects = counts->sphere_count
		+ counts->plane_count
		+ counts->cylinder_count;
	return (NO_ERROR);
}

/**
 * @brief A, C, L が各1つ存在することを確認する
 * 
 * @param lines 文字列配列
 * @param counts 個数を保持する構造体
 * @return HAS_ERROR/NO_ERROR
 */
int	validate_structure(char **lines, t_element_counts *counts)
{
	if (!lines || !lines[0])
		return (print_error("File is empty"));
	ft_bzero(counts, sizeof(t_element_counts));
	if (count_all_elements(lines, counts) == HAS_ERROR)
		return (HAS_ERROR);
	if (counts->ambient_count != 1)
		return (print_error("Invalid number of A"));
	if (counts->camera_count != 1)
		return (print_error("Invalid number of C"));
	if (counts->light_count != 1)
		return (print_error("Invalid number of L"));
	return (NO_ERROR);
}
