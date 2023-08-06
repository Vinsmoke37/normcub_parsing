/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 20:34:03 by ooussaad          #+#    #+#             */
/*   Updated: 2023/08/05 14:21:11 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int checkCondition(int i, int j, char** map)
{
	if ((i > 0 && j > 0) && ((map[i][j + 1] == '\0' || map[i][j + 1] == ' ') || (map[i][j - 1] == '\0' || map[i][j - 1] == ' ') ||\
		(map[i + 1][j] == '\0' || map[i + 1][j] == ' ') || (map[i - 1][j] == '\0' || map[i - 1][j] == ' '))) 
	{
    
	    return 1;
    } 
	else {
        return 0;
    }
}

void check_all(char **map)
{
	int i = 0;
	int j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
			{
				if (checkCondition(i, j, map))
				{
    				printf("map[%d][%d]: %c\n", i, j, map[i][j]);
 				   printf("error");
				}
			}
			j++;
		}
		i++;
	}
}

int is_valid_character(char ch) 
{
    return (ch == '0' || ch == '1' || ch == 'S' || ch == 'N' || ch == 'E' || ch == 'W');
}

int check_map(char *map[]) 
{
    int i = 0;
    int found_required_character = 0;

    while (map[i]) {
        int j = 0;
        while (map[i][j]) {
            if (!is_valid_character(map[i][j])) 
			{
                return 0;
            }

            if (map[i][j] == 'S' || map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'W') {
                found_required_character = 1;
            }

            j++;
        }
        i++;
    }
    return found_required_character;
}
