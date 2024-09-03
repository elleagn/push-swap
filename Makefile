# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gozon <gozon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/28 08:35:14 by gozon             #+#    #+#              #
#    Updated: 2024/09/02 10:12:57 by gozon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

V = false

ifeq ($(V),true)
    ECHO =
else
    ECHO = @
endif

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = Libft/libft.a
SRC = fill_stack_a.c init_cleanup.c args_to_array.c is_valid.c quick_sort.c \
	stack_ops.c maths.c cheapest_move_element.c stack_a_to_stack_b.c moves.c \
	moves_2.c sort.c test_init.c
OBJ = $(SRC:.c=.o)

# Symboles Unicode
CHECK_MARK = ✔
UNCHECKED_MARK = ✘
COMP_SUCCESS = $(CHECK_MARK)
COMP_FAILURE = $(UNCHECKED_MARK)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compilation de push_swap en cours..."
	@$(ECHO)make -C Libft --silent --no-print-directory \
	&& { echo "Compilation de la Libft ($(COMP_SUCCESS))" ; } \
	|| { echo "Erreur : Compilation de la Libft échouée ($(COMP_FAILURE))" ; exit 1; }
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) \
	&& { echo "$(NAME) a été créé avec succès ($(COMP_SUCCESS))" ; } \
	|| { echo "Erreur : Compilation de $(NAME) échouée ($(COMP_FAILURE))" ; exit 1; }
	@echo "Compilation réussie ($(COMP_SUCCESS))"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(ECHO)make clean -C Libft --silent --no-print-directory
	$(ECHO)rm -f $(OBJ)
	@echo "Nettoyage réussi ($(COMP_SUCCESS))"

fclean: clean
	$(ECHO)rm -f $(NAME)
	$(ECHO)rm -f Libft/libft.a
	@echo "Nettoyage complet réussie ($(COMP_SUCCESS))"

re: fclean all

.PHONY: all clean fclean re

