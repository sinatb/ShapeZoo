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