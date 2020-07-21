/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfearles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 18:14:05 by vfearles          #+#    #+#             */
/*   Updated: 2019/11/08 08:50:05 by eidaho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Функция для расчета минимального размера карты
*/

t_map		*minsize(t_list *lst)
{
	int		size;
	t_map	*map;

	size = sqrtsize(ft_lstcount(lst));
	map = creaturemap_new(size);
	while (!backtracking(map, lst))
	{
		size++;
		freemap(map);
		map = creaturemap_new(size);
	}
	return (map);
}

int			sqrtsize(int len)
{
	int		size;

	size = 2;
	while (size * size < len)
		size++;
	return (size);
}

/*
** Алгоритм поиска с возратом
*/

int			backtracking(t_map *map, t_list *list)
{
	int			x;
	int			y;
	t_tetris	*tetrimino;

	if (!list)
		return (1);
	tetrimino = (t_tetris *)(list->content);
	x = -1;
	while (++x < map->size - tetrimino->height + 1)
	{
		y = -1;
		while (++y < map->size - tetrimino->width + 1)
		{
			if (position(tetrimino, map, x, y))
			{
				if (backtracking(map, list->next))
					return (1);
				else
					position_setting(tetrimino, map, x, y);
			}
		}
	}
	return (0);
}

/*
** Проверка позиции для постановки тетриминки
*/

int			position(t_tetris *tetramino, t_map *map, int x, int y)
{
	int		i;
	int		k;

	i = -1;
	while (++i < tetramino->height)
	{
		k = -1;
		while (++k < tetramino->width)
			if (tetramino->str[i][k] != '.' && map->tmp[x + i][y + k] != '.')
				return (0);
	}
	position_setting(tetramino, map, x, y);
	return (1);
}

/*
** Установка тетрамино на позицию и очистка,
** если нет возможности постановки тетрамино на позицию
*/

void		position_setting(t_tetris *tetramino, t_map *map, int x, int y)
{
	int		i;
	int		k;

	i = -1;
	while (++i < tetramino->height)
	{
		k = -1;
		while (++k < tetramino->width)
			if (tetramino->str[i][k] != '.' && map->tmp[x + i][y + k] != '.')
				map->tmp[x + i][y + k] = '.';
			else if (tetramino->str[i][k] != '.')
				map->tmp[x + i][y + k] = tetramino->str[i][k];
	}
}
