CFLAGS= -g -Wall -Wextra
all:
	cd build && make

setup:
	mkdir -p build
	cd build && cmake ../


clean:
	rm -rf build

format:
	find src/ -iname *.hpp -o -iname *.cpp | xargs clang-format -i