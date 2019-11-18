/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eidaho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:34:17 by eidaho            #+#    #+#             */
/*   Updated: 2019/10/28 11:34:20 by eidaho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				main(int argc, char **argv)
{
	t_list		*current;
	t_map		*map;

	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (1);
	}
	if ((current = read_tetrimino(open(argv[1], O_RDONLY), 0)) == NULL)
	{
		ft_putstr("error\n");
		return (1);
	}
	if (!(map = minsize(current)))
		return (1);
	printmap(map);
	freemap(map);
	free_list(current);
	return (0);
}
