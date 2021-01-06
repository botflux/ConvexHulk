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

    points.emplace_back(400, 200);
    points.emplace_back(420, 280);
    points.emplace_back(430, 220);
    points.emplace_back(450, 300);
    points.emplace_back(455, 180);
    points.emplace_back(460, 260);
    points.emplace_back(462, 210);
    points.emplace_back(464, 240);
    points.emplace_back(500, 238);

    auto polygon = Polygon();

    convexHulk(polygon, points);

    auto firstVertex = polygon.getFirstVertex();
    auto secondVertex = firstVertex->getNextVertex();
    auto thirdVertex = secondVertex->getNextVertex();
    auto fourthVertex = thirdVertex->getNextVertex();

    ASSERT_EQ(firstVertex->getPoint(), points[0]);
    ASSERT_EQ(secondVertex->getPoint(), points[4]);
    ASSERT_EQ(thirdVertex->getPoint(), points[8]);
    ASSERT_EQ(fourthVertex->getPoint(), points[3]);
}

int main(int argc, char ** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}