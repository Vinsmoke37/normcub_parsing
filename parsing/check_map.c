/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerraoui <aerraoui <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:43:22 by ooussaad          #+#    #+#             */
/*   Updated: 2023/08/06 23:19:28 by aerraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void find_angle(char **map,t_game *ptr,int i, int j)
{
	if(map[i][j] == 'S')
		ptr->pa = PI/2;
	if(map[i][j] == 'N')
		ptr->pa = (3 * PI)/2;
	if(map[i][j] == 'W')
		ptr->pa = PI;
	if(map[i][j] == 'E')
		ptr->pa = 0;

}

void position(t_game *game)
{
	int i ;
	int j;

	i = 0;
	j = 0;
	while(game->correct_map[i])
	{
		j = 0;
		while(game->correct_map[i][j])
		{
			if (game->correct_map[i][j] == 'S' || game->correct_map[i][j] == 'N' || game->correct_map[i][j] == 'E' || game->correct_map[i][j] == 'W')
        	{
            	find_angle(game->correct_map,game,i,j);
            	game->pl_y = i * 50 +25;
            	game->pl_x = j * 50 +25;
				game->correct_map[i][j] = '0';
				return ;
         
        	}
			j++;
		}
		i++;
	}
	
}

int find_max_map(char** map, int* maxIndex, int *h) 
{
    int maxLen = 0;
    int index = 0;
    int i = 0;

    while (map[i])
	{
        int len = ft_strlen(map[i]);
        if (len > maxLen) {
            maxLen = len;
            index = i;
        }
        i++;
    }

    *maxIndex = index;
	*h = i;
    return maxLen;
}

int	check_walls(char **map, t_game *ptr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
    while (map[i])
	{
        skipWhitespace(&map[i]);
        i++;
	}
	i = 0;
	while (map[0][j])
	{
		if (map[0][j] != '1' && map[0][j] != ' ')
		{
			ft_putstr_err("invalid wall");
			return 0;
		}
		j++;
	}
	while (map[i])
	{
		i++;
	}
	i = i - 1;
	j = 0;
	while (map[i][j])
	{
		if (map[i][j] != '1' && map[i][j] != ' ')
		{
			ft_putstr_err("invalid wall");
			return 0;
		}
		j++;
	}
	j = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		ptr->coloumes = ft_strlen(map[i]);
		while (map[i][j])
		{
			if (map[i][0] != '1' || map[i][ptr->coloumes - 1] != '1')
			{
				ft_putstr_err("invalid wall");
				return 0;
			}
			j++;
		}	
		i++;
	}
	return (1);
}

void check_der(char **map,int *i)
{
	int check = 0;
	while (*i < 6 && map[*i])
	{
		if ((ft_strncmp(map[*i], "NO ", 3) == 0
			|| ft_strncmp(map[*i], "SO ", 3) == 0
			|| ft_strncmp(map[*i], "WE ", 3) == 0
			|| ft_strncmp(map[*i], "EA ", 3) == 0)
			|| ft_strncmp(map[*i], "F ", 2) == 0
			|| ft_strncmp(map[*i], "C ", 2) == 0)
			check++;
		(*i)++;
	}
	//printf("->>>%d\n",check);
	if (check != 6 && *i != check)
	{
		write(2,"ERROR IN DERICTION TEXTURE\n",28);
		exit(1);
	}
	if (*i == 0)
	{
		write(2,"EMPTY ERROR\n",11);
		exit(1);
	}
}