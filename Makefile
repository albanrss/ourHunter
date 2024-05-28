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


SRC_FOLDER 		=	./src/

INIT_FOLDER 	=	$(SRC_FOLDER)init/

COMPUTE_FOLDER	=	$(SRC_FOLDER)compute/

CLASSES_FOLDER	=	$(SRC_FOLDER)classes/

APP_FOLDER		=	$(SRC_FOLDER)app/

ANALYZE_FOLDER	=	$(SRC_FOLDER)analyze/

DELETE_FOLDER 	=	$(SRC_FOLDER)delete/

SRC =	$(APP_FOLDER)app.cpp	\
		$(INIT_FOLDER)init_time.cpp	\
		$(INIT_FOLDER)init_duck.cpp	\
		$(CLASSES_FOLDER)ducks.cpp	\
		$(CLASSES_FOLDER)duck_impact.cpp	\
		$(ANALYZE_FOLDER)analyze_events.cpp	\
		$(COMPUTE_FOLDER)increment_rect.cpp	\
		$(DELETE_FOLDER)delete_img.cpp	\
		$(DELETE_FOLDER)delete_time.cpp	\
		$(SRC_FOLDER)vector_operations.cpp	\

SRC_MAIN =	$(SRC_FOLDER)main.cpp

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
	@find . -name *.o -exec rm -rf {} \;
	@rm -f *.gcno
	@rm -f *.gcda

fclean: clean
	@printf "$(RED)[🚫]$(BLUE)Fclean$(NC)\n"
	@rm -f $(NAME)
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
