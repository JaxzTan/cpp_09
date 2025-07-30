# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chtan <chtan@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/09 12:35:05 by chtan             #+#    #+#              #
#    Updated: 2025/06/15 09:15:39 by chtan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = ./Program
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
	@./$(NAME)

.PHONY: all clean fclean re run