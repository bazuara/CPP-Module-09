NAME = RPN

# Source files
SOURCE_FOLDER = src/
SOURCE_FILES = 	RPN.cpp \
				main.cpp

SOURCES = $(addprefix $(SOURCE_FOLDER), $(SOURCE_FILES))

# Objects
OBJECTS= $(SOURCE_FILES:.cpp=.o)
# OBJECTS = $(addprefix $(OBJECT_FOLDER), $(OBJECT_FILES))

# Headers
HEADERS_FOLDER	= include/

# Flags and output
CXXCFLAGS = -Wall -Wextra -Werror -std=c++98

# Valgrind flags
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all --verbose --log-file=leaks.$(NAME).txt

# arguments for binary
BIN_ARGS_1 = '8 9 * 9 - 9 - 9 - 4 - 1 +'
BIN_ARGS_2 = '7 7 * 7 -'
BIN_ARGS_3 = '1 2 * 2 / 2 * 2 4 - +'

all: $(NAME)

# Rule to build your object files and link them into a binary
$(NAME): $(OBJECTS)
	@echo "🚧 Compiling binary... 🚧"
	@c++ $(OBJECTS) -o $(NAME)
	@echo "✅ Done!"

#objects
$(OBJECTS):
	@echo "🚧 Compiling objects... 🚧"
	@c++  -c $(SOURCES) $(CXXCFLAGS) -I$(HEADERS_FOLDER)
	@echo "✅ Done!"
# Rule to remove object files
clean:
	@echo "🧹 Deleting objects..."
	@rm -f $(OBJECTS)
	@echo "🧹 Deleting leaks reports..."
	@rm -f leaks.$(NAME).txt
	@echo "✅ Done!"
# Rule to remove binary, calls the 'clean' rule first
fclean: clean
	@rm -f $(NAME)
	@echo "🧹 Deleting binary named $(NAME)"

# Rule to remove object files and binary, then re-build everything
re:	fclean all

# Rule to test norminette
normi:	
	@cpplint --root=include $(SOURCES) $(HEADERS_FOLDER)*

# Rule to debug, include norminette and similars
test: re
	@echo "⚡️Binary execution⚡️\n"
	@echo "🔥Test 1🔥: $(BIN_ARGS_1)"
	@./$(NAME) $(BIN_ARGS_1)
	@echo "🔥Test 2🔥: $(BIN_ARGS_2)"
	@./$(NAME) $(BIN_ARGS_2)
	@echo "🔥Test 3🔥: $(BIN_ARGS_3)"
	@./$(NAME) $(BIN_ARGS_3)
	@echo "\n🛡️Valgrind execution🛡️\n"
	@echo "🔥Test 1🔥: $(BIN_ARGS_1)"
	@valgrind $(VALGRIND_FLAGS) ./$(NAME) $(BIN_ARGS_1)
	@echo "🔥Test 2🔥: $(BIN_ARGS_2)"
	@valgrind $(VALGRIND_FLAGS) ./$(NAME) $(BIN_ARGS_2)
	@echo "🔥Test 3🔥: $(BIN_ARGS_3)"
	@valgrind $(VALGRIND_FLAGS) ./$(NAME) $(BIN_ARGS_3)

	@echo "\n📚Valgrind summary📚\nCheck leaks.$(NAME).txt for a detailed report."
	@cat leaks.$(NAME).txt | grep 'ERROR SUMMARY'
