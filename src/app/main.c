/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurishik <yurishik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 23:23:43 by hisasano          #+#    #+#             */
/*   Updated: 2026/10/09 12:53:46 by yurishik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "app.h"
#include "parser.h"

int	main(int ac, char **av)
{
	if (check_args(ac, av) != NO_ERROR)
		return (1);
	return (app_run(av[1]));
}
