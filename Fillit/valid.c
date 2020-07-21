/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eidaho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 14:24:45 by eidaho            #+#    #+#             */
/*   Updated: 2019/11/03 14:24:46 by eidaho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_sh(char *t, int x)
{
	int		y;
	int		i;

	while (x < 5)
	{
		y = 0;
		while (++y < 5)
		{
			i = y * 4 + y + x - 6;
			if (t[i] == '#')
				break ;
		}
		if (t[i] == '#')
			break ;
		x++;
	}
	i = 0;
	while (t[i] != '#')
		i++;
	y = 1 + (i / 5);
	i = y * 4 + y + x - 6;
	return (i);
}

char		**ft_put_letter(char *str, int hgt, int len, char letter)
{
	char	**new_tetri;
	int		step;
	int		i;
	int		count;

	count = -1;
	i = check_sh(str, 1);
	new_tetri = (char **)ft_memalloc(sizeof(char *) * hgt);
	while (++count < hgt)
	{
		new_tetri[count] = (char*)ft_memalloc(len + 1);
		step = 0;
		while (step < len)
		{
			if (str[i + step] == '#')
				new_tetri[count][step] = letter;
			else
				new_tetri[count][step] = '.';
			step++;
		}
		new_tetri[count][len] = '\0';
		i = i + 5;
	}
	return (new_tetri);
}

/*
** Считает максимальную высоту фигуры тетриса.
*/

int			ft_height_tetri(char *tetri, int i)
{
	int		height_max;

	height_max = 0;
	while (i < 19)
	{
		if (tetri[i] == '#')
		{
			height_max++;
			while (tetri[i] != '\n')
				i++;
		}
		i++;
	}
	return (height_max);
}

int			ft_length_tetri(char *tetri, int i)
{
	int		x;
	int		y;
	int		length_max;

	x = 1;
	length_max = 0;
	while (x < 5 && length_max != 4)
	{
		y = 1;
		while (y < 5)
		{
			i = y * 4 + y + x - 6;
			if (tetri[i] == '#')
			{
				length_max++;
				break ;
			}
			y++;
		}
		x++;
	}
	return (length_max);
}
