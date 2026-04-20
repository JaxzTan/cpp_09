# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaxztan <jaxztan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/09 12:35:05 by chtan             #+#    #+#              #
#    Updated: 2025/08/21 14:14:14 by jaxztan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = ./RPN
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

test: $(NAME)
	@printf '\033[1m=== RPN Test Suite ===\033[0m\n\n'; \
	EXPECTED="14 12 42 42 0 14 15 4 2 0"; \
	section=""; in_block=0; valid_idx=1; PASS=0; FAIL=0; \
	while IFS= read -r line; do \
		if [ "$$line" = "---" ]; then \
			if [ "$$in_block" = "0" ]; then \
				in_block=1; \
				printf '\033[1;34m[ %s ]\033[0m\n' "$$section"; \
			else \
				in_block=0; printf '\n'; \
			fi; \
		elif [ "$$in_block" = "0" ] && [ -n "$$line" ]; then \
			section="$$line"; \
		elif [ "$$in_block" = "1" ] && [ -n "$$line" ]; then \
			expr=$$(printf '%s' "$$line" | sed 's/^"//;s/"$$//'); \
			actual=$$(./RPN "$$expr" 2>&1); rc=$$?; \
			if [ "$$section" = "valid" ]; then \
				exp=$$(echo "$$EXPECTED" | tr ' ' '\n' | sed -n "$${valid_idx}p"); \
				valid_idx=$$((valid_idx + 1)); \
				if [ "$$actual" = "$$exp" ]; then \
					printf '  \033[32m[PASS]\033[0m  %-34s expected: %-4s  got: %s\n' "$$expr" "$$exp" "$$actual"; \
					PASS=$$((PASS + 1)); \
				else \
					printf '  \033[31m[FAIL]\033[0m  %-34s expected: %-4s  got: %s\n' "$$expr" "$$exp" "$$actual"; \
					FAIL=$$((FAIL + 1)); \
				fi; \
			else \
				if [ "$$rc" != "0" ]; then \
					printf '  \033[32m[PASS]\033[0m  %-34s => %s\n' "$$expr" "$$actual"; \
					PASS=$$((PASS + 1)); \
				else \
					printf '  \033[31m[FAIL]\033[0m  %-34s => expected error, got: %s\n' "$$expr" "$$actual"; \
					FAIL=$$((FAIL + 1)); \
				fi; \
			fi; \
		fi; \
	done < Files/test_case.txt; \
	printf '\033[1mResults: \033[32m%d passed\033[0m\033[1m, \033[31m%d failed\033[0m\n' "$$PASS" "$$FAIL"

.PHONY: all clean fclean re run test