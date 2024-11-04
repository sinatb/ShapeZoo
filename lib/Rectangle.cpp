//
// Created by sinat on 11/3/2024.
//
#include "../include/Rectangle.h"

Rectangle::Rectangle(std::string &text,
                     sf::Vector2f position,
                     sf::Vector2f speed,
                     sf::Color color,
                     float width,
                     float height) :
    BaseShape(text, position, speed, color, m_rectangle),
    m_width(width),
    m_height(height)
{
    m_rectangle = sf::RectangleShape(sf::Vector2f(m_width, m_height));
    m_shape.setPosition(m_position);
    m_rectangle.setFillColor(m_color);
}

void Rectangle::Draw(sf::RenderWindow &window) {
    window.draw(m_rectangle);
    m_rendered_text.setPosition(m_position.x + m_width/2 - static_cast<float>((m_text.size() / 2.0) * 15),
                                m_position.y + m_height/2 - 10);
    window.draw(m_rendered_text);
}

void Rectangle::OnCollision(sf::RenderWindow &window) {
    if (m_position.x < 0 || m_position.x + m_width > window.getSize().x)
        m_speed.x = -m_speed.x;
    if (m_position.y < 0 || m_position.y + m_height > window.getSize().y)
        m_speed.y = -m_speed.y;
}