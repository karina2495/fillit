/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfearles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:18:12 by vfearles          #+#    #+#             */
/*   Updated: 2019/11/08 09:38:09 by eidaho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# define M_T 27
# define SIZE_TETRI 20

typedef struct		s_tetris
{
	int				width;
	int				height;
	char			**str;
}					t_tetris;

typedef struct		s_map
{
	int				size;
	char			**tmp;
}					t_map;

t_list				*free_list(t_list *list);
void				free_tetris(t_tetris *tetri);
t_tetris			*tetris_new(char **str, int length, int height);
int					main(int argc, char **argv);
t_map				*creaturemap_new(int size);
void				freemap(t_map *map);
void				printmap(t_map *map);
t_map				*minsize(t_list *lst);
int					backtracking(t_map *map, t_list *list);
int					position(t_tetris *tetramino, t_map *map, int x, int y);
void				position_setting(t_tetris *tetramino, \
		t_map *map, int x, int y);
int					check_connect(const char *str, int i, int counter);
t_tetris			*get_new_cut_tetri(char *tetri_str, int tetri_num);
t_list				*read_tetrimino(int fd, int flag);
int					check_sh(char *t, int x);
char				**ft_put_letter(char *str, int hgt, int len, char letter);
int					ft_height_tetri(char *tetri, int i);
int					ft_length_tetri(char *tetri, int i);
int					sqrtsize(int len);

#endif
