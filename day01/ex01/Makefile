CC := clang++
CFLAGS := -Wall -Wextra -Werror -c
LD := clang++
LDFLAGS := -arch x86_64 -e _main

SRCS := ex01.cpp
OBJS := $(patsubst %.cpp, %.o, $(SRCS))
NAME := ex01

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



