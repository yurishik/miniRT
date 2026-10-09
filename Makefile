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

SHELL := /bin/bash
TARGET := ./miniRT

define TEST_CASES
# ==============================================================================
# VALID CASES (正常系 / レンダリングを通すべきファイル)
# ==============================================================================
# rt_files/sample.rt                  : 基本的な構成要素（A, C, L, 各オブジェクト）を含む標準シーン
# rt_files/one_sphere.rt              : 最小構成のオブジェクト（球1つのみ）を含むシーン
# rt_files/no_objects.rt              : オブジェクトなし（A, C, L のみで背景色描画を許容）
# rt_files/interleaved_empty_lines.rt : 定義行の間に挟まれた連続空行をスキップして処理可能
# rt_files/leading_trailing_spaces.rt : 行頭・行末の余分なスペースをトリムして処理可能
# rt_files/no_newline_eof.rt          : ファイル末尾（EOF直前）に改行がなくても正常にパース可能
# rt_files/crlf_endings.rt            : Windows形式の改行コード (\r\n) を許容
# rt_files/tab_separated.rt           : スペースの代わりに水平タブ (\t) 区切りを許容
# rt_files/explicit_plus_sign.rt      : 明示的な正の符号（+0.0, +255 など）が付いた数値を許容
# rt_files/norm_not_normalized.rt     : 各成分[-1,1]の非単位ベクトル（ゼロベクトル以外）をプログラム側で自動正規化して描画
# ==============================================================================
# INVALID CASES: 要素数 (A, C, L の過不足)
# ==============================================================================
rt_files/no_ambient.rt:              Invalid number of A
rt_files/no_camera.rt:               Invalid number of C
rt_files/no_light.rt:                Invalid number of L
rt_files/multi_ambient.rt:           Invalid number of A
rt_files/multi_camera.rt:            Invalid number of C
rt_files/multi_light.rt:             Invalid number of L

# ==============================================================================
# INVALID CASES: 識別子・引数の個数
# ==============================================================================
rt_files/unknown_identifier.rt:      Failed to read file
rt_files/lowercase_identifier.rt:    Failed to read file
rt_files/extra_element.rt:           Ambient: Invalid argument count
rt_files/missing_element.rt:         Ambient: Invalid argument count

# ==============================================================================
# INVALID CASES: 数値・カンマフォーマット
# ==============================================================================
rt_files/char_in_float.rt:           Failed to read file
rt_files/double_dot.rt:              Camera: Invalid viewpoint coordinates
rt_files/hanging_dot.rt:             Camera: Invalid viewpoint coordinates
rt_files/dot_only.rt:                Sphere: Invalid center coordinates
rt_files/sign_only.rt:               Camera: Invalid viewpoint coordinates
rt_files/multiple_signs.rt:          Camera: Invalid viewpoint coordinates
rt_files/scientific_notation.rt:     Failed to read file
rt_files/numeric_overflow.rt:        Camera: Invalid viewpoint coordinates
rt_files/huge_fractional_digits.rt:  Camera: Invalid viewpoint coordinates
rt_files/space_around_comma.rt:      Camera: Invalid argument count
rt_files/comma_inner_spaces.rt:      Sphere: Invalid argument count
rt_files/missing_comma.rt:           Camera: Invalid argument count
rt_files/extra_comma.rt:             Camera: Invalid viewpoint coordinates
rt_files/comma_leading_trailing.rt:  Sphere: Invalid center coordinates
rt_files/consecutive_commas.rt:      Sphere: Invalid center coordinates
rt_files/only_two_coords.rt:         Camera: Invalid viewpoint coordinates
rt_files/four_coords.rt:             Camera: Invalid viewpoint coordinates

# ==============================================================================
# INVALID CASES: 色 (RGB)
# ==============================================================================
rt_files/rgb_negative.rt:            Ambient: Invalid RGB format
rt_files/rgb_over_max.rt:            Ambient: Invalid RGB format
rt_files/rgb_float.rt:               Ambient: Invalid RGB format

# ==============================================================================
# INVALID CASES: 比率・明るさ・FOV
# ==============================================================================
rt_files/ambient_ratio_neg.rt:       Ratio out of range
rt_files/ambient_ratio_over.rt:      Ratio out of range
rt_files/light_brightness_neg.rt:    Brightness out of range
rt_files/light_brightness_over.rt:   Brightness out of range
rt_files/fov_negative.rt:            Camera: FOV out of range [0, 180]
rt_files/fov_zero.rt:                Camera: FOV cannot be 0 (division by zero)
rt_files/fov_exact_0.rt:             Camera: FOV cannot be 0 (division by zero)
rt_files/fov_over_180.rt:            Camera: FOV out of range [0, 180]
rt_files/fov_exact_180.rt:           Camera: FOV cannot be 180 (infinite viewport)
rt_files/fov_float.rt:               Camera: FOV must be a valid number

# ==============================================================================
# INVALID CASES: 方向・法線ベクトル
# ==============================================================================
rt_files/norm_vector_zero.rt:        Camera: Invalid orientation vector
rt_files/norm_out_of_range.rt:       Camera: Invalid orientation vector
rt_files/cam_norm_zero.rt:           Camera: Invalid orientation vector
rt_files/pl_norm_zero.rt:            Plane: Invalid normal vector
rt_files/cy_norm_zero.rt:            Cylinder: Invalid axis normal vector

# ==============================================================================
# INVALID CASES: 形状寸法 (直径・高さ)
# ==============================================================================
rt_files/sp_diameter_neg.rt:         Sphere: Diameter must be greater than 0
rt_files/sp_diameter_zero.rt:        Sphere: Diameter must be greater than 0
rt_files/cy_diameter_neg.rt:         Cylinder: Invalid value (must be positive)
rt_files/cy_diameter_zero.rt:        Cylinder: Invalid value (must be positive)
rt_files/cy_height_neg.rt:           Cylinder: Invalid value (must be positive)
rt_files/cy_height_zero.rt:          Cylinder: Invalid value (must be positive)

# ==============================================================================
# INVALID CASES: ファイル・システム・読み込み
# ==============================================================================
rt_files/mixed_whitespace.rt:        Failed to read file
rt_files/empty_file.rt:              Failed to read file
rt_files/empty_lines_only.rt:        Failed to read file
rt_files/extremely_long_line.rt:     Failed to read file
rt_files/no_permission.rt:           Failed to read file
rt_files/is_a_directory.rt:          Failed to read file
rt_files/non_existent.rt:            Failed to read file
rt_files/no_extension:               Invalid file extension
rt_files/.rt:                        Invalid file extension
rt_files/scene.RT:                   Invalid file extension
rt_files/scene.rt.txt:               Invalid file extension
rt_files/scene.rt_:                  Invalid file extension
endef
export TEST_CASES

.PHONY: test

test:
	@FAILED=0; \
	PASSED=0; \
	TOTAL=0; \
	while IFS=: read -r file expected; do \
		file=$$(echo "$$file" | sed -e 's/^[[:space:]]*//' -e 's/[[:space:]]*$$//'); \
		[ -z "$$file" ] && continue; \
		case "$$file" in \#*) continue ;; esac; \
		expected=$$(echo "$$expected" | sed -e 's/^[[:space:]]*//'); \
		TOTAL=$$((TOTAL + 1)); \
		output=$$($(TARGET) "$$file" 2>&1); \
		\
		has_detail=$$(echo "$$output" | grep -Fiq "$$expected" && echo 1 || echo 0); \
		first_line=$$(echo "$$output" | head -n 1 | tr -d '\r'); \
		is_error_prefix=0; \
		if [ "$$first_line" = "Error" ]; then is_error_prefix=1; fi; \
		\
		if [ "$$has_detail" -eq 1 ] && [ "$$is_error_prefix" -eq 1 ]; then \
			printf "\033[0;32m[PASS]\033[0m %s\n" "$$file"; \
			PASSED=$$((PASSED + 1)); \
		else \
			printf "\033[0;31m[FAIL]\033[0m %s\n" "$$file"; \
			[ "$$is_error_prefix" -eq 0 ] && echo "  (Missing 'Error' on first line)"; \
			printf "  Expected detail: %s\n" "$$expected"; \
			printf "  Got:\n%s\n" "$$output"; \
			FAILED=$$((FAILED + 1)); \
		fi; \
	done <<< "$$TEST_CASES"; \
	printf "\nResult: %d/%d passed.\n" "$$PASSED" "$$TOTAL"; \
	if [ $$FAILED -ne 0 ]; then exit 1; fi
