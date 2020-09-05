CC := clang++
CFLAGS := -Wall -Wextra -Werror -c -std=c++98 -w -g
LD := clang++
LDFLAGS := -arch x86_64 -e _main

SRCS := Bureaucrat.cc Form.cc ShrubberyCreationForm.cc \
	RobotomyRequestForm.cc PresidentialPardonForm.cc \
	Intern.cc main.cc
OBJS := $(patsubst %.cc, %.o, $(SRCS))
NAME := ex03

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



