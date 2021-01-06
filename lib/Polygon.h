//
// Created by Victor MENDELE on 05/01/2021.
//

#ifndef CONVEXHULK_POLYGON_H
#define CONVEXHULK_POLYGON_H

#include <iostream>
#include "Point.h"
#include "Vertex.h"

using namespace std;

class Polygon {
private:
    Vertex * firstVertex;
    std::vector<Vertex*> vertexReferences;

public:
    Polygon() : firstVertex(nullptr) {}
    bool hasPoints () {
        return firstVertex != nullptr;
    }
    Vertex * addVertex (Point point) {
        auto vertex = new Vertex(point);
        vertexReferences.push_back(vertex);

        if (! hasPoints()) {
            firstVertex = vertex;
        }

        return vertex;
    }
    Vertex * addVertex (Point point, Vertex * previousVertex) {
        auto vertex = addVertex(point);
        vertex->setPreviousVertex(previousVertex);
        previousVertex->setNextVertex(vertex);
        return vertex;
    }
    void deleteVertex (Vertex * vertexToDelete) {
        // Remove vertexToDelete of vertexReferences.
//        for (auto it = begin(vertexReferences); it != end(vertexReferences); ++it) {
//            if (vertexToDelete == (*it)) {
//                vertexReferences.erase(it);
//            }
//        }

        if (vertexToDelete->hasPreviousVertex()) {
            vertexToDelete->getPreviousVertex()->setNextVertex(vertexToDelete->getNextVertex());
        }

        if (vertexToDelete->hasNextVertex()) {
            vertexToDelete->getNextVertex()->setPreviousVertex(vertexToDelete->getPreviousVertex());
        }
    }
    ~Polygon() {
        for (auto vertexReference : vertexReferences) {
            delete vertexReference;
        }
    }

    Vertex * getFirstVertex() {
        return firstVertex;
    }
};

#endif //CONVEXHULK_POLYGON_H
