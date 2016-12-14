OBJ = $(SRC:.c=.o)
FLAG = -Wall -Werror -Wextra
#-fsanitize=address
CG = \033[92m
CY =  \033[93m
CE = \033[0m
CB = \033[34m

all: $(NAME)

$(NAME):
	@echo "ici"
	@echo "\033[K$(CY)[42SH] :$(CE) $(CG)Compiling send(CE) \033[1A";
	@gcc -o send $(FLAG) send.c;
	@echo "\033[K$(CY)[42SH] :$(CE) $(CG)Compiling recv(CE) \033[1A";
	@gcc -o recv $(FLAG) recv.c;


clean:
	@echo "\033[K$(CY)[42SH] :$(CE) $(CG)Cleaning objects$(CE)\033[1A";
	@/bin/rm -rf $(OBJ)

fclean: clean
	@echo "\033[K$(CY)[42SH] :$(CE) $(CG)Cleaning files ...$(CE)\033[1A";
	@/bin/rm -f send;
	@/bin/rm -f recv;

re: fclean all

.PHONY: all clean fclean re