NAME	= libft.a

CC	= cc

SRCS	= 	ft_atoi.c \
			ft_atod.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			get_next_line.c \
			get_next_line_utils.c 

OBJCS	= $(SRCS:.c=.o)

DEPS	= libft.h

CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME)	: $(OBJCS)
	@ar crs $(NAME) $(OBJCS)

%.o: %.c $(DEPS)
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -rf $(OBJCS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY	: all re clean fclean