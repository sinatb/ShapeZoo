//
// Created by sinat on 11/3/2024.
//
#include "../include/Triangle.h"

Triangle::Triangle(std::string &text,
                   sf::Vector2f position,
                   sf::Vector2f speed,
                   sf::Color color,
                   float radius) :
        BaseShape(text, position, speed, color, m_triangle),
        m_radius(radius)
{
    m_triangle = sf::CircleShape(m_radius,3);
    m_shape.setPosition(m_position);
    m_triangle.setFillColor(m_color);
}

void Triangle::OnCollision(sf::RenderWindow &window) {

}

void Triangle::Draw(sf::RenderWindow &window) {
    window.draw(m_shape);
}