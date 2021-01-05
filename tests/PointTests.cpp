#include <gtest/gtest.h>
#include "../lib/Point.h"

TEST(PointTest, CreatePoint) {
    auto point = Point(4, 10);
    ASSERT_EQ(point.x, 4);
    ASSERT_EQ(point.y, 10);
}

TEST(PointTest, CreateEmptyPoint) {
    auto point = Point();
    ASSERT_EQ(point.x, 0);
    ASSERT_EQ(point.y, 0);
}

TEST(PointTest, PointsEquality) {
    auto point1 = Point(8, 2);
    auto point2 = Point(8, 2);

    bool areEqual = Point::equals(point1, point2);

    ASSERT_EQ(areEqual, true);
}

int main(int argc, char ** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}