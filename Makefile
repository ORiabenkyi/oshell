# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 12:53:01 by oriabenk          #+#    #+#              #
#    Updated: 2025/01/26 11:27:17 by oriabenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= oshell

CC			= cc
CFLAGS		= -Wall -Wextra -Werror \

LDFLAGS		= -lreadline

LIB_DIR = libft
LIBFT =  $(LIB_DIR)/libft.a

INCLUDES_FLAGS = $(LIBFT) -I inc/ 

OBJ_PATH = obj

SRC_DIR = src
FILES_SRC := \
		main.c \
		init_env.c \
		handle_signals_global.c \
		init_data.c \
		exit_shell.c \
		process_execute.c \
		is_valid_input.c \
		exit_invalid_input.c \
		is_opened_bracket.c \
		is_correct_substring.c \
		error_allocate_list.c \
		init_list.c \
		split_on_substring.c \
		create_list.c \
		free_all.c \
		add_token_after.c \
		create_token.c \
		split_token.c \
		

FILES_SRC := $(addprefix $(SRC_DIR)/, $(FILES_SRC))
FILES_OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_PATH)/%.o, $(FILES_SRC))

# ----- Rules -----
# make your life more ordered

all: $(NAME)

$(NAME): $(LIBFT) $(FILES_OBJ)
	$(CC) $^ $(INCLUDES_FLAGS) $(CFLAGS) $(LDFLAGS) -o $(NAME)

$(LIBFT):
	make -C $(LIB_DIR)

$(OBJ_PATH)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) -c $< -o $@ 

clean:
	rm -rf $(OBJ_PATH)
	$(MAKE) clean -C $(LIB_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIB_DIR)

re: fclean all

.PHONY: all clean make fclean re