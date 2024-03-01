NAME = libftprintf.a

$(NAME) :
	gcc -Wall -Wextra -Werror -c $(CFILES)
	ar -rc libftprintf.a $(OFILES)

all : fclean $(NAME)

clean : 
	rm -f $(OFILES)

fclean : clean
	rm -f $(NAME)

re : all

files	= ft_isalpha \
		  ft_isdigit \
		  ft_isalnum \
		  ft_isascii \
		  ft_isprint \
		  ft_strlen \
		  ft_memset \
		  ft_bzero \
		  ft_memcpy \
		  ft_memmove \
		  ft_strlcpy \
		  ft_strlcat \
		  ft_toupper \
		  ft_tolower \
		  ft_strchr \
		  ft_strrchr \
		  ft_strncmp \
		  ft_memchr \
		  ft_memcmp \
		  ft_strnstr \
		  ft_atoi \
		  ft_calloc \
		  ft_strdup \
		  ft_substr \
		  ft_strjoin \
		  ft_strtrim \
		  ft_split \
		  ft_itoa \
		  ft_strmapi \
		  ft_striteri \
		  ft_putchar_fd \
		  ft_putstr_fd \
		  ft_putendl_fd \
		  ft_putnbr_fd \
		  ft_printf \
		  ft_printf_utils \
		  ft_print_hex \
		  ft_print_ptr \
		  ft_print_unsigned

CFILES	= $(files:%=%.c)
OFILES	= $(files:%=%.o)
