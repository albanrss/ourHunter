##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Compile files into a binary
##

GREEN=\033[0;32m
RED=\033[0;31m
YELLOW=\033[01;33m
BLUE=\e[1;34m
NC=\033[0m

SRC =	src/app/app.cpp	\
		src/init/init_time.cpp	\
		src/init/init_duck.cpp	\
		src/classes/ducks.cpp	\
		src/classes/duck_impact.cpp	\
		src/analyze/analyze_events.cpp	\
		src/compute/increment_rect.cpp	\
		src/vector_operations.cpp	\
		src/delete/delete_img.cpp	\
		src/delete/delete_time.cpp	\

SRC_MAIN =	src/main.cpp

OBJ = $(SRC:.cpp=.o)

OBJ_MAIN = $(SRC_MAIN:.cpp=.o)

NAME	=	our_hunter

CFLAGS	=	-I./includes/ -lsfml-graphics -lsfml-window -lsfml-system -lm -g

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_MAIN)
	@g++ -o $(NAME) $(OBJ) $(OBJ_MAIN) $(CFLAGS)
	@printf "$(BLUE)[🕹️ ] $(NAME), $(GREEN)Build complete ! $(NC)\n"

clean:
	@printf "$(RED)[🚫]$(BLUE)Clean$(NC)\n"
	@rm -f $(OBJ)
	@rm -f $(OBJ_MAIN)
	@rm -f $(LIBOBJ)
	@rm -f *.gcno
	@rm -f *.gcda

fclean: clean
	@printf "$(RED)[🚫]$(BLUE)Fclean$(NC)\n"
	@rm -f $(NAME)
	@rm -f libmy.a
	@rm -f $(OBJ)
	@rm -f $(OBJ_MAIN)
	@rm -f unit_tests

re: fclean all

run : all clean
	./$(NAME)

unit_tests: re
	@gcc -o unit_tests $(SRC) $(SRC_TESTS) $(CFLAGS_TEST)

tests_run: unit_tests
	./unit_tests --exclude="./lib"

code_line :
	find . -name '*.c' | xargs wc -l

%.o: %.cpp
	@printf "$(RED)[⚒️ $(YELLOW)]$(BLUE) Compiling, $(GREEN)$@$(NC)\n"
	@g++ -c $(CFLAGS) $< -o $@

zip_assets :
	@zip -r assets.zip assets
	@printf "$(BLUE)[📦] Zipping assets, $(GREEN)complete ! $(NC)\n"

unzip_assets:
	@unzip -o assets.zip -d .
	@printf "$(BLUE)[📦] Unzipping assets, $(GREEN)complete ! $(NC)\n"

.PHONY: clean fclean
