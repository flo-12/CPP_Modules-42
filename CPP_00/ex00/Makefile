
# Executable name
NAME		= megaphone

# Compiler
CC			= c++
FLAGS		= -Werror -Wextra -Wall -std=c++98

# Sources & Objects
SRC_FILES	= megaphone
SRC			= $(SRC_FILES:=.cpp)
OBJDIR		= .objs
OBJ			= $(addprefix $(OBJDIR)/, $(SRC_FILES:=.o))
#HEADER		=

# RULES
all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@echo "Compiling $(NAME)..."
	@$(CC) $(OBJ) -o $(NAME)
	@echo "\n\t\033[33;1;3m$(NAME) ready\033[0m\n"

$(OBJDIR)/%.o: $(SRC) $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@echo "Removing object files..."
	@rm -rf $(OBJDIR) $(OBJ)

fclean: clean
	@echo "Removing executable..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
