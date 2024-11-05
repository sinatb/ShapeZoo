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

void Triangle::Draw(sf::RenderWindow &window) {
    window.draw(m_shape);
    m_rendered_text.setPosition(m_position.x + m_radius - static_cast<float>((m_text.size() / 2.0) * 15),
                                m_position.y + m_radius - 10);
    window.draw(m_rendered_text);
}


void Triangle::OnCollision(sf::RenderWindow &window) {
    if (m_position.x < 0 || m_position.x+1.73*m_radius > window.getSize().x)
        m_speed.x = -m_speed.x;
    if (m_position.y < 0 || m_position.y+1.5*m_radius > window.getSize().y)
        m_speed.y = -m_speed.y;
}
