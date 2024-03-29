TARGET = git
CC = clang
FLAGS = -Wall -Werror -Wextra

SRC = main.c init.c config.c
SRCDIR = ./srcs/
SRCS = $(addprefix $(SRCDIR), $(SRC))

OBJ = $(SRC:.c=.o)
OBJDIR = ./objs/
OBJS = $(addprefix $(OBJDIR), $(OBJ))

INC = -I ./includes/
SANITIZE = -fsanitize=address,undefined -ferror-limit=10

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(FLAGS) -o $(TARGET) $(SANITIZE) $(OBJS)

$(OBJS):
	$(CC) $(FLAGS) $(INC) -c $(SRCS)
	mv $(OBJ) $(OBJDIR)

clean:
	-rm -rf $(OBJS)
	-rm -rf $(OBJ)

fclean: clean
	-rm $(TARGET)

re:  fclean all
