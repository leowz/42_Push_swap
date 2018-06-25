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
NAME1 = push_swap

NAME2 = checker

NAME1_PATH = push_folder

NAME2_PATH = check_folder

CURRENT_PATH = .

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
all: $(NAME1) $(NAME2) 

$(NAME1): $(NAME1_PATH)/$(NAME1)
	@cp $(NAME1_PATH)/$(NAME1) $(CURRENT_PATH) 

$(NAME1_PATH)/$(NAME1):
	@make -C $(NAME1_PATH) 

$(NAME2): $(NAME2_PATH)/$(NAME2)
	@cp $(NAME2_PATH)/$(NAME2) $(CURRENT_PATH) 

$(NAME2_PATH)/$(NAME2):
	@make -C $(NAME2_PATH) 
	

clean:
	@make -C $(NAME1_PATH) clean
	@make -C $(NAME2_PATH) clean

fclean:
	@rm -f $(NAME1) $(NAME2)
	@make -C $(NAME1_PATH) fclean
	@make -C $(NAME2_PATH) fclean

re: fclean all

norme:
	@make -C $(NAME1_PATH) norme
	@make -C $(NAME2_PATH) norme

.PHONY: clean fclean all
