#include <SFML/Graphics.hpp>
#include <iostream>
#include "lib/Point.h"
#include "lib/Vertex.h"
#include "lib/Polygon.h"
#include "lib/sfmlHelpers.h"

using namespace std;

sf::RenderWindow * createWindow () {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    auto window = new sf::RenderWindow(sf::VideoMode(800, 600), "ConvexHulk", sf::Style::Default, settings);
    return window;
}

int main() {
    auto window = createWindow();
    window->setActive();

    auto polygon = Polygon();

    auto firstVertex = polygon.addVertex(Point(100, 100));
    auto secondVertex = polygon.addVertex(Point(150, 100), firstVertex);
    auto thirdVertex = polygon.addVertex(Point(100, 150), secondVertex);
    thirdVertex->setNextVertex(firstVertex);

    while (window->isOpen()) {
        sf::Event event;

        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window->close();
            }

            window->clear(sf::Color(100, 149, 239));

//            drawSegment(window, Point(200, 200), Point(600, 600));
            drawPolygon(window, polygon);

            window->display();
        }
    }

    delete window;

    return 0;
}
