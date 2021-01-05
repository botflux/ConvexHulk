//
// Created by Victor MENDELE on 05/01/2021.
//

#ifndef CONVEXHULK_VERTEX_H
#define CONVEXHULK_VERTEX_H

#include "Point.h"

class Vertex {
private:
    Point point;
    Vertex * previousVertex;
    Vertex * nextVertex;

public:
    Vertex (Point point)
        : point(point), previousVertex(nullptr), nextVertex(nullptr) {}
    Vertex (Point point, Vertex * previous, Vertex * next)
        : point(point), previousVertex(previous), nextVertex(next) {}

    Vertex * getPreviousVertex () {
        return previousVertex;
    }
    Vertex * getNextVertex () {
        return nextVertex;
    }
    void setNextVertex (Vertex * vertex) {
        nextVertex = vertex;
    }
    void setPreviousVertex (Vertex * vertex) {
        previousVertex = vertex;
    }
    bool hasNextVertex () {
        return nextVertex != nullptr;
    }
    bool hasPreviousVertex () {
        return previousVertex != nullptr;
    }
    Point getPoint () {
        return point;
    }
};

#endif //CONVEXHULK_VERTEX_H
