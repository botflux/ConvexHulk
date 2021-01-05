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

    static bool equals (Point lhs, Point rhs) {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }
};

#endif //CONVEXHULK_POINT_H
