

# Executable name
NAME		= DynamicCast

# Compiler
CC			= c++
FLAGS		= -Wextra -Wall -Werror -std=c++98

# Sources & Objects
OBJDIR		= .objFiles
SRC_FILES	= main  
SRC			= $(SRC_FILES:=.cpp)
OBJ			= $(addprefix $(OBJDIR)/, $(SRC_FILES:=.o))
HEADER		= Base.hpp A.hpp B.hpp C.hpp

# RULES
all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@echo "Compiling $(NAME)..."
	@$(CC) $(OBJ) -o $(NAME)
	@echo "\n\t\033[33;1;3m$(NAME) ready\033[0m\n"

$(OBJDIR)/%.o: %.cpp $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@echo "Removing object files..."
	@rm -rf $(OBJDIR) $(OBJ)

fclean: clean
	@echo "Removing executable and object files..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
