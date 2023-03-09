CC = clang
CFLAGS = -g3 -Og -std=c11 -Wall -fno-omit-frame-pointer

all: me

me: me.c
	$(CC)  $(CFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm -f me
	echo "Removed me binary type make to recompile"
