#==============================================================================#
#                                   SETTINGS                                   #
#==============================================================================#

NAME = btc

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf
VAL = valgrind --leak-check=full --show-leak-kinds=all

SRC = main.cpp BitcoinExchange.cpp

OBJ_DIR = obj
OBJS = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

TEST_FILES = input.txt input_edge.txt empty_file.txt windows.txt

#==============================================================================#
#                                    EXTRA                                     #
#==============================================================================#

ECHO = @echo
GREEN = \033[1;32m
RED = \033[1;31m
CYAN = \033[0;36m
MAGENTA = \033[0;35m
YELLOW  = \033[1;33m
RESET = \033[0m

#==============================================================================#
#                                    RULES                                     #
#==============================================================================#

all: $(NAME) $(TEST_FILES)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "$(YELLOW)[Compiled]$(RESET) $<"

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "╔══════════════════════════╗"
	@echo "║ ✅ Compiled Successfully!║"
	@echo "╚══════════════════════════╝"

#==============================================================================#
#                                 TEST FILES                                   #
#==============================================================================#

input.txt:
	@printf "date | value\n\
2011-01-03 | 3\n\
2011-01-03 | 2\n\
2011-01-03 | 1\n\
2011-01-03 | 1.2\n\
2011-01-09 | 1\n\
2012-01-11 | -1\n\
2001-42-42\n\
2012-01-11 | 1\n\
2012-01-11 | 2147483648\n" > $@
	@echo "$(GREEN)[Created]$(RESET) $@"

input_edge.txt:
	@printf "date | value\n\
2009-01-01 | 5\n\
2008-12-31 | 5\n\
2030-01-01 | 5\n\
2011-01-03 | 0\n\
2011-01-03 | 1000\n\
2011-01-03 | 1000.1\n\
2011-01-03 | abc\n\
2011-01-03|5\n\
2011-02-29 | 1\n\
2012-02-29 | 1\n\
not a date | 5\n" > $@
	@echo "$(GREEN)[Created]$(RESET) $@"

empty_file.txt:
	@touch $@
	@echo "$(GREEN)[Created]$(RESET) $@"

windows.txt:
	@printf "date | value\r\n\
2011-01-03 | 3\r\n\
2011-01-03 | 2\r\n\
2011-01-03 | 1\r\n\
2011-01-03 | 1.2\r\n" > $@
	@echo "$(GREEN)[Created]$(RESET) $@"

#==============================================================================#
#                                    UTILS                                     #
#==============================================================================#

r: all
	@./$(NAME)

rv: all
	@$(VAL) ./$(NAME)

clean:
	@$(RM) $(OBJS)
	@echo "$(RED)[CLEAN] Object files removed.$(RESET)"

fclean: clean
	@$(RM) $(NAME) $(OBJ_DIR) $(TEST_FILES)
	@echo "$(RED)[FCLEAN] Binary and test files removed.$(RESET)"

re: fclean all

# Phony Targets
.PHONY: all clean fclean re r rv