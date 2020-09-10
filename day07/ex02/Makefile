CC := clang++
CFLAGS := -Wall -Wextra -Werror -std=c++98 -c -g -Wno-deprecated
LD := clang++
LDFLAGS := -arch x86_64 -e _main

SRCS := main.cc
OBJS := $(patsubst %.cc,%.o,$(SRCS))
NAME := ex02

all : $(NAME)
	@echo "Building...\nDone"

$(NAME) : $(OBJS)
	$(LD) $(LDFLAGS) $^ -o $@

%.o : %.cc
	@$(CC) $(CFLAGS) $< -o $@

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re



