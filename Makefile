CC              := cc
CFLAGS          := -Wall -Wextra -Werror
CPPFLAGS        := -Ilibft/include \
	               -Isrc -Isrc/bonus \
	               -Isrc/parsing -Isrc/parsing/operands -Isrc/parsing/options \
	               -Isrc/stack -Isrc/stats -Isrc/operations \
	               -Isrc/sorting/utils -Isrc/sorting/selection \
	               -Isrc/sorting/chunk -Isrc/sorting/turk
DEPFLAGS        := -MMD -MP

NAME            := push_swap
CHECKER         := checker
LIBFT_DIR       := libft
LIBFT           := $(LIBFT_DIR)/libft.a
BUILD_DIR       := build

RESET           := \033[0m
BOLD            := \033[1m
DIM             := \033[2m
CYAN            := \033[36m
GREEN           := \033[32m
YELLOW          := \033[33m
RED             := \033[31m
BLUE            := \033[34m

TAG_CC          := $(BOLD)$(CYAN)
TAG_MKDIR       := $(BOLD)$(BLUE)
TAG_CLEAN       := $(BOLD)$(YELLOW)
TAG_FCLEAN      := $(BOLD)$(RED)
TAG_LD          := $(BOLD)$(GREEN)

LIBFT_SOURCES   := \
	$(LIBFT_DIR)/src/character/ft_isalnum.c \
	$(LIBFT_DIR)/src/character/ft_isalpha.c \
	$(LIBFT_DIR)/src/character/ft_isascii.c \
	$(LIBFT_DIR)/src/character/ft_isdigit.c \
	$(LIBFT_DIR)/src/character/ft_isspace.c \
	$(LIBFT_DIR)/src/character/ft_isprint.c \
	$(LIBFT_DIR)/src/character/ft_tolower.c \
	$(LIBFT_DIR)/src/character/ft_toupper.c \
	$(LIBFT_DIR)/src/conversion/ft_atoi.c \
	$(LIBFT_DIR)/src/conversion/ft_itoa.c \
	$(LIBFT_DIR)/src/io/ft_putchar_fd.c \
	$(LIBFT_DIR)/src/io/ft_putendl_fd.c \
	$(LIBFT_DIR)/src/io/ft_putnbr_fd.c \
	$(LIBFT_DIR)/src/io/ft_putstr_fd.c \
	$(LIBFT_DIR)/src/list/ft_lstnew.c \
	$(LIBFT_DIR)/src/list/ft_lstadd_front.c \
	$(LIBFT_DIR)/src/list/ft_lstsize.c \
	$(LIBFT_DIR)/src/list/ft_lstlast.c \
	$(LIBFT_DIR)/src/list/ft_lstadd_back.c \
	$(LIBFT_DIR)/src/list/ft_lstdelone.c \
	$(LIBFT_DIR)/src/list/ft_lstclear.c \
	$(LIBFT_DIR)/src/list/ft_lstiter.c \
	$(LIBFT_DIR)/src/list/ft_lstmap.c \
	$(LIBFT_DIR)/src/memory/ft_bzero.c \
	$(LIBFT_DIR)/src/memory/ft_calloc.c \
	$(LIBFT_DIR)/src/memory/ft_memchr.c \
	$(LIBFT_DIR)/src/memory/ft_memcmp.c \
	$(LIBFT_DIR)/src/memory/ft_memcpy.c \
	$(LIBFT_DIR)/src/memory/ft_memmove.c \
	$(LIBFT_DIR)/src/memory/ft_memset.c \
	$(LIBFT_DIR)/src/string/ft_split.c \
	$(LIBFT_DIR)/src/string/ft_strchr.c \
	$(LIBFT_DIR)/src/string/ft_strdup.c \
	$(LIBFT_DIR)/src/string/ft_striteri.c \
	$(LIBFT_DIR)/src/string/ft_strjoin.c \
	$(LIBFT_DIR)/src/string/ft_strlcat.c \
	$(LIBFT_DIR)/src/string/ft_strlcpy.c \
	$(LIBFT_DIR)/src/string/ft_strlen.c \
	$(LIBFT_DIR)/src/string/ft_strmapi.c \
	$(LIBFT_DIR)/src/string/ft_strcmp.c \
	$(LIBFT_DIR)/src/string/ft_strncmp.c \
	$(LIBFT_DIR)/src/string/ft_strnstr.c \
	$(LIBFT_DIR)/src/string/ft_strrchr.c \
	$(LIBFT_DIR)/src/string/ft_strtrim.c \
	$(LIBFT_DIR)/src/string/ft_substr.c \
	$(LIBFT_DIR)/src/get_next_line/get_next_line.c \
	$(LIBFT_DIR)/src/get_next_line/get_next_line_state.c \
	$(LIBFT_DIR)/src/get_next_line/get_next_line_utils.c \
	$(LIBFT_DIR)/src/ft_printf/api/ft_printf.c \
	$(LIBFT_DIR)/src/ft_printf/api/ft_dprintf.c \
	$(LIBFT_DIR)/src/ft_printf/api/ft_vdprintf.c \
	$(LIBFT_DIR)/src/ft_printf/core/ft_process_format.c \
	$(LIBFT_DIR)/src/ft_printf/core/ft_process_directive.c \
	$(LIBFT_DIR)/src/ft_printf/core/ft_dispatch_conversion.c \
	$(LIBFT_DIR)/src/ft_printf/core/ft_emit_literal.c \
	$(LIBFT_DIR)/src/ft_printf/parsing/ft_parse_directive.c \
	$(LIBFT_DIR)/src/ft_printf/parsing/ft_parse_flags.c \
	$(LIBFT_DIR)/src/ft_printf/parsing/ft_parse_width.c \
	$(LIBFT_DIR)/src/ft_printf/parsing/ft_parse_precision.c \
	$(LIBFT_DIR)/src/ft_printf/parsing/ft_parse_specifier.c \
	$(LIBFT_DIR)/src/ft_printf/parsing/ft_parse_decimal.c \
	$(LIBFT_DIR)/src/ft_printf/conversions/ft_convert_char.c \
	$(LIBFT_DIR)/src/ft_printf/conversions/ft_convert_string.c \
	$(LIBFT_DIR)/src/ft_printf/conversions/ft_convert_signed.c \
	$(LIBFT_DIR)/src/ft_printf/conversions/ft_convert_unsigned.c \
	$(LIBFT_DIR)/src/ft_printf/conversions/ft_convert_hex.c \
	$(LIBFT_DIR)/src/ft_printf/conversions/ft_convert_octal.c \
	$(LIBFT_DIR)/src/ft_printf/conversions/ft_convert_binary.c \
	$(LIBFT_DIR)/src/ft_printf/conversions/ft_convert_pointer.c \
	$(LIBFT_DIR)/src/ft_printf/conversions/ft_convert_percent.c \
	$(LIBFT_DIR)/src/ft_printf/formatting/ft_emit_text_field.c \
	$(LIBFT_DIR)/src/ft_printf/formatting/ft_emit_integer_field.c \
	$(LIBFT_DIR)/src/ft_printf/output/ft_output_write.c \
	$(LIBFT_DIR)/src/ft_printf/output/ft_output_repeat.c \
	$(LIBFT_DIR)/src/ft_printf/output/ft_write_all.c \
	$(LIBFT_DIR)/src/ft_printf/utils/ft_utoa_base.c \
	$(LIBFT_DIR)/src/ft_printf/utils/ft_strnlen.c

LIBFT_HEADERS   := \
	$(LIBFT_DIR)/include/libft.h \
	$(LIBFT_DIR)/include/ft_printf.h \
	$(LIBFT_DIR)/include/get_next_line.h \
	$(LIBFT_DIR)/src/ft_printf/internal/ft_printf_internal.h \
	$(LIBFT_DIR)/src/get_next_line/get_next_line_internal.h

COMMON_SOURCES  := \
	src/parsing/operands/count_operand_tokens.c \
	src/parsing/operands/parse_integer_token.c \
	src/parsing/operands/parse_operand.c \
	src/parsing/operands/parse_operands.c \
	src/stack/stack_pop_top.c \
	src/stack/stack_push_top.c \
	src/stack/stack_reverse_rotate.c \
	src/stack/stack_rotate.c \
	src/stack/stack_swap_top.c \
	src/stack/initialize_stacks.c \
	src/stack/destroy_stacks.c \
	src/sorting/utils/stack_access.c \
	src/sorting/utils/stack_extreme_offsets.c \
	src/sorting/is_sorted.c

PUSH_SWAP_SOURCES := \
	src/main.c \
	src/orchestrator.c \
	src/orchestrator_dispatch.c \
	src/sorting/disorder_ratio.c \
	src/operations/operation_push.c \
	src/operations/operation_reverse_rotate.c \
	src/operations/operation_rotate.c \
	src/operations/operation_swap.c \
	src/parsing/options/apply_option.c \
	src/parsing/options/parse_long_option.c \
	src/parsing/parse_command_line.c \
	src/parsing/parse_result.c \
	src/parsing/options/parse_short_options.c \
	src/parsing/options/scan_arguments.c \
	src/sorting/selection/selection_sort.c \
	src/sorting/utils/small_sort.c \
	src/sorting/utils/stack_rotation.c \
	src/sorting/utils/stack_insertion_target.c \
	src/sorting/chunk/chunk_sort.c \
	src/sorting/chunk/chunk_group_width.c \
	src/sorting/utils/stack_rank_values.c \
	src/sorting/chunk/chunk_transfer_to_b.c \
	src/sorting/chunk/chunk_restore_to_a.c \
	src/sorting/turk/turk_find_cheapest_move.c \
	src/sorting/turk/turk_rotate_move.c \
	src/sorting/turk/turk_execute_move.c \
	src/sorting/turk/turk_sort.c \
	src/stats/stats.c \
	src/stats/print_benchmark.c

CHECKER_SOURCES := \
	src/bonus/main_bonus.c \
	src/bonus/checker_dispatch_bonus.c \
	src/bonus/checker_loop_bonus.c \
	src/bonus/checker_execute_push_bonus.c \
	src/bonus/checker_execute_reverse_rotate_bonus.c \
	src/bonus/checker_execute_rotate_bonus.c \
	src/bonus/checker_execute_swap_bonus.c

COMMON_OBJECTS    := $(patsubst src/%.c,$(BUILD_DIR)/%.o,$(COMMON_SOURCES))
PUSH_SWAP_OBJECTS := $(patsubst src/%.c,$(BUILD_DIR)/%.o,$(PUSH_SWAP_SOURCES))
CHECKER_OBJECTS   := $(patsubst src/%.c,$(BUILD_DIR)/%.o,$(CHECKER_SOURCES))

ALL_OBJECTS       := $(sort $(COMMON_OBJECTS) $(PUSH_SWAP_OBJECTS) \
	$(CHECKER_OBJECTS))

OBJ_DIRS          := $(sort $(dir $(ALL_OBJECTS)))
DEPS              := $(ALL_OBJECTS:.o=.d)

.DEFAULT_GOAL := all
.DELETE_ON_ERROR:

all: $(NAME)

bonus: $(CHECKER)

$(LIBFT): $(LIBFT_SOURCES) $(LIBFT_HEADERS) $(LIBFT_DIR)/Makefile
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)

$(NAME): $(COMMON_OBJECTS) $(PUSH_SWAP_OBJECTS) $(LIBFT) Makefile
	@printf "$(TAG_LD)[LD]$(RESET) Linking $(DIM)%s$(RESET)\n" "$@"
	@$(CC) $(CFLAGS) $(LDFLAGS) $(COMMON_OBJECTS) $(PUSH_SWAP_OBJECTS) \
		$(LIBFT) $(LDLIBS) -o $@

$(CHECKER): $(COMMON_OBJECTS) $(CHECKER_OBJECTS) $(LIBFT) Makefile
	@printf "$(TAG_LD)[LD]$(RESET) Linking $(DIM)%s$(RESET)\n" "$@"
	@$(CC) $(CFLAGS) $(LDFLAGS) $(COMMON_OBJECTS) $(CHECKER_OBJECTS) \
		$(LIBFT) $(LDLIBS) -o $@

$(OBJ_DIRS):
	@mkdir -p $@
	@printf "$(TAG_MKDIR)[MKDIR]$(RESET) Creating $(DIM)%s$(RESET)\n" "$@"

$(BUILD_DIR)/%.o: src/%.c | $(OBJ_DIRS)
	@printf "$(TAG_CC)[CC]$(RESET) Compiling $(DIM)%s$(RESET)\n" "$<"
	@$(CC) $(CPPFLAGS) $(CFLAGS) $(DEPFLAGS) \
		-MF $(@:.o=.d) -MT $@ -c $< -o $@

clean:
	@rm -rf $(BUILD_DIR)
	@printf "$(TAG_CLEAN)[CLEAN]$(RESET) Removing build directory\n"
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean

fclean:
	@rm -rf $(BUILD_DIR)
	@printf "$(TAG_CLEAN)[CLEAN]$(RESET) Removing build directory\n"
	@rm -f $(NAME) $(CHECKER)
	@printf "$(TAG_FCLEAN)[FCLEAN]$(RESET) Removing $(DIM)%s$(RESET)\n" \
		"$(NAME) and $(CHECKER)"
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean

re: fclean
	@$(MAKE) --no-print-directory all

-include $(DEPS)

.PHONY: all bonus clean fclean re