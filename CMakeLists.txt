cmake_minimum_required(VERSION 3.17)
project(ConvexHulk)

set(CMAKE_CXX_STANDARD 20)


find_package(SFML 2.5.1 COMPONENTS graphics system window REQUIRED)

add_subdirectory(lib)
add_subdirectory(tests)

add_executable(ConvexHulk main.cpp lib/Point.h lib/Vertex.h lib/Polygon.h lib/sfmlHelpers.h)
target_link_libraries(ConvexHulk sfml-graphics)

# GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(executePointTests tests/PointTests.cpp lib/Point.h lib/Vertex.h lib/Polygon.h)
target_link_libraries(executePointTests ${GTEST_LIBRARIES} pthread)

add_executable(executeVertexTests tests/VertexTests.cpp lib/Point.h lib/Vertex.h lib/Polygon.h)
target_link_libraries(executeVertexTests ${GTEST_LIBRARIES} pthread)

add_executable(executePolygonTests tests/PolygonTests.cpp lib/Point.h lib/Vertex.h lib/Polygon.h)
target_link_libraries(executePolygonTests ${GTEST_LIBRARIES} pthread)