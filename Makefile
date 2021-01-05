build:
	rm -f ./build
	cmake -S . -B ./build
	(cd ./build && make)

run: build
	./build/ConvexHulk $(ARGS)