/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerraoui <aerraoui <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:49:21 by ooussaad          #+#    #+#             */
/*   Updated: 2023/08/06 21:54:17 by aerraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_content(char **map,char **map_path)
{
	int i = 0;
	char **dst;
	dst = fix_line_size(map,6);

	i = 0;
	if (hasDuplicate(dst)) {
		ft_putstr_err("Duplicate textures found!\n");
		exit(1);
	}
	i = 0;
	check_der(map,&i);
	while (map[i] && ft_strcmp(map[i],"\n") == 0)
		i++;
	while (map[i] && ft_strcmp(map[i],"\n") == 0)
		i++;
	if (!map[i]) {
		ft_putstr_err("empty map\n");
        exit(1);
	}
	free_array(dst);
}

void	fill_textures(t_game *ptr)
{
	char **holder;
	int i = 0;
	while (i < 4)
	{
		holder = ft_split_big(ptr->map[i++], ", \n");
		if (!holder[0])
			return ;
		if (ft_strcmp(holder[0], NORTH) == 0)
		{
			if (!holder[1])
				err();
			else
				ptr->cub_map.north_texture = NULL;
				ptr->cub_map.north_texture = ft_strdup(holder[1]);
		}
		else if (ft_strcmp(holder[0], SOUTH) == 0)
		{
			if (!holder[1])
				err();
			else
				ptr->cub_map.south_texture = NULL;
				ptr->cub_map.south_texture = ft_strdup(holder[1]);		
		}
		else if (ft_strcmp(holder[0], EAST) == 0)
		{
			if (!holder[1])
				err();
			else
				ptr->cub_map.east_texture = NULL;
				ptr->cub_map.east_texture = ft_strdup(holder[1]);		
		}
		else if (ft_strcmp(holder[0], WEST) == 0)
		{
			if (!holder[1])
				err();
			else
				ptr->cub_map.west_texture = NULL;
				ptr->cub_map.west_texture = ft_strdup(holder[1]);
		}
		free_array(holder);
	}
}

void	fill_colors(t_game *ptr)
{
	char	**splited;
	int		i;

	i = 0;
	while (ptr->map[i])
	{
		if (ptr->map[i][0] == '1'
				|| ptr->map[i][0] == ' '
				|| ptr->map[i][0] == '0')
			break ;
		splited = ft_split_big(ptr->map[i++], ", \n");
		if (splited[0])
		{
			if (ft_strcmp(splited[0], FLOOR) == 0)
			{
				// printf("D--------------------- floor \n");
				// printf("split %s\n",splited[i]);
				// i++;
				fill_rgb(&ptr->cub_map.floor_clr, splited + 1);
			}
			else if (ft_strcmp(splited[0], CEILLING) == 0)
			{
				// printf("D---------------------  ciel \n");
				fill_rgb(&ptr->cub_map.ceill_clr, splited + 1);
			}
		}
		free_array(splited);
		//dont free this
	}	
}