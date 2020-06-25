CC := clang++
CFLAGS := -Wall -Wextra -Werror -c -std=c++98
LD := clang++
LDFLAGS := -arch x86_64 -e _main

SRCS := Brain.cpp Human.cpp main.cpp 
OBJS := $(patsubst %.cpp, %.o, $(SRCS))
NAME := brain

all : $(NAME)

$(NAME) : $(OBJS)
	$(LD) $(LDFLAGS) $^ -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re



