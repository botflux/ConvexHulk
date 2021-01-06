//
// Created by Victor MENDELE on 05/01/2021.
//

#ifndef CONVEXHULK_POINT_H
#define CONVEXHULK_POINT_H

struct Point {
public:
    int x;
    int y;

    Point (int x, int y): x (x), y (y) {}
    Point (): x (0), y(0) {}

    /**
     *
     * @param a The first point of the segment
     * @param b The second point of the segment
     * @return Positive number if the current point is at the left, negative if at the right otherwise 0.
     */
    int atLeftOfSegment (Point a, Point b) {
        return (b.x - a.x) * (y - a.y) - (x - a.x) * (b.y - a.y);
    }

    static bool equals (Point lhs, Point rhs) {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }
};

bool operator==(const Point & a, const Point & b) {
    return Point::equals(a, b);
}

bool operator != (const Point & a, const Point & b) {
    return ! (a == b);
}

#endif //CONVEXHULK_POINT_H
