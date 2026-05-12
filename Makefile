.PHONY: build

build:
	mkdir -p build && cd build && cmake .. && make

run:
	./build/alice_bot
