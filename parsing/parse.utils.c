/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerraoui <aerraoui <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:40:30 by ooussaad          #+#    #+#             */
/*   Updated: 2023/08/06 22:05:38 by aerraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_putstr_err(char *str)
{
	while (*str)
		write(2,str++,1);
}

char **cpy_map(char **map, int lines, int h)
{
    char **dst = (char **)ft_calloc(h + 1, sizeof(char *));
    int i = 0;
    while (map[i] != NULL) 
	{
        dst[i] = (char *)ft_calloc(lines + 1, sizeof(char));
        ft_strcpy(dst[i], map[i]);
        i++;
    }
    dst[i] = NULL; // Null-terminate the destination array
    return dst;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			break ;
	}
	return (s1[i] - s2[i]);
}

void err(void)
{
	ft_putstr_err("null argument");
	exit(1);
}

int len(char **str)
{
	int i =0;
	while (str[i])
	{
		i++;
	}
	return i;
}

int		ft_isspace(int c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

void skipWhitespace(char** str) 
{
    while (**str && ft_isspace(**str)) 
	{
        (*str)++;
    }
}