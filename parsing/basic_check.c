/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerraoui <aerraoui <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:38:27 by ooussaad          #+#    #+#             */
/*   Updated: 2023/08/06 16:55:39 by aerraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_file(char *file)
{
	char	*ext;

	ext = ft_strrchr(file, '.');
	if (!file || !ext)
	{
		ft_putstr_err("file error");
		exit(0);
	}
	if (ft_strncmp(ext, ".cub", 5))
	{
		write(2, ".cub error", 11);
		exit (1);
	}
	return (1);
}

int	check_character(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0'  && (map[i][j] == 'S' || map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'W'))
			{
				// printf("we ")
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int check_player_character(char **map)
{
    int i = 0;
    int j = 0;
    int hasValidCharacter = 0;

    while (map[i])
	{
        j = 0;
        while (map[i][j]) {
            if (map[i][j] == 'S' || map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'W')
			{
                hasValidCharacter = 1;
                break;
            }
            j++;
        }
        i++;
    }
    if (hasValidCharacter) {
        return 1; // Map is valid
    } else {
        return 0; // Map is invalid
    }
}

void	check_is_one(int count)
{
	if (count != 1)
	{
		ft_putstr_err ("invalid double map\n");
		exit (1);
	}
}

void	check_doubles(char **map, t_game *vars)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'S' || map[j][i] == 'N' || map[j][i] == 'E' || map[j][i] == 'W')
			{
				vars->cub_map.counter++;
			}
			i++;
		}
		j++;
	}
	check_is_one(vars->cub_map.counter);
}
