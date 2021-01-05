//
// Created by Victor MENDELE on 05/01/2021.
//
#include <gtest/gtest.h>
#include "../lib/Point.h"
#include "../lib/Vertex.h"


TEST(VertexTests, CreateVertex) {
    auto vertex = Vertex(Point(0, 10));

    ASSERT_EQ(vertex.getPoint().x, 0);
    ASSERT_EQ(vertex.getPoint().y, 10);
}

TEST(VertexTests, CreateVertexGivesEmptyPreviousAndNext) {
    auto vertex = Vertex(Point(0, 10));

    ASSERT_FALSE(vertex.hasNextVertex());
    ASSERT_FALSE(vertex.hasPreviousVertex());
}

TEST(VertexTests, SetNextAndPreviousVertex) {
    auto vertex1 = Vertex(Point(2, 4));
    auto vertex2 = Vertex(Point(7, 19));
    auto vertex3 = Vertex(Point(6, 0), & vertex1, & vertex2);

    ASSERT_TRUE(vertex3.hasPreviousVertex());
    ASSERT_TRUE(vertex3.hasNextVertex());

    ASSERT_EQ(vertex3.getNextVertex(), & vertex2);
    ASSERT_EQ(vertex3.getPreviousVertex(), & vertex1);
}

int main(int argc, char ** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
