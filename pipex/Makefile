NAME = pipex

$(NAME):
	$(MAKE) -C ./lib/ft_printf/
	gcc -Wall -Wextra $(CFILES) ./lib/ft_printf/libftprintf.a -o pipex

all : fclean $(NAME)

clean :
	rm -f $(OFILES)

fclean : clean
	rm -f $(NAME)

re : all

files = ./src/pipex \
		./src/pipex_utils \
		./src/px_split \

CFILES = $(files:%=%.c)
OFILES = $(files:%=%.o)

