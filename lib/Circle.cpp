//
// Created by sinat on 11/3/2024.
//
#include "../include/Circle.h"

Circle::Circle(std::string& text,
               sf::Vector2f position,
               sf::Vector2f speed,
               sf::Color color,
               float radius) :
    BaseShape(text, position, speed, color, m_circle),
    m_radius(radius)
{
    m_circle = sf::CircleShape(m_radius);
    m_shape.setPosition(m_position);
    m_circle.setFillColor(m_color);
}

void Circle::Draw(sf::RenderWindow &window) {
    window.draw(m_shape);
}

void Circle::OnCollision(sf::RenderWindow &window) {
    if (m_position.x-m_radius <= 0 || m_position.x+m_radius >= window.getSize().x)
        m_speed.x = -m_speed.x;
    if (m_position.y-m_radius <= 0 || m_position.y+m_radius >= window.getSize().y)
        m_speed.y = -m_speed.y;
}