NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror # -fsanitize=address

SRC = main.c\
	parsing.c\
	get_next_line.c\
	get_next_line_utils.c\
	data_extraction.c\
	# check_elements.c\

OBJ = $(SRC:.c=.o)

# Add libft directory
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

# Compile libft before compiling cub3D
$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -Lmlx_linux -lmlx -L/usr/lib -Imlx_linux \
		-lXext -lX11 -lm -lz -L$(LIBFT_DIR) -lft -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -I$(LIBFT_DIR) -O3 -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
.SECONDARY :
