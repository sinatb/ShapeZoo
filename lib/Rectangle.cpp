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
}

void Rectangle::OnCollision(sf::RenderWindow &window) {

}