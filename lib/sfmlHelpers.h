//
// Created by Victor MENDELE on 05/01/2021.
//

#ifndef CONVEXHULK_SFMLHELPERS_H
#define CONVEXHULK_SFMLHELPERS_H

#include <SFML/Graphics.hpp>
#include "Point.h"

void drawSegment (sf::RenderWindow * window, Point a, Point b) {
    sf::Vertex line [] = {
        sf::Vertex(sf::Vector2f(a.x, a.y), sf::Color::Red),
        sf::Vertex(sf::Vector2f(b.x, b.y), sf::Color::Red)
    };

    window->draw(&line[0], 2, sf::Lines);
}

void drawPolygon (sf::RenderWindow * window, Polygon & polygon) {
    if (polygon.hasPoints()) {
        return;
    }

    auto currentVertex = polygon.getFirstVertex();

    do {
        auto nextVertex = currentVertex->getNextVertex();
        drawSegment(window, currentVertex->getPoint(), nextVertex->getPoint());
        currentVertex = nextVertex;
    } while (currentVertex != polygon.getFirstVertex());
}

#endif //CONVEXHULK_SFMLHELPERS_H
