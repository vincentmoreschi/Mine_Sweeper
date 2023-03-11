all:
	mkdir -p build
	cd build && cmake ../ && make

clean:
	rm -rf build

format:
	find src/ -iname *.hpp -o -iname *.cpp | xargs clang-format -i