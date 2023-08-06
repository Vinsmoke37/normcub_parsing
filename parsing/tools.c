/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerraoui <aerraoui <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:51:26 by ooussaad          #+#    #+#             */
/*   Updated: 2023/08/06 21:19:32 by aerraoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**malloc_error(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

int	is_saperator(char c, char *sap)
{
	int	i;

	i = 0;
	while (sap[i])
	{
		if (c == sap[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *sap)
{
	int	i;
	int	w_count;
	int	state;

	i = 0;
	w_count = 0;
	state = 0;
	while (str[i])
	{
		if (!is_saperator(str[i], sap))
		{
			if (!state)
				w_count++;
			state = 1;
			i++;
		}
		else
		{
			state = 0;
			i++;
		}
	}
	return (w_count);
}

char	*ft_strdup_w(char *str, int *index, char *sap)
{
	char	*word;
	int		len;
	int		i;

	i = *index;
	len = 0;
	while (str[i] && !is_saperator(str[i++], sap))
	{
		len++;
	}
	word = (char *) malloc(len + 1);
	// printf("FILE : %s | LINE  : %d | adress : %p\n",__FILE__, __LINE__ , word);
	if (!word)
		return (NULL);
	i = 0;
	while (str[*index])
	{
		if (!is_saperator(str[*index], sap))
		{
			word[i++] = str[*index];
			(*index)++;
		}
		else
			break ;
	}
	word[len] = '\0';
	return (word);
}

char	**ft_split_big(char *str, char *sap)
{
	char	**arr_str;
	int		i;
	int		words;
	int		w_i;

	i = 0;
	w_i = 0;
	words = count_words(str, sap);
	arr_str = (char **) malloc((words + 1) * 8);
    // printf("FILE : %s | LINE  : %d | adress : %p\n",__FILE__, __LINE__ , arr_str);
	if (!arr_str)
		return (NULL);
	while (w_i < words)
	{
		while (is_saperator(str[i], sap) && str[i])
			if (!str[i++])
				break ;
		arr_str[w_i] = ft_strdup_w(str, &i, sap);
		if (!arr_str[w_i])
			return (malloc_error(arr_str));
		w_i++;
	}
	arr_str[words] = 0;
	return (arr_str);
}

char** copy_array(char** src, int start_index, int* copied_length) 
{
	char** dst = NULL;
    int src_length = 0;
    int dst_length = 0;
    // Calculate the length of the source array
    while (src[src_length]) {
        src_length++;
    }

    // Check if start_index is within the valid range
    if (start_index >= src_length) {
        *copied_length = 0;
        return NULL;
    }

    // Calculate the length of the portion to be copied
    while (src[start_index + dst_length]) {
        dst_length++;
    }

    // Allocate memory for the destination array
    dst = ( char**) malloc((dst_length + 1) * sizeof(char*));
	dprintf(2, "Address =>>> %p\n", dst);
	
    // Copy the elements from the source to the destination array
    int i = 0;
    while (src[start_index + i]) {
        dst[i] = ft_strdup(src[start_index + i]);
        i++;
    }

    dst[i] = NULL; // Terminate the destination array with a NULL pointer

    *copied_length = dst_length;
    return dst;
}

char** ft_big_memcpy(char** dst, char** src)
{
    int rows = 0;
    while (src[rows]) {
        int columns = 0;
        while (src[rows][columns]) {
            dst[rows][columns] = src[rows][columns];
            columns++;
        }
        dst[rows][columns] = '\0'; // Null-terminate the row in the destination array
        rows++;
    }
    dst[rows] = NULL; // Null-terminate the destination array
    return dst;
}

void	free_array(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab && tab[i])
		free(tab[i++]);
	free(tab);
}