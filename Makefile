# Project name
NAME = minishell

# Readline name
READLINE = readline

# Compilator
CC = cc

# Compilator flags
INC_DIRS = -I./includes -I./$(LIBS_DIR)/$(READLINE)/include
CFLAGS = -Wall -Wextra -Werror $(INC_DIRS) #-g3 -fsanitize=address

# Libraries
LIBS_DIR = libraries
READLINE_LIB_PATH = $(LIBS_DIR)/readline/lib

# Headers
HEADERS = $(wildcard includes/*.h)

# Source and object directories
SRCS_DIR = sources/
OBJS_DIR = objects/

# Source and object file names using wildcards
SRCS = $(wildcard $(SRCS_DIR)**/*.c $(SRCS_DIR)*.c)
OBJS = $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))

# Compilation process
all: $(LIBS_DIR)/$(READLINE) $(NAME)

linux_minishell: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ -l$(READLINE)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ -l$(READLINE) -L$(READLINE_LIB_PATH)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADERS) Makefile
	 @mkdir -p $(OBJS_DIR)
	# @mkdir -p $(OBJS_DIR)/tokenization
	# @mkdir -p $(OBJS_DIR)/utilities
	# @mkdir -p $(OBJS_DIR)/environment
	# @mkdir -p $(OBJS_DIR)/builtin
	# @mkdir -p $(OBJS_DIR)/syntaxer
	# @mkdir -p $(OBJS_DIR)/executor
	# @mkdir -p $(OBJS_DIR)/pipex
	$(CC) $(CFLAGS) -c $< -o $@

# Configuring readline
$(LIBS_DIR)/$(READLINE):
	./$(LIBS_DIR)/config_readline readline

# Cleaning
clean:
	@$(RM) $(OBJS)

# Force cleaning
fclean: clean
	@$(RM) $(NAME)
	@$(RM) linux_minishell
	rm -rf $(LIBS_DIR)/$(READLINE)
	rm -rf $(OBJS_DIR)
	make clean -C $(LIBS_DIR)/readline-8.2

# Remaking
re: fclean all

# PHONY files
.PHONY: all clean fclean re
