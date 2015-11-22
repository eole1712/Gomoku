NAME = Gomoku

all:
	make -C build all

$(NAME):
	make -C build $(NAME)

clean:
	make -C build clean

fclean:
	make -C build clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
