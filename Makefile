build:
	rm -f ./build
	cmake -S . -B ./build
	(cd ./build && make)

run: build
	./build/ConvexHulk $(ARGS)

test: build
	./build/executeConvexHulkTests
	./build/executePointTests
	./build/executePolygonTests
	./build/executeVertexTests