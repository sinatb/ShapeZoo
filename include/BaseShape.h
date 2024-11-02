//
// Created by sinat on 11/2/2024.
//

#ifndef SHAPEZOO_BASESHAPE_H
#define SHAPEZOO_BASESHAPE_H

#include <string>
#include <SFML/Graphics.hpp>
class BaseShape {
    std::string m_text;
    sf::Vector2f m_position;
    sf::Vector2f m_speed;
    void Move(){
        m_position += m_speed;
    }
public:
    virtual void OnCollision() = 0;
    virtual void Draw(sf::RenderWindow &window) = 0;
    void Update(sf::RenderWindow &window) {
        OnCollision();
        Move();
        Draw(window);
    }
    ~BaseShape() = default;
};
#endif //SHAPEZOO_BASESHAPE_H
