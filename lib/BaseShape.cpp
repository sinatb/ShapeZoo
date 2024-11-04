//
// Created by sinat on 11/3/2024.
//
#include "../include/BaseShape.h"

BaseShape::BaseShape(std::string &text,
                     sf::Vector2f &position,
                     sf::Vector2f &speed,
                     sf::Color &color,
                     sf::Shape &shape) :
    m_text(text),
    m_position(position),
    m_speed(speed),
    m_color(color),
    m_shape(shape),
    m_direction(getRandomDirection())
{
    loadFont();
    m_rendered_text.setFont(m_font);
    m_rendered_text.setString(m_text);
    m_rendered_text.setCharacterSize(20);
    m_rendered_text.setFillColor(sf::Color::White);
}

void BaseShape::Update(sf::RenderWindow &window)
{
    OnCollision(window);
    Move();
    Draw(window);
}

void BaseShape::Move() {
    sf::Vector2f effective_movement_vector(m_direction.x * m_speed.x, m_direction.y * m_speed.y);
    m_position += effective_movement_vector;
    m_shape.setPosition(m_position);
}

sf::Vector2f BaseShape::getRandomDirection() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(0.0,1.0);

    float rand_x =  dist(gen);
    float rand_y = dist(gen);
    float div = std::sqrt(rand_x*rand_x + rand_y*rand_y);
    return {rand_x/div, rand_y/div};
}


bool BaseShape::loadFont() {
    if (!m_font.loadFromFile(R"(D:\works\gameDev\COMP4300\ShapeZoo\fonts\Minecrafter.Alt.ttf)")){
        std::cout << "ERROR: Failed to load font" << std::endl;
        exit(-1);
    }
    return true;
}