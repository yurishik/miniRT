NAME := minirt
SRC_DIR := src
INCLUDE_DIR := include
LIBFT_DIR := libft

CC := cc
CFLAGS := -Wall -Wextra -Werror -I$(INCLUDE_DIR)
RM := rm -f
RMDIR := rm -rf

GNL_FILES := get_next_line/get_next_line_utils.c \
				get_next_line/get_next_line.c 

PARSER_FILES := parser/check_args.c \
				parser/error.c \
				parser/validate_chars.c \
				parser/read_file.c \
				parser/validate_structure.c \
				parser/validate_lines.c \
				parser/validate_format.c \
				parser/validate_a_c_l.c \
				parser/validate_sp_pl_cy.c

CALC_VECTOR_FILES := calc_vector/vec_basic.c \
						calc_vector/vec_scalar.c \
						calc_vector/vec_vec.c \
						calc_vector/vec_length.c

UTILS_FILES := utils/utils.c \
				utils/splitting.c \
				utils/utils_for_debug.c

SRCFILES := main.c \
			$(GNL_FILES) \
			$(PARSER_FILES) \
			$(CALC_VECTOR_FILES) \
			$(UTILS_FILES)

SRCS := $(addprefix $(SRC_DIR)/, $(SRCFILES))
OBJS := $(SRCS:%.c=%.o)

LIBFT := $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -lm -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) bonus

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
