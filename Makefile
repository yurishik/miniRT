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
				parser/validate_line.c \
				parser/read_file.c

UTILS_FILES := utils/utils.c

SRCFILES := main.c \
			$(GNL_FILES) \
			$(PARSER_FILES) \
			$(UTILS_FILES)

SRCS := $(addprefix $(SRC_DIR)/, $(SRCFILES))
OBJS := $(SRCS:%.c=%.o)

LIBFT := $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -lreadline -o $(NAME)

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
