TARGET = git
CC = clang
FLAGS = -Wall -Werror -Wextra

SRC = main.c
SRCDIR = ./srcs/
SRCS = $(addprefix $(SRCDIR), $(SRC))

OBJ = $(SRC:.c=.o)
OBJDIR = ./objs/
OBJS = $(addprefix $(OBJDIR), $(OBJ))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(FLAGS) -o $(TARGET) $(OBJS)

$(OBJS):
	$(CC) $(FLAGS) -c $(SRCS)
	mv $(OBJ) $(OBJDIR)

clean:
	-rm -rf $(OBJS)
	-rm -rf $(OBJ)

fclean: clean
	-rm $(TARGET)

re:  fclean all
