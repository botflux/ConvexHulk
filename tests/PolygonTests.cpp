//
// Created by Victor MENDELE on 05/01/2021.
//

#include <gtest/gtest.h>
#include "../lib/Polygon.h"

TEST(PolygonTests, AddVertices) {
    auto polygon = Polygon();

    auto vertex1 = polygon.addVertex(Point(3, 4));
    auto vertex2 = polygon.addVertex(Point(32, 59), vertex1);

    ASSERT_EQ(vertex1, vertex2->getPreviousVertex());
    ASSERT_FALSE(vertex1->hasPreviousVertex());
    ASSERT_FALSE(vertex2->hasNextVertex());
}

TEST(PolygonTests, RemoveVertices) {
    auto polygon = Polygon();
    auto vertex1 = polygon.addVertex(Point(3, 4));
    auto vertex2 = polygon.addVertex(Point(32, 59), vertex1);
    auto vertex3 = polygon.addVertex(Point(19, 22), vertex2);

    polygon.deleteVertex(vertex2);

    ASSERT_FALSE(vertex3->hasNextVertex());
    ASSERT_FALSE(vertex1->hasPreviousVertex());
    ASSERT_EQ(vertex1->getNextVertex(), vertex3);
    ASSERT_EQ(vertex2->getPreviousVertex(), vertex1);
}

int main(int argc, char ** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}