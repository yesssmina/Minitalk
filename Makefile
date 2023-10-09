NAME_SERVER = server
NAME_CLIENT = client

BONUS_SERVER = server_bonus
BONUS_CLIENT = client_bonus

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SERVER_SRC = ./server.c \

CLIENT_SRC = ./client.c \

BONUS_SERVER_SRC = ./server_bonus.c \

BONUS_CLIENT_SRC = ./client_bonus.c \
			utils_bonus.c \

NB_SRCS = $(words $(SERVER_SRC) $(CLIENT_SRC))

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
BONUS_SERVER_OBJ = $(BONUS_SERVER_SRC:.c=.o)
BONUS_CLIENT_OBJ = $(BONUS_CLIENT_SRC:.c=.o)

LIBFT = ./libft.a
FT_PRINTF = ./libftprintf.a

all: $(NAME_SERVER) $(NAME_CLIENT)

bonus: $(BONUS_SERVER) $(BONUS_CLIENT)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@cat .loading_bar 2>/dev/null || printf "" > .loading_bar
	@printf '*' >> .loading_bar

$(NAME_SERVER): $(SERVER_OBJ)
	@echo "\033[0;1m"
	@printf '%*s' $(NB_SRCS) '' | tr ' ' '*' #print one star per file in SRCS
	@echo ""
	@make -s -C ./Libft/
	@make -s -C ./Printf/
	@$(CC) $(CFLAGS) $(SERVER_OBJ) -L./Libft -lft -L./Printf -lftprintf -o $(NAME_SERVER)
	@rm -f .loading_bar
	@echo "\033[1;32mMinitalk server: successful compilation\033[0m 🎇"

$(NAME_CLIENT): $(CLIENT_OBJ)
	@echo "\033[0;1m"
	@printf '%*s' $(NB_SRCS) '' | tr ' ' '*' #print one star per file in SRCS
	@echo ""
	@make -s -C ./Libft/
	@make -s -C ./Printf/
	@$(CC) $(CFLAGS) $(CLIENT_OBJ) -L./Libft -lft -L./Printf -lftprintf -o $(NAME_CLIENT)
	@rm -f .loading_bar
	@echo "\033[1;32mMinitalk client: successful compilation\033[0m 🎇"

$(BONUS_SERVER): $(BONUS_SERVER_OBJ)
	@echo "\033[0;1m"
	@printf '%*s' $(NB_SRCS) '' | tr ' ' '*' #print one star per file in SRCS
	@echo ""
	@make -s -C ./Libft/
	@make -s -C ./Printf/
	@$(CC) $(CFLAGS) $(BONUS_SERVER_OBJ) -L./Libft -lft -L./Printf -lftprintf -o $(BONUS_SERVER)
	@rm -f .loading_bar
	@echo "\033[1;32mMinitalk server bonus: successful compilation\033[0m 🎇"

$(BONUS_CLIENT): $(BONUS_CLIENT_OBJ)
	@echo "\033[0;1m"
	@printf '%*s' $(NB_SRCS) '' | tr ' ' '*' #print one star per file in SRCS
	@echo ""
	@make -s -C ./Libft/
	@make -s -C ./Printf/
	@$(CC) $(CFLAGS) $(BONUS_CLIENT_OBJ) -L./Libft -lft -L./Printf -lftprintf -o $(BONUS_CLIENT)
	@rm -f .loading_bar
	@echo "\033[1;32mMinitalk client bonus: successful compilation\033[0m 🎇"

clean:
	@make -s clean -C ./Libft/
	@make -s clean -C ./Printf/
	@rm -f $(SERVER_OBJ) $(CLIENT_OBJ) $(BONUS_SERVER_OBJ) $(BONUS_CLIENT_OBJ)
	@echo "\033[1;36m===>Minitalk: .o correctly cleaned\033[0m"

fclean: clean
	@rm -f $(NAME_SERVER) $(NAME_CLIENT) $(BONUS_SERVER) $(BONUS_CLIENT)
	@rm -f $(LIBFT)
	@rm -f $(PRINTF)
	@echo "\033[1;30mLibft: .a correctly cleaned\033[0m"
	@echo "\033[1;36m===>Minitalk: .a correctly cleaned\033[0m"

re: fclean all
