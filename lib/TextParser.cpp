//
// Created by sinat on 11/5/2024.
//
#include <fstream>
#include <sstream>
#include "../include/TextParser.h"

TextParser::TextParser(std::string &input_file_name) {

    //Opening the test files
    std::string path = R"(D:\works\gameDev\COMP4300\ShapeZoo\test-files\)" + input_file_name;
    std::ifstream input_file(path);
    if (!input_file.is_open())
    {
        std::cout << "Failed to open file" << std::endl;
        exit(1);
    }

    //Reading file values
    std::string line;
    int line_number = 0;
    while (std::getline(input_file, line)){
        switch (line_number) {
            case 0:
                m_window_size_data = line;
                break;
            case 1:
                m_window_color_data = line;
                break;
            case 2:
                m_window_name_data = line;
                break;
            default:
                m_shapes_data.push_back(line);
                break;
        }
        line_number ++;
    }
    input_file.close();
}

int TextParser::getHeight() const {
    std::istringstream iss(m_window_size_data);
    std::string height;
    iss >> height;
    iss >> height;
    return std::stoi(height);
}

int TextParser::getWidth() const {
    std::istringstream iss(m_window_size_data);
    std::string width;
    iss >> width;
    return std::stoi(width);
}

sf::Color TextParser::getBgColor() {
    return ParseColor(m_window_color_data);
}

sf::Color TextParser::ParseColor(std::string &color)
{
    if (color == "RED") {
        return sf::Color::Red;
    } else if (color == "GREEN") {
        return sf::Color::Green;
    } else if (color == "BLUE") {
        return sf::Color::Blue;
    }
    return sf::Color::Black;
}

std::string TextParser::getWindowName() {
    return m_window_name_data;
}

std::vector<std::unique_ptr<BaseShape>> TextParser::getShapes() {
    std::vector<std::unique_ptr<BaseShape>> shapes;
    for (auto s: m_shapes_data)
    {
        std::istringstream iss(s);
        std::string shape_type;
        iss >> shape_type;
        if (shape_type == "triangle"){
            shapes.push_back(ParseTriangle(s));
        }else if (shape_type == "rectangle"){
            shapes.push_back(ParseRectangle(s));
        }else if (shape_type == "circle"){
            shapes.push_back(ParseCircle(s));
        }
    }
    return shapes;
}

std::unique_ptr<Triangle> TextParser::ParseTriangle(std::string &data) {
    std::istringstream iss(data);
    std::string shape_type;
    iss >> shape_type;

    //name parsing
    std::string text;
    iss >> text;

    //position parsing
    sf::Vector2f pos;
    std::string pos_x, pos_y;
    iss >> pos_x;
    iss >> pos_y;
    pos.x = std::stof(pos_x);
    pos.y = std::stof(pos_y);

    //speed parsing
    sf::Vector2f spd;
    std::string spd_x, spd_y;
    iss >> spd_x;
    iss >> spd_y;
    spd.x = std::stof(spd_x);
    spd.y = std::stof(spd_y);

    //color parsing
    sf::Color color;
    std::string color_s;
    iss >> color_s;
    color = ParseColor(color_s);

    //size parsing
    float radius;
    std::string radius_s;
    iss >> radius_s;
    radius = std::stof(radius_s);

    return std::make_unique<Triangle>(text, pos, spd, color, radius);
}

std::unique_ptr<Circle> TextParser::ParseCircle(std::string &data) {
    std::istringstream iss(data);
    std::string shape_type;
    iss >> shape_type;

    //name parsing
    std::string text;
    iss >> text;

    //position parsing
    sf::Vector2f pos;
    std::string pos_x, pos_y;
    iss >> pos_x;
    iss >> pos_y;
    pos.x = std::stof(pos_x);
    pos.y = std::stof(pos_y);

    //speed parsing
    sf::Vector2f spd;
    std::string spd_x, spd_y;
    iss >> spd_x;
    iss >> spd_y;
    spd.x = std::stof(spd_x);
    spd.y = std::stof(spd_y);

    //color parsing
    sf::Color color;
    std::string color_s;
    iss >> color_s;
    color = ParseColor(color_s);

    //size parsing
    float radius;
    std::string radius_s;
    iss >> radius_s;
    radius = std::stof(radius_s);

    return std::make_unique<Circle>(text, pos, spd, color, radius);
}

std::unique_ptr<Rectangle> TextParser::ParseRectangle(std::string &data) {
    std::istringstream iss(data);
    std::string shape_type;
    iss >> shape_type;

    //name parsing
    std::string text;
    iss >> text;

    //position parsing
    sf::Vector2f pos;
    std::string pos_x, pos_y;
    iss >> pos_x;
    iss >> pos_y;
    pos.x = std::stof(pos_x);
    pos.y = std::stof(pos_y);

    //speed parsing
    sf::Vector2f spd;
    std::string spd_x, spd_y;
    iss >> spd_x;
    iss >> spd_y;
    spd.x = std::stof(spd_x);
    spd.y = std::stof(spd_y);

    //color parsing
    sf::Color color;
    std::string color_s;
    iss >> color_s;
    color = ParseColor(color_s);

    //size parsing
    float width,height;
    std::string width_s, height_s;
    iss >> width_s;
    iss >> height_s;
    width = std::stof(width_s);
    height = std::stof(height_s);

    return std::make_unique<Rectangle>(text, pos, spd, color, width, height);
}