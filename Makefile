NAME := miniRT

CC := cc
CFLAGS := -Wall -Wextra -Werror

INCLUDE_DIR := include
LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a

UNAME_S := $(shell uname -s)

# =========================================================
# MiniLibX
# =========================================================

ifeq ($(UNAME_S),Linux)

	MLX_DIR := minilibx-linux
	MLX := $(MLX_DIR)/libmlx.a

	MLX_INCLUDES := -I$(MLX_DIR)
	MLX_FLAGS := -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

else ifeq ($(UNAME_S),Darwin)

	MLX_DIR := minilibx_opengl
	MLX := $(MLX_DIR)/libmlx.a

	MLX_INCLUDES := -I$(MLX_DIR)
	MLX_FLAGS := -L$(MLX_DIR) -lmlx \
		-framework OpenGL \
		-framework AppKit

else

	$(error Unsupported operating system: $(UNAME_S))

endif

# =========================================================
# Include
# =========================================================

INCLUDES := -I$(INCLUDE_DIR) \
			-I$(LIBFT_DIR) \
			$(MLX_INCLUDES)

# =========================================================
# Source files
# =========================================================

APP_FILES := \
	app/main.c \
	app/app.c \
	app/app_run.c \
	app/cleanup.c

MATH_FILES := \
	calc_vector/vec_basic.c \
	calc_vector/vec_color.c \
	calc_vector/vec_length.c \
	calc_vector/vec_scalar.c \
	calc_vector/vec_vec.c

OBJECT_FILES := \
	object/object.c \
	object/sphere.c

RENDER_FILES := \
	render/camera_ray.c \
	render/color.c \
	render/image.c \
	render/lighting.c \
	render/ray_color.c \
	render/render.c

MLX_FILES := \
	mlx/mlx_init.c \
	mlx/mlx_image.c \
	mlx/mlx_events.c \
	mlx/mlx_cleanup.c

PARSER_FILES := \
	parser/check_args.c \
	parser/error.c \
	parser/parse_scene.c \
	parser/read_file.c \
	parser/set_a_c_l.c \
	parser/set_sp_pl_cy.c \
	parser/set_utils.c \
	parser/validate_a_c_l.c \
	parser/validate_chars.c \
	parser/validate_format.c \
	parser/validate_lines.c \
	parser/validate_sp_pl_cy.c \
	parser/validate_structure.c

GNL_FILES := \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c

UTILS_FILES := \
	utils/splitting.c \
	utils/utils.c \
	utils/utils_for_debug.c

SRC_FILES := \
	$(APP_FILES) \
	$(MATH_FILES) \
	$(OBJECT_FILES) \
	$(RENDER_FILES) \
	$(MLX_FILES) \
	$(PARSER_FILES) \
	$(GNL_FILES) \
	$(UTILS_FILES)

SRC := $(addprefix src/, $(SRC_FILES))
OBJ := $(SRC:.c=.o)

# =========================================================
# Rules
# =========================================================

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

clean:
	$(RM) $(OBJ)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re

# NAME := minirt
# SRC_DIR := src
# INCLUDE_DIR := include
# LIBFT_DIR := libft

# MLX_DIR := minilibx-linux
# MLX := $(MLX_DIR)/libmlx.a

# CC := cc
# CFLAGS := -Wall -Wextra -Werror -I$(INCLUDE_DIR) -I$(MLX_DIR)
# RM := rm -f
# RMDIR := rm -rf

# MLX_FLAGS := -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

# GNL_FILES := get_next_line/get_next_line_utils.c \
#                 get_next_line/get_next_line.c 

# PARSER_FILES := parser/check_args.c \
#                 parser/error.c \
#                 parser/validate_chars.c \
#                 parser/read_file.c \
#                 parser/validate_structure.c \
#                 parser/validate_lines.c \
#                 parser/validate_format.c \
#                 parser/validate_a_c_l.c \
#                 parser/validate_sp_pl_cy.c \
#                 parser/set_utils.c \
#                 parser/set_a_c_l.c \
#                 parser/set_sp_pl_cy.c

# CALC_FILES := calc/ray.c \
#                 calc/hit.c

# CALC_VECTOR_FILES := calc_vector/vec_basic.c \
#                         calc_vector/vec_scalar.c \
#                         calc_vector/vec_vec.c \
#                         calc_vector/vec_length.c \
#                         calc_vector/vec_color.c

# MLX_UTILS_FILES := mlx_utils/utils.c \
#                 mlx_utils/render.c

# UTILS_FILES := utils/utils.c \
#                 utils/splitting.c \
#                 utils/utils_for_debug.c

# SRCFILES := main.c \
#             $(GNL_FILES) \
#             $(PARSER_FILES) \
#             $(CALC_VECTOR_FILES) \
#             $(UTILS_FILES) \
#             $(MLX_UTILS_FILES) \
#             $(CALC_FILES)

# SRCS := $(addprefix $(SRC_DIR)/, $(SRCFILES))
# OBJS := $(SRCS:%.c=%.o)

# LIBFT := $(LIBFT_DIR)/libft.a

# all: $(NAME)

# # 1. リンク: $(MLX) を依存関係に入れ、$(MLX_FLAGS) でリンクする
# $(NAME): $(LIBFT) $(MLX) $(OBJS)
# 	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

# # 2. libft のビルド
# $(LIBFT):
# 	$(MAKE) -C $(LIBFT_DIR) bonus

# # 3. MiniLibX のビルド
# $(MLX):
# 	$(MAKE) -C $(MLX_DIR)

# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

# # 4. clean で mlx 側のお掃除も呼ぶ
# clean:
# 	$(MAKE) -C $(LIBFT_DIR) clean
# 	$(MAKE) -C $(MLX_DIR) clean
# 	$(RM) $(OBJS)

# # 5. fclean (mlx-linux は fclean がない場合があるので clean で対応)
# fclean: clean
# 	$(MAKE) -C $(LIBFT_DIR) fclean
# 	$(RM) $(NAME)

# re: fclean all

# .PHONY: all clean fclean re
