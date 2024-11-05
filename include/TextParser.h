//
// Created by sinat on 11/5/2024.
//

#ifndef SHAPEZOO_TEXTPARSER_H
#define SHAPEZOO_TEXTPARSER_H

#include <SFML/Graphics.hpp>
#include "BaseShape.h"
#include <memory>

class TextParser{
    std::string m_window_name;
    std::vector<std::unique_ptr<BaseShape>> m_shapes;
    std::string m_window_size_data;
    std::string m_window_color_data;
    std::string m_window_name_data;
    std::vector<std::string> m_shapes_data;
    static sf::Color ParseColor(std::string& color);
public:
    explicit TextParser(std::string& input_file_name);
    [[nodiscard]] int getWidth() const;
    [[nodiscard]] int getHeight() const;
    sf::Color getBgColor();
    std::string getWindowName();

};
#endif //SHAPEZOO_TEXTPARSER_H
