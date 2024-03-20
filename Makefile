NAME = minishell
MKDIR = mkdir

CC = gcc

LIBFTP = libft
PATHB = build/
PATHO = build/objs/
PATHS = src/
PATHSL = src/lexer/
PATHSP = src/parser/
PATHSB = src/builtins/
PATHSEX = src/expander/
PATHSU = src/utils/
PATHSE = src/error/
PATHP = src/pipex/
PATHEX = src/executor/

BUILD_PATHS = $(PATHB) $(PATHO)

src	=	src/main.c \
		src/ft_list_tokens.c \
		src/engine.c	\
		src/init_all.c	\
		src/utils.c		\
		src/pipex_utils.c \
		src/px_split.c \
		# src/cd.c \
		# src/echo.c \
		# src/env.c \
		# src/pwd.c \


OBJS	=	$(addprefix $(PATHO), $(notdir $(patsubst %.c, %.o, $(src))))

FLAGS	=	-Wall -Werror -Wextra -g #-fsanitize=address

LIBFT	=	libft/libft.a

HEADER	=	.includes/builtins.h \
			.includes/color.h \
			.includes/error.h \
			.includes/executor.h \
			.includes/lexer.h \
			.includes/minishell.h \
			.includes/parser.h \
			.includes/utils.h 

READLINE_DIR = $(shell brew --prefix readline)

READLINE_LIB = -lreadline -lhistory -L $(READLINE_DIR)/lib
	
INCLUDES =-Iincludes -I$(PATHP) -I$(LIBFTP) -I$(READLINE_DIR)/include 

all: $(BUILD_PATHS) $(NAME)

$(PATHO)%.o:: $(PATHS)%.c
	@echo "Compiling ${notdir $<}			in	$(PATHS)"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHSL)%.c $(HEADERS)
	@echo "Compiling ${notdir $<}			in	$(PATHSL)"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHSP)%.c $(HEADERS)
	@echo "Compiling ${notdir $<}			in	$(PATHSP)"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHSB)%.c $(HEADERS)
	@echo "Compiling ${notdir $<}			in	$(PATHSB)"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHSEX)%.c $(HEADERS)
	@echo "Compiling ${notdir $<}			in	$(PATHSEX)"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHSU)%.c $(HEADERS)
	@echo "Compiling ${notdir $<}			in	$(PATHSU)"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHSE)%.c $(HEADERS)
	@echo "Compiling ${notdir $<}			in	$(PATHSE)"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATHO)%.o:: $(PATHEX)%.c $(HEADERS)
	@echo "Compiling ${notdir $<}			in	$(PATHEX)"
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(NAME): $(LIBFT) $(OBJS) $(HEADERS)
	@$(CC) $(FLAGS) $(LIBFT) $(OBJS) $(READLINE_LIB) -o $(NAME)

	@echo "Success"

$(LIBFT):
	@$(MAKE) -C ./libft

$(PATHB):
	@$(MKDIR) $(PATHB)

$(PATHO):
	@$(MKDIR) $(PATHO)

clean:
	@echo "Cleaning"
	@rm -f $(OBJS)
	@rm -f $(PATHB).tmp*
	@rmdir $(PATHO) $(PATHB)
	@make fclean -C libft

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)

re: fclean all

.PRECIOUS: $(PATHO)%.o