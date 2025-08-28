# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaxztan <jaxztan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/09 12:35:05 by chtan             #+#    #+#              #
#    Updated: 2025/08/22 14:18:06 by jaxztan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = ./PmergeMe
CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -pedantic -std=c++98 -g3
SRC_DIR     = ./src
INC_DIR     = ./inc
OBJ_DIR     = ./obj
SRCS        = $(wildcard $(SRC_DIR)/*.cpp)
OBJS        = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# ------------------------------------------------------------------#
# Rules to prevent relinking                                         #
# ------------------------------------------------------------------#
all: $(NAME)
	@echo "\033[0;32m✅ Program is ready!\033[0m"

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $@
	@echo "\033[0;32m🔧 Linking complete!\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "\033[0;31m🧹 Cleaned object files!\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;31m🗑️  Full clean complete!\033[0m"

re: fclean all

run: $(NAME)
	@./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
	@echo ""
	@./RPN "7 7 * 7 -"
	@echo ""
	@./RPN "1 2 * 2 / 2 * 2 4 - +"

invalid: $(NAME)
	@./RPN "(1 + 1)"
	@echo ""
	@./RPN 1 1 +
	@echo ""
	@./RPN "1 2 3 +"

.PHONY: all clean fclean re run