# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/16 11:09:45 by ctaboada          #+#    #+#              #
#    Updated: 2025/05/16 12:11:13 by ctaboada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable names
NAME_CLIENT = client
NAME_SERVER = server

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Directories and files
SRC_CLIENT = src/client.c src/atob.c
SRC_SERVER = src/server.c
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
HEADER = include/minitalk.h

# Include directories
INCLUDES = -I./include -I$(LIBFT_DIR)

# Default target: build everything
all: $(LIBFT) $(NAME_CLIENT) $(NAME_SERVER)
	@echo "\033[0;32mCOMPILED MINITALK\033[0m"

# Build libft first
$(LIBFT):
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)

# Build client program
$(NAME_CLIENT): $(SRC_CLIENT) $(LIBFT) $(HEADER)
	@$(CC) $(CFLAGS) $(SRC_CLIENT) $(LIBFT) $(INCLUDES) -o $(NAME_CLIENT)

# Build server program
$(NAME_SERVER): $(SRC_SERVER) $(LIBFT) $(HEADER)
	@$(CC) $(CFLAGS) $(SRC_SERVER) $(LIBFT) $(INCLUDES) -o $(NAME_SERVER)

# Clean object files (from libft) and executables
clean:
	@$(MAKE) --no-print-directory clean -C $(LIBFT_DIR)
	@rm -f $(NAME_CLIENT) $(NAME_SERVER)
	@echo "\033[0;31mDELETED MINITALK\033[0m"

# Full clean including libft.a
fclean: clean
	@$(MAKE) --no-print-directory fclean -C $(LIBFT_DIR)
	@rm -f $(NAME_CLIENT) $(NAME_SERVER)

# Rebuild everything
re: fclean all
	@echo "\033[0;33mUPDATE MINITALK\033[0m"
