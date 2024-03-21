
#-------------------COLORS------------------#
DEF = \033[0m
BOLD = \033[1m
UNDERLINE = \033[4m
RED = \033[31;2m
BLACK = \033[38;5;238m
BLUE = \033[38;5;153m
GREEN = \033[38;5;48m
YELLOW = \033[38;5;226m
ORANGE = \033[38;5;202m
PINK = \033[38;5;198m
PURPLE = \033[38;5;147m
UP = UP = \033[A

#-------------------SRCS--------------------#
SRCS	=	main.c \
			cub3d_utils.c \
			parsing/parsing.c \
			parsing/parsing_elem.c \
			parsing/parsing_param.c \
			parsing/parsing_map.c \
			execution/deal_hook.c \
			execution/raycasting.c \
			execution/init_vectors.c \
			execution/dda_algorithm.c \
			execution/colors.c

OBJS = $(SRCS:.c=.o)

#------------------COMPILE------------------#
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3
ifdef DEBUG
CFLAGS += -fsanitize=address -g3
endif

.c.o:
	@$(CC) $(CFLAGS) -c -I ./inc/ $< -o $(<:.c=.o)

#------------------RULES---------------------#
NAME = cub3d

all : $(NAME)

$(NAME): $(OBJS)
	@echo ""
	@echo "	$(BOLD)$(PINK)$(UNDERLINE)Compiling...$(DEF)  $(PURPLE)$(BOLD)Cub3d$(DEF) ⏳"
	@$(MAKE) -C ./Libft/
	@$(CC) $(CFLAGS) $(OBJS) ./Libft/libft.a -o $(NAME) -L ./minilibx-linux -lmlx -lXext -lX11 -lm
	@clear
	@echo "	$(YELLOW)$(BOLD)Compiled ! ✨$(DEF)"

debug: fclean
	@$(MAKE) DEBUG=1

clean:
	@$(MAKE) clean -C ./Libft/
	@rm -rf $(OBJS)
	@echo "	❌ $(BOLD)$(RED)Deleted file .o$(DEF)"

fclean: clean
	@rm -rf ./Libft/libft.a
	@rm -rf $(NAME)
	@echo "	❌ $(BOLD)$(RED)Deleted file .a$(DEF)"

re: fclean all

.PHONY: all clean fclean re debug
