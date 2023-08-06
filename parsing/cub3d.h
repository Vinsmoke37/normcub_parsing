/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerraoui <aerraoui <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:37:32 by ooussaad          #+#    #+#             */
/*   Updated: 2023/08/06 23:22:52 by aerraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "libft/libft.h"
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
#include <stdbool.h>
# include "libft/libft.h"
# include <mlx.h>
#include<math.h>

#define FLOOR "F"
#define CEILLING "C"
#define EAST  "EA"
#define WEST "WE"
#define NORTH "NO"
#define SOUTH "SO"
#define PI 3.1415926535


typedef struct s_move
{
	int move_up_down;
	int move_angle;
	int move_right_left ;
}t_move;

typedef struct s_rgb_color
{
	int	red;
	int	green;
	int	bleu;
}	t_rgb_color;

typedef struct c_cub
{
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	char		*filename;
	int			counter;
	t_rgb_color floor_clr;
	t_rgb_color ceill_clr;
}t_cub;

typedef struct t_cube
{
	
    char **map;
    t_cub cub_map;
	char **correct_map;
	char **temp_work;
	char **temp_work_two;
	char **map_path_cl;
	int 	rows;
	int 	coloumes;
	int 	player_x;
	int 	player_y;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
    void	*mlx;
	void	*mlx_win;
	void *mlx1;
	void    *mlx_WE;
	void *mlx_NO;
	void *mlx_EU;
	void *mlx_SU;
	int WHITE ;
    int HIEGHT;
	int WHITE_rays;
    int HIEGHT_rays;
	double pl_x;
	double pl_y;
	double pdx;
	double pdy;
	double pa;
	double Xv;
	double Xh;
	double Yv;
	double Yh;
	char	*addr1;
	int		bits_per_pixel1;
	int		line_length1;
	int		endian1;
	int whiSU;
	int highSU;
	int whiNO;
	int highNO;
	int whiWE;
	int highWE;
    int whiEU;
	int highEU;
	int m;
	t_move move;
    
}t_game;

int		check_file(char *file);
char	**ft_split_big(char *str, char *sap);
char    **copy_array(char** src, int start_index, int* copied_length);
int	    check_file(char *file);
int	check_character(char **map);
int check_player_character(char **map);
void	check_is_one(int count);
void	check_doubles(char **map, t_game *vars);
void	check_content(char **map,char **map_path);
void	fill_textures(t_game *ptr);
void	fill_colors(t_game *ptr);
void position(t_game *game);
int find_max_map(char** map, int* maxIndex, int *h); 
int	check_walls(char **map, t_game *ptr);
void check_der(char **map,int *i);
void ft_putstr_err(char *str);
void	free_array(char **tab);
void check_all(char **map);
int checkCondition(int i, int j, char** map);
char **cpy_map(char **map, int lines, int h);
int	ft_strcmp(char *s1, char *s2);
void err(void);
int len(char **str);
int check_map(char *map[]);
char** ft_big_memcpy(char** dst, char** src);
void fill_rgb(t_rgb_color *ptr,char **holder);
int hasDuplicate(char** map);
int		ft_isspace(int c);
char** fix_line_size(char **map, int numLines);
void skipWhitespace(char** str);
char** copy_array(char** src, int start_index, int* copied_length);
char	**ft_split_big(char *str, char *sap);
void ft_cub(t_game *img);
void	my_mlx_pixel_put(t_game *data, int x, int y, int color);
int key_realise(int key , t_game *data);
int key_press(int key , t_game *data);
double mlx_retunr_color(t_game *data, int x, int y);
void mini_map(t_game *data);
void	key_hook( t_game *img);


