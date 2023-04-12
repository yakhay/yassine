NAME = builtins
SRC = builtins.c cmd_cd.c cmd_echo.c cmd_pwd.c env.c exit.c export.c fill_env.c unset.c
#BONUS			= ./Get_Next_Line/get_next_line_utils.c ./Get_Next_Line/get_next_line.c checker.c  function.c test3.c ft_chek.c ft_ss_rr_rrr.c
CFLAGS			= -Wall -Wextra -Werror -lreadline -g3 -fsanitize=address
all : $(SRC)
	gcc $(CFLAGS) $(SRC) ../libft/libft.a -o $(NAME)



#clean:

fclean:			clean


re:				fclean all
