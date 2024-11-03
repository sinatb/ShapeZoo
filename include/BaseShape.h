//
// Created by sinat on 11/2/2024.
//

#ifndef SHAPEZOO_BASESHAPE_H
#define SHAPEZOO_BASESHAPE_H

#include <cmath>
#include <string>
#include <SFML/Graphics.hpp>
#include <random>
class BaseShape {

void Move(){
    sf::Vector2f effective_movement_vector(m_direction.x * m_speed.x, m_direction.y * m_speed.y);
    m_position += effective_movement_vector;
    m_shape.setPosition(m_position);
}

static sf::Vector2f getRandomDirection() {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(0.0,1.0);

    float rand_x =  dist(gen);
    float rand_y = dist(gen);
    float div = std::sqrt(rand_x*rand_x + rand_y*rand_y);
    return {rand_x/div, rand_y/div};

}

protected:
    std::string  m_text;
    sf::Vector2f m_position;
    sf::Vector2f m_speed;
    sf::Color    m_color;
    sf::Vector2f m_direction;
    sf::Shape&   m_shape;

public:
    BaseShape(std::string& text, sf::Vector2f& position, sf::Vector2f& speed, sf::Color& color, sf::Shape& shape):
        m_text(text),
        m_position(position),
        m_speed(speed),
        m_color(color),
        m_shape(shape),
        m_direction(getRandomDirection())
    {}
    virtual void OnCollision(sf::RenderWindow &window) = 0;
    virtual void Draw(sf::RenderWindow &window) = 0;
    void Update(sf::RenderWindow &window) {
        OnCollision(window);
        Move();
        Draw(window);
    }
    ~BaseShape() = default;
};
#endif //SHAPEZOO_BASESHAPE_H
