/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 21:39:42 by ooussaad          #+#    #+#             */
/*   Updated: 2023/07/02 21:58:27 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFFER_SIZE 99

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
#include <stdio.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memset(void *b, int x, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char *holder, char *cursor);
char	**ft_split(char const *str, char c);
void	ft_bzero(void *s, size_t n);
char	*get_next_line(int fd);
char	*ft_strcpy(char *s1, const char *s2);
char	*ft_itoa(int n);
int	ft_atoi(const char *str);

#endif
