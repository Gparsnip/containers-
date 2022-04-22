CC = clang++
FLAGS = -Wall -Wextra -Werror -MMD -std=c++98
DIR_OBJ = obj/
DIR_D_FILE = dep/

SRC_VECTOR =	test_vector.cpp

OBJ_VECTOR = $(addprefix $(DIR_OBJ), $(SRC_VECTOR:.cpp=.o))
D_FILES_VECTOR = $(addprefix $(DIR_D_FILE), $(SRC_VECTOR:.cpp=.d))

SRC_MAP =	test_map.cpp

OBJ_MAP = $(addprefix $(DIR_OBJ), $(SRC_MAP:.cpp=.o))
D_FILES_MAP = $(addprefix $(DIR_D_FILE), $(SRC_MAP:.cpp=.d))

SRC_STACK =	test_stack.cpp

OBJ_STACK = $(addprefix $(DIR_OBJ), $(SRC_STACK:.cpp=.o))
D_FILES_STACK = $(addprefix $(DIR_D_FILE), $(SRC_STACK:.cpp=.d))

all: vector map stack

vector: $(OBJ_VECTOR)
	@echo "\n"
	@echo "\033[0;32mCompiling vector..."
	@$(CC) $(OBJ_VECTOR) $(FLAGS) -o vector
	@echo "\n\033[0mDone !"

-include $(D_FILES_VECTOR)

map: $(OBJ_MAP)
	@echo "\n"
	@echo "\033[0;32mCompiling map..."
	@$(CC) $(OBJ_MAP) $(FLAGS) -o map
	@echo "\n\033[0mDone !"

-include $(D_FILES_MAP)

stack: $(OBJ_STACK)
	@echo "\n"
	@echo "\033[0;32mCompiling stack..."
	@$(CC) $(OBJ_STACK) $(FLAGS) -o stack
	@echo "\n\033[0mDone !"

-include $(D_FILES_STACK)

$(DIR_OBJ)%.o: %.cpp
	@mkdir -p $(DIR_OBJ)
	@mkdir -p $(DIR_D_FILE)
	@printf "\033[0;33mGenerating $(NAME) objects... %-33.33s\r" $@
	@${CC} ${FLAGS} -o $@ -c -MT $@ $< ; mv $(DIR_OBJ)*.d $(DIR_D_FILE)


clean:
	@echo "\nRemoving dependency..."
	@rm -rf $(DIR_D_FILE)
	@echo "\033[0m"
	@echo "Removing binaries..."
	@rm -rf $(DIR_OBJ)
	@rm -rf *_shrubbery
	@echo "\033[0m"

fclean:
	@echo "\033[0;31m\nDeleting dependency..."
	@rm -rf $(DIR_D_FILE)
	@echo "\033[0;31m\nDeleting objects..."
	@rm -rf $(DIR_OBJ)
	@echo "\nDeleting executable..."
	@rm -f vector
	@rm -f map
	@rm -f stack
	@echo "\nDeleting trash..."
	@rm -rf *_shrubbery
	@echo "\033[0m"

re: fclean all

.PHONY: clean fclean re