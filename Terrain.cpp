#include <iostream>
#include "Terrain.h"


unsigned int WIDTH = 800;
unsigned int HEIGHT = 600;
size_t POINT_COUNT = 4;
float POINT_COEFF = float(WIDTH) / float(POINT_COUNT);

Terrain::Terrain(size_t number_of_points, float *points) {
    terrain.setPointCount(number_of_points + 2);
    terrain.setFillColor(sf::Color(35, 147, 67));
    terrain.setOutlineColor(sf::Color::Black);
    terrain.setOutlineThickness(-1);

    setPoints(points);
}

void Terrain::setPoints(float *points) {
    for (size_t i=0; i<terrain.getPointCount()-2; i++) {
        terrain.setPoint(i, sf::Vector2f(i*POINT_COEFF, HEIGHT-points[i]));
    }

    terrain.setPoint(terrain.getPointCount()-2, sf::Vector2f(WIDTH, HEIGHT));
    terrain.setPoint(terrain.getPointCount()-1, sf::Vector2f(0, HEIGHT));
//    for (size_t i=0; i<terrain.getPointCount(); i++)
//        std::cout << terrain.getPoint(i).x <<", " << terrain.getPoint(i).y << std::endl;
}

void Terrain::draw(sf::RenderWindow& window) {
    window.draw(terrain);
}