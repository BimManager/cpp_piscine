CC := clang++
CFLAGS := -Wall -Wextra -Werror -c
LD := clang++
LDFLAGS := -arch x86_64 -e _main

SRCS := megaphone.cpp
OBJS := $(patsubst %.cpp, %.o, $(SRCS))
NAME := megaphone

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



