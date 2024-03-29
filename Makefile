# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 15:37:53 by victgonz          #+#    #+#              #
#    Updated: 2023/04/27 09:16:32 by victgonz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

####	VARIABLES	####

PROJECT = PUSHSWAP

CC = gcc

CFLAGS = ##-Wall -Wextra -Werror -std=c99

SRC_DIR = src/

OBJ_DIR = obj/

SRC_FILES	=	swap_info			\
				func_swap_1			\
				func_swap_2			\
				free_all			\
				linked_func			\
				push_swap			\
				algorithm_1			\
				algorithm_2			\
				utils/push_lst		\
				utils/utils_1		\
				utils/utils_2		\
				utils/rotate_up		\
				utils/rotate_down

SOURCES = 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))

OBJECTS = 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJF		=	.cache_exists

EXECUTABLE = push_swap

## INCLUDES

INCLUDES = -I./include

LIB_DIR = lib/my_lib

INCLUDES_MY_LIB = -I./$(LIB_DIR)/include

LIB = -L./$(LIB_DIR) -lft

####	COLORS	####

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#### COMMANDS ####

all: libft $(EXECUTABLE) write_name

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) $(INCLUDES_MY_LIB) $(OBJECTS) $(LIB) -o $(EXECUTABLE)
	@echo "$(MAGENTA)======>$(GREEN)$(EXECUTABLE) compiled! $(MAGENTA)<======$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	@echo "$(MAGENTA)======>$(GREEN)Compiling: $(YELLOW)$< $(DEF_COLOR)"
	$(CC) $(CFLAGS) $(INCLUDES) $(INCLUDES_MY_LIB) -c $< -o $@

$(OBJF):
		@mkdir -p $(OBJ_DIR)

write_name:
		@echo "$(MAGENTA)╔═════════════════════════════════════════╗$(DEF_COLOR)"
		@echo "$(MAGENTA)║                 $(CYAN)$(PROJECT)$(MAGENTA)                ║$(DEF_COLOR)"
		@echo "$(MAGENTA)╚═══════════════╦═════════╦═══════════════╝$(DEF_COLOR)"
		@echo "$(MAGENTA)                ║  $(GREEN)VIC'S$(MAGENTA)  ║$(DEF_COLOR)"
		@echo "$(MAGENTA)                ╚═════════╝     $(DEF_COLOR)"

clean:
	rm -f $(OBJECTS)
	@echo "$(MAGENTA)======>$(BLUE)$(EXECUTABLE) object files cleaned!$(DEF_COLOR)"

fclean: clean
	rm -f $(EXECUTABLE)
	@echo "$(MAGENTA)======>$(CYAN)$(EXECUTABLE)executable files cleaned!$(DEF_COLOR)"
	make -C $(LIB_DIR) fclean

re: fclean all

libft:
	make -C $(LIB_DIR)
