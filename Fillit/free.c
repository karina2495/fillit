/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eidaho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:02:50 by eidaho            #+#    #+#             */
/*   Updated: 2019/11/08 08:53:49 by eidaho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list			*free_list(t_list *list)
{
	t_tetris	*tetris;
	t_list		*next;

	while (list)
	{
		tetris = (t_tetris *)list->content;
		next = list->next;
		free_tetris(tetris);
		ft_memdel((void **)&list);
		list = next;
	}
	return (NULL);
}

/*
** Очистка структур, хранящие тетрамино.
*/

void			free_tetris(t_tetris *tetri)
{
	int y;

	y = -1;
	while (++y < tetri->height)
		ft_memdel((void **)(&(tetri->str[y])));
	ft_memdel((void **)(&(tetri->str)));
	ft_memdel((void **)&tetri);
}

/*
** Создание новой структуры, в которую записываются данные о тетрамино.
*/

t_tetris		*tetris_new(char **str, int length, int height)
{
	t_tetris	*tetris;

	tetris = ft_memalloc(sizeof(t_tetris));
	tetris->str = str;
	tetris->width = length;
	tetris->height = height;
	return (tetris);
}
