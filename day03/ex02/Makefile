CC := clang++
CFLAGS := -Wall -Wextra -Werror -c -std=c++98 -w
LD := clang++
LDFLAGS := -arch x86_64 -e _main

SRCS := ClapTrap.cc FragTrap.cc ScavTrap.cc  main.cc
OBJS := $(patsubst %.cc, %.o, $(SRCS))
NAME := claptrap

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



