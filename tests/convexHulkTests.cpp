//
// Created by Victor MENDELE on 06/01/2021.
//

#include <gtest/gtest.h>
#include "../lib/Polygon.h"
#include "../lib/Point.h"
#include "../lib/convexHulk.h"
#include <iostream>

using namespace std;

TEST(convexHulkTests, DoesNotPopulatePolygonWhenPointsHasLessThanThreeItems) {
    auto points = vector<Point> ();

    points.emplace_back(0, 4);
    points.emplace_back(5, 9);

    auto polygon = Polygon();

    convexHulk(polygon, points);

    ASSERT_FALSE(polygon.hasPoints());
}

TEST(convexHulkTests, PopulatePolygonWhenPointsHasAtLeastThreePoints) {
    auto points = vector<Point> ();

    points.emplace_back(5, 6);
    points.emplace_back(7, 9);
    points.emplace_back(9, 4);

    auto polygon = Polygon();

    convexHulk(polygon, points);

    auto hasPoints = polygon.hasPoints();
    auto firstVertex = polygon.getFirstVertex();
    auto secondVertex = firstVertex->getNextVertex();
    auto thirdVertex = secondVertex->getNextVertex();

    ASSERT_TRUE(hasPoints);
    ASSERT_EQ(firstVertex->getPoint(), points[0]);
    ASSERT_EQ(secondVertex->getPoint(), points[1]);
    ASSERT_EQ(thirdVertex->getPoint(), points[2]);
}

TEST(convexHulkTests, PointsAreOrderedByAbscissa) {

    auto points = vector<Point> ();

    points.emplace_back(9, 4);
    points.emplace_back(7, 9);
    points.emplace_back(5, 6);

    auto polygon = Polygon();

    convexHulk(polygon, points);

    auto hasPoints = polygon.hasPoints();
    auto firstVertex = polygon.getFirstVertex();
    auto secondVertex = firstVertex->getNextVertex();
    auto thirdVertex = secondVertex->getNextVertex();

    ASSERT_TRUE(hasPoints);
    ASSERT_EQ(firstVertex->getPoint(), points[2]);
    ASSERT_EQ(secondVertex->getPoint(), points[1]);
    ASSERT_EQ(thirdVertex->getPoint(), points[0]);
}

TEST(convexHulkTests, PopulatePolygonWithTheRightConvexHulk) {
    auto points = vector<Point> ();

    points.emplace_back(200, 200);
    points.emplace_back(300, 200);
    points.emplace_back(330, 300);
    points.emplace_back(500, 500);
    points.emplace_back(550, 100);
    points.emplace_back(560, 150);

    auto polygon = Polygon();

    convexHulk(polygon, points);

    auto firstVertex = polygon.getFirstVertex();
    auto secondVertex = firstVertex->getNextVertex();
    auto thirdVertex = secondVertex->getNextVertex();
    auto fourthVertex = thirdVertex->getNextVertex();

    ASSERT_EQ(firstVertex->getPoint(), points[0]);
    ASSERT_EQ(secondVertex->getPoint(), points[4]);
    ASSERT_EQ(thirdVertex->getPoint(), points[5]);
    ASSERT_EQ(fourthVertex->getPoint(), points[3]);
}

int main(int argc, char ** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}