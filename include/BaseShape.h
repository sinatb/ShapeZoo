//
// Created by sinat on 11/2/2024.
//

#ifndef SHAPEZOO_BASESHAPE_H
#define SHAPEZOO_BASESHAPE_H

#include <cmath>
#include <string>
#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>

class BaseShape {

void Move();

static sf::Vector2f getRandomDirection();

bool loadFont();

protected:
    std::string  m_text;
    sf::Vector2f m_position;
    sf::Vector2f m_speed;
    sf::Color    m_color;
    sf::Font     m_font;
    sf::Text     m_rendered_text;
    sf::Vector2f m_direction;
    sf::Shape&   m_shape;

public:
    BaseShape(std::string& text, sf::Vector2f& position, sf::Vector2f& speed, sf::Color& color, sf::Shape& shape);
    virtual void OnCollision(sf::RenderWindow &window) = 0;
    virtual void Draw(sf::RenderWindow &window) = 0;
    void Update(sf::RenderWindow &window);
    virtual ~BaseShape() = default;
};
#endif //SHAPEZOO_BASESHAPE_H
