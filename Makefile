# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 16:14:59 by tlegendr          #+#    #+#              #
#    Updated: 2024/03/17 18:50:43 by tlegendr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define the output name (e.g., your static library or binary)
NAME = push_swap

# Source files
SRC = push_swap.c push_cmd.c target_utils.c
# Object files derived from source files 
OBJ = $(SRC:.c=.o)

# Compiler and compiler flags
CC = cc
CFLAGS = -g -Wall -Wextra -Werror -I/usr/include
LDFLAGS = -lm -lz

# Default target (builds the final output)
all: $(NAME)

# Pattern rule for compiling source files to object files 
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Build the final output
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)



# Clean up object files
clean:
	rm -f $(OBJ)

# Clean everything, including the final output
fclean: clean
	rm -f $(NAME)

# Rebuild the project
re: fclean all

# Phony target to avoid conflicts with files named "clean" or "fclean"
.PHONY: all clean fclean re
