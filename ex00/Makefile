# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chtan <chtan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/09 12:35:05 by chtan             #+#    #+#              #
#    Updated: 2026/05/02 15:21:15 by chtan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = ./btc
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
	@./$(NAME) Files/mandatory.txt

invalid: $(NAME)
	@./$(NAME) Files/empty.txt
	@sleep 1
	@./$(NAME) Files/invalid.txt

.PHONY: all clean fclean re run