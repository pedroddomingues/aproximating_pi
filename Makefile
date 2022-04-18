CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -rf

SRC_DIR	= src
SRC = colors.c pixels.c circle.c points.c main.c

# errors.c exit.c  gradients.c hooks.c instructions.c map.c points.c

OBJ_DIR	= obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

INCLUDE_DIR = ./include
INCLUDE = pi.h

MAIN =

LIBFT = ./libft/libft.a
LIBS = -lmlx -lXext -lX11 -lm

NAME = pi

VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=valgrind-out.txt

NORM = norminette.txt

vpath %.c $(SRC_DIR)
vpath %.h $(INCD_DIR)

all:	$(NAME)

$(NAME):	$(LIBFT) $(OBJ)
	@echo "Compiling pi..."
	@$(CC) $(CFLAGS) $(MAIN) $(OBJ) $(LIBFT) $(LIBS) -o $(NAME)
	@echo "Done."

$(OBJ_DIR)/%.o:	%.c
	@mkdir -p $(OBJ_DIR)
	@echo "Compiling $(basename $<)..."
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Done."

run:	all
	@echo "Running pi"
	@./$(NAME) $(MAP)

valgrind: all
	@echo "Running pi with Valgrind"
	@$(VALGRIND) ./$(NAME) $(MAP)

$(LIBFT):
	@echo "Compiling libft..."
	@make -C ./libft
	@echo "libft compiled successfully"

norminette: norminette_run norminette_return

norminette_run:
	@echo "Running norminette..."
	@touch $(NORM)
	@norminette | { grep 'Error' || true; } > $(NORM)

norminette_return:
	@if [ -s $(NORM) ]; then \
	echo "Norminette failed" &&\
	cat $(NORM);\
	else \
	echo "Norminette passed";\
	fi
	@rm -f $(NORM)

clean:
	@make clean -C ./libft
	@$(RM) $(OBJ_DIR)
	@$(RM) valgrind*

fclean:	clean
	@make fclean -C ./libft
	@$(RM) $(NAME)

re:	fclean all

git:
	git add .
	git status
	git commit -m "$m"
