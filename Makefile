# Builds every .c file in this folder (e.g. vector.c + test.c) into one test program.
#
#   make           build build/test_runner
#   make test      build and run the tests
#   make asan      build and run with AddressSanitizer + UBSan
#   make valgrind  run the tests under Valgrind (Linux)
#   make clean     delete everything in build/

CC       := gcc
CFLAGS   := -std=c11 -Wall -Wextra -Wpedantic -Werror -Wstrict-prototypes -g
DEPFLAGS := -MMD -MP
SANFLAGS := -fsanitize=address,undefined -fno-omit-frame-pointer

SRCS      := $(wildcard *.c)
OBJS      := $(SRCS:%.c=build/%.o)
ASAN_OBJS := $(SRCS:%.c=build/asan/%.o)

BIN      := build/test_runner
ASAN_BIN := build/asan/test_runner

.PHONY: all test asan valgrind clean

all: $(BIN)

# Normal build
$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

build/%.o: %.c | build
	$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

test: $(BIN)
	./$(BIN)

# Sanitizer build (kept in its own folder so objects never mix)
$(ASAN_BIN): $(ASAN_OBJS)
	$(CC) $(CFLAGS) $(SANFLAGS) $^ -o $@

build/asan/%.o: %.c | build/asan
	$(CC) $(CFLAGS) $(SANFLAGS) $(DEPFLAGS) -c $< -o $@

asan: $(ASAN_BIN)
	./$(ASAN_BIN)

valgrind: $(BIN)
	valgrind --leak-check=full --show-leak-kinds=all --error-exitcode=1 ./$(BIN)

build build/asan:
	mkdir -p $@

clean:
	rm -rf build

# Rebuild a .c file automatically when a header it includes changes
-include $(OBJS:.o=.d) $(ASAN_OBJS:.o=.d)
