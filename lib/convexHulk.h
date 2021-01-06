//
// Created by Victor MENDELE on 06/01/2021.
//

#ifndef CONVEXHULK_CONVEXHULK_H
#define CONVEXHULK_CONVEXHULK_H

#include "Polygon.h"
#include <iostream>
#include "Vertex.h"
#include "Point.h"

using namespace std;

void sortPointsByAbscissa (vector<Point> & points) {
    sort(points.begin(), points.end(), [] (const Point & lhs, const Point & rhs) {
        return lhs.x < rhs.x;
    });
}

void findLinesAtLeftOfPoint (vector<tuple<Vertex *, Vertex *>> & lines, Point point, Polygon & polygon) {

    auto currentVertex = polygon.getFirstVertex();

    do {
        auto nextVertex = currentVertex->getNextVertex();

        if (point.atLeftOfSegment(currentVertex->getPoint(), nextVertex->getPoint()) < 0) {
            lines.emplace_back(currentVertex, nextVertex);
        }

        currentVertex = nextVertex;
    } while (currentVertex != polygon.getFirstVertex());
}

void convexHulk (Polygon & polygon, vector<Point> & points) {
    if (points.size() < 3) {
        return;
    }

    auto sortedPoints = points;
    sortPointsByAbscissa(sortedPoints);

    auto firstVertex = polygon.addVertex(sortedPoints[0]);
    auto secondVertex = polygon.addVertex(sortedPoints[1], firstVertex);
    auto thirdVertex = polygon.addVertex(sortedPoints[2], secondVertex);
    thirdVertex->setNextVertex(firstVertex);
    firstVertex->setPreviousVertex(thirdVertex);

    auto pointsWithoutTheFirstThree = vector<Point> (sortedPoints.begin() + 3, sortedPoints.end());

    for (auto point : pointsWithoutTheFirstThree) {
        vector<tuple<Vertex *, Vertex *>> linesAtLeftOfPoint;
        findLinesAtLeftOfPoint(linesAtLeftOfPoint, point, polygon);

        auto firstVertexOfLines = get<0>(linesAtLeftOfPoint[0]);
        auto lastVertexOfLines = get<1>(linesAtLeftOfPoint[linesAtLeftOfPoint.size() - 1]);

        for (auto line : linesAtLeftOfPoint) {

            auto a = get<0>(line);
            auto b = get<1>(line);

            if (a->getPoint() != firstVertexOfLines->getPoint()) {
                polygon.deleteVertex(a);
            }

            if (b->getPoint() != lastVertexOfLines->getPoint()) {
                polygon.deleteVertex(b);
            }

            polygon
                .addVertex(point, firstVertexOfLines)
                ->setNextVertex(lastVertexOfLines);
        }
    }
}

#endif //CONVEXHULK_CONVEXHULK_H
