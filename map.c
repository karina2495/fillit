/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfearles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:02:09 by vfearles          #+#    #+#             */
/*   Updated: 2019/11/08 08:51:06 by eidaho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** создание новой карты
*/

t_map		*creaturemap_new(int size)
{
	int		i;
	int		k;
	t_map	*map;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->size = size;
	map->tmp = (char **)ft_memalloc(sizeof(char *) * size);
	i = -1;
	while (++i < size)
	{
		map->tmp[i] = ft_strnew(size);
		k = -1;
		while (++k < size)
			map->tmp[i][k] = '.';
	}
	return (map);
}

/*
** очистка карты
*/

void		freemap(t_map *map)
{
	int		i;

	i = -1;
	while (++i < map->size)
		ft_memdel((void**)&(map->tmp[i]));
	ft_memdel((void**)&(map->tmp));
	ft_memdel((void**)&map);
}

/*
** печать карты
*/

void		printmap(t_map *map)
{
	int		i;

	i = -1;
	while (++i < map->size)
		ft_putendl(map->tmp[i]);
}
