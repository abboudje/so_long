# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abboudje <abboudje@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 17:24:01 by abboudje          #+#    #+#              #
#    Updated: 2024/11/06 12:52:15 by abboudje         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define the name of the executable
NAME        = so_long

# Compiler and compilation flags
CC          = clang
FLAGS       = -Wall -Wextra -Werror -I./includes

# Library paths and files
LIBFT_PATH  = ./core/libft/
LIBFT_FILE  = libft.a
LIBFT_LIB   = $(LIBFT_PATH)$(LIBFT_FILE)

MLX_FILE    = libmlx.a
MLX_PATH    = ./minilibx-linux/
MLX_LIB     = $(MLX_PATH)$(MLX_FILE)
MLX_FLAGS   = -lX11 -lXext  # Flags for linking the MinilibX library

# Source files
C_FILES     = 	main.c  \
				check.c \
				matrix.c \
				free.c \
				render.c \

SRC_DIR      = ./src/
SRC          = $(addprefix $(SRC_DIR), $(C_FILES))  # Complete paths to source files
OBJ          = $(SRC:.c=.o)  # Object files corresponding to source files

# Rule for compiling .c files into .o files
.c.o:
	$(CC) $(FLAGS) -c $< -o $@

# Default target to build the executable
all: $(NAME)

# Target to build the libft library
lib:
	@make -C $(LIBFT_PATH)  # Change directory and run make

# Target to build the MinilibX library
mlx:
	@make -C $(MLX_PATH)  # Change directory and run make

# Target to link object files and create the executable
$(NAME): lib mlx $(OBJ)
	$(CC) $(OBJ) $(LIBFT_LIB) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)

# Target to clean up object files
clean:
	@make clean -C $(MLX_PATH)  # Clean MinilibX object files
	@make clean -C $(LIBFT_PATH)  # Clean libft object files
	@rm -f $(OBJ)  # Remove object files for the current project

# Target to clean up everything
fclean: clean
	@rm -f $(NAME)  # Remove the executable
	@make fclean -C $(LIBFT_PATH)  # Clean libft

# Target to rebuild everything from scratch
re: fclean all

# Declare phony targets (not actual files)
.PHONY: all clean fclean re lib mlx