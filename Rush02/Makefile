NAME = Rush-02

CC = cc

CFLAGS = -Wall -Wextra -Werror 

SRCS = main.c utils.c parsing.c read_doc.c ft_split.c utilsbis.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
