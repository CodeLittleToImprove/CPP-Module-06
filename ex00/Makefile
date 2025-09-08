# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbui-quo <tbui-quo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 16:12:00 by tbui-quo          #+#    #+#              #
#    Updated: 2025/09/01 18:44:10 by tbui-quo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CXX = c++

# Compiler flags
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Target executable
TARGET = convert

# Source files (using wildcard)
SRC = $(wildcard *.cpp)

# Object files (replace .cpp with .o)
OBJ = $(SRC:.cpp=.o)

# Default target
all: $(TARGET)

# Linking the object file(s) to create the executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Compiling each source file to object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Clean up object files
clean:
	rm -f $(OBJ)

# Remove both object files and executable
fclean: clean
	rm -f $(TARGET)

# Optional: rebuild everything (full clean + rebuild)
re: fclean all

# Run tests
test: $(TARGET)
	@echo "Running tests..."
	@echo "---- Test 1: integer ----"
	@./$(TARGET) 42
	@echo "---- Test 2: char ----"
	@./$(TARGET) a
	@echo "---- Test 3: float ----"
	@./$(TARGET) 3.14f
	@echo "---- Test 4: double ----"
	@./$(TARGET) 2.71828
	@echo "---- Test 5: nan ----"
	@./$(TARGET) nan
	@echo "---- Test 6: +inf ----"
	@./$(TARGET) +inf
	@echo "---- Test 7: string ----"
	@./$(TARGET) hello
	@echo "---- Test 9: nanf ----"
	@./$(TARGET) nanf
	@echo "---- Test 10: no argument ----"
	@./$(TARGET) || true
