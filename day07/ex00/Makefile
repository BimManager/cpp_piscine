CC := clang++
CFLAGS := -Wall -Wextra -Werror -c -std=c++98 -g
LD := clang++
LDFLAGS := -arch x86_64 -e _main

SRCS := whatever.cc
OBJS := $(patsubst %.cc, %.o, $(SRCS))
NAME := ex00

all : $(NAME)
	@echo "Building...\nDone"

$(NAME) : $(OBJS)
	@$(LD) $(LDFLAGS) $^ -o $@

%.o : %.cc
	@$(CC) $(CFLAGS) $< -o $@

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re



