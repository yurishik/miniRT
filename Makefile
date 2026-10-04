NAME := minirt
SRC_DIR := src
INCLUDE_DIR := include
LIBFT_DIR := libft

MLX_DIR := minilibx-linux
MLX := $(MLX_DIR)/libmlx.a

CC := cc
CFLAGS := -Wall -Wextra -Werror -I$(INCLUDE_DIR) -I$(MLX_DIR)
RM := rm -f
RMDIR := rm -rf

MLX_FLAGS := -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

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
                parser/validate_sp_pl_cy.c \
                parser/set_utils.c \
                parser/set_a_c_l.c \
                parser/set_sp_pl_cy.c

CALC_FILES := calc/ray.c \
                calc/hit.c

CALC_VECTOR_FILES := calc_vector/vec_basic.c \
                        calc_vector/vec_scalar.c \
                        calc_vector/vec_vec.c \
                        calc_vector/vec_length.c \
                        calc_vector/vec_color.c

MLX_UTILS_FILES := mlx_utils/utils.c \
                mlx_utils/render.c

UTILS_FILES := utils/utils.c \
                utils/splitting.c \
                utils/utils_for_debug.c

SRCFILES := main.c \
            $(GNL_FILES) \
            $(PARSER_FILES) \
            $(CALC_VECTOR_FILES) \
            $(UTILS_FILES) \
            $(MLX_UTILS_FILES) \
            $(CALC_FILES)

SRCS := $(addprefix $(SRC_DIR)/, $(SRCFILES))
OBJS := $(SRCS:%.c=%.o)

LIBFT := $(LIBFT_DIR)/libft.a

all: $(NAME)

# 1. リンク: $(MLX) を依存関係に入れ、$(MLX_FLAGS) でリンクする
$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

# 2. libft のビルド
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) bonus

# 3. MiniLibX のビルド
$(MLX):
	$(MAKE) -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 4. clean で mlx 側のお掃除も呼ぶ
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	$(RM) $(OBJS)

# 5. fclean (mlx-linux は fclean がない場合があるので clean で対応)
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
