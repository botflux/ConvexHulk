#include <SFML/Graphics.hpp>
#include <iostream>
#include "lib/Point.h"
#include "lib/Vertex.h"
#include "lib/Polygon.h"
#include "lib/sfmlHelpers.h"
#include "lib/convexHulk.h"

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

    while (window->isOpen()) {
        sf::Event event;

        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window->close();
            }

            window->clear(sf::Color(100, 149, 239));

//            drawSegment(window, Point(200, 200), Point(600, 600));
            drawPolygon(window, polygon);
            drawPoints(window, points);

            window->display();
        }
    }

    delete window;

    return 0;
}
