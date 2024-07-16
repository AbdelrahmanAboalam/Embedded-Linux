cc=gcc
Inc=include

all: build/a.out

bin/%.o: src/%.c
	@$(cc) -c -Wall $(Inc)/ -I$(Inc)/ $< -o $@

build/a.out: $(patsubst src/%.c,bin/%.o,$(wildcard src/*.c))
	@$(cc) $^ -o $@
	@echo "Compliation Done"

.PHONY:clean
clean:
	@rm bin/*.o build/a.out
	@echo "All Files Deleted"
