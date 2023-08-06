
NAME = cub3d

CC = CC
CFLAGS =  -fsanitize=address -g3 #-Wall -Wextra -Werror

SRC = libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_itoa.c libft/ft_memcpy.c libft/ft_memset.c libft/ft_split.c\
		libft/ft_strchr.c libft/ft_strcpy.c libft/ft_strdup.c libft/ft_strjoin.c libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strncmp.c\
		libft/ft_strrchr.c libft/get_next_line.c check_map.c main.c cub/cub.c  cub/mlx_put_pixel.c cub/move.c cub/mini_map.c check_map_2.c\
		basic_check.c check_wall.c tools_2.c tools.c parse.utils.c
 
OBJ =$(SRC:.c=.o)

all : $(NAME)

$(NAME):$(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean : 
		rm -f $(OBJ) 

fclean : clean
	rm -f $(NAME)

re : fclean all


vinsmok: all  clean
		@clear