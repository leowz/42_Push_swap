# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zweng <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 18:11:43 by zweng             #+#    #+#              #
#    Updated: 2018/06/25 19:10:24 by zweng            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

# ----- part to change -----
PS_NAME = push_swap

CK_NAME = checker

LIB_PATH = libft

LIB = $(LIB_PATH)/libft.a

STC_PATH = stack_folder

STC_HEADER = stack.h

STC_SRC_NAME = stack_r.c stack_s.c stack_p.c stack_rr.c stack_singleton.c\
			   stack_exit.c stack_print.c stack_parse.c stack_is_sorted.c

PS_PATH = push_folder

PS_HEADER_PATH = $(PS_PATH)/includes

PS_SRC_PATH = $(PS_PATH)/srcs

PS_SRC_NAME = push_swap.c ps_print.c ps_quick_sort.c ps_insert_sort.c ps_small_sort.c\
            ps_sort.c ps_quick_sort_a.c ps_quick_sort_b.c \
			ps_sort_top.c ps_optim_cmd.c ps_optim1.c ps_optim2.c

CK_PATH = check_folder

CK_SRC_PATH = $(CK_PATH)/srcs

CK_HEADER_PATH = $(CK_PATH)/includes

CK_SRC_NAME = checker.c ck_error.c ck_print_is_sorted.c ck_exec_cmd.c

HEADER = $(PS_HEADER_PATH)/push_swap.h $(CK_HEADER_PATH)/checker.h

OBJ_PATH = obj

PS_OBJ_NAME = $(PS_SRC_NAME:.c=.o) $(STC_SRC_NAME:.c=.o)

CK_OBJ_NAME = $(CK_SRC_NAME:.c=.o) $(STC_SRC_NAME:.c=.o)

CPPFLAGS = -I$(CK_HEADER_PATH) -I$(PS_HEADER_PATH) -I$(LIB_PATH)/includes -I$(STC_PATH)

LDFLAGS = -L$(LIB_PATH) -fsanitize=address

LDLIBS = -lft

CFLAGS =  -Wall -Wextra -Werror

# ----- part automatic -----
PS_SRCS = $(addprefix $(PS_SRC_PATH)/,$(SRC_NAME)) \
	   $(addprefix $(STC_PATH)/,$(STC_SRC_NAME))
PS_OBJS = $(addprefix $(OBJ_PATH)/,$(PS_OBJ_NAME))
CK_SRCS = $(addprefix $(CK_SRC_PATH)/,$(CK_SRC_NAME))\
	   $(addprefix $(STC_PATH)/,$(STC_SRC_NAME))
CK_OBJS = $(addprefix $(OBJ_PATH)/,$(CK_OBJ_NAME))

# ----- Colors -----
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"
#  # ==================

# ----- part rules -----
all: $(PS_NAME) $(CK_NAME)

$(PS_NAME): $(LIB) $(PS_OBJS)
	$(CC) $(PS_OBJS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -o $@
	printf $(GREEN)"$(NAME) Finish linking\n"$(EOC)

$(CK_NAME): $(LIB) $(CK_OBJS)
	$(CC) $(CK_OBJS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -o $@
	printf $(GREEN)"$(NAME) Finish linking\n"$(EOC)

$(LIB):
	@make -C $(LIB_PATH) fclean && make -C $(LIB_PATH)

$(OBJ_PATH)/%.o: $(PS_SRC_PATH)/%.c  $(HEADER) | $(OBJ_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(OBJ_PATH)/%.o: $(CK_SRC_PATH)/%.c  $(HEADER) | $(OBJ_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(OBJ_PATH)/%.o: $(STC_PATH)/%.c  $(STC_PATH)/$(STC_HEADER) | $(OBJ_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(OBJ_PATH):
	mkdir $(OBJ_PATH) 2> /dev/null

clean:
	@rm -f $(PS_OBJS) $(CK_OBJS)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@printf $(GREEN)"$(NAME) clean\n"$(EOC)
	@make -C $(LIB_PATH) clean

fclean: clean
	@/bin/rm -f $(PS_NAME) $(CK_NAME)
	@printf $(GREEN)"$(NAME) fclean\n"$(EOC)
	@/bin/rm -f $(LIB)
	@printf $(GREEN)"$(LIB) fclean\n"$(EOC)

re: fclean all

norme:
	@norminette $(PS_SRCS) $(CK_SRCS)
	@norminette $(HEADER)

.PHONY: clean fclean all
