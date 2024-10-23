NAME = bsq

FLAGS = -Wall -Wextra -Werror

SOURCES = browse_plateau.c\
	find_square.c\
	read_file.c\
	main.c\
	str.c\

OBJECTS = $(SOURCES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS) 
	@cc $(FLAGS) -o $(NAME) $(OBJECTS)
	
clean :
	@rm -f $(OBJECTS)

fclean : clean
	@rm -f $(NAME)
	
re : fclean all
