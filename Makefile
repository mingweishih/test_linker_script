.PHONY: all clean

all: test

test: main.o libdylib.so
	clang-8 -o $@ $^ -Wl,-rpath=$(shell pwd)

main.o: main.c
	clang-8 -c main.c

libdylib.so: dylib.c dylib.lds
	clang-8 -shared -o $@ -fPIC $< -Wl,-T dylib.lds

run: test
	./test

clean:
	rm -f test main.o libdylib.so
