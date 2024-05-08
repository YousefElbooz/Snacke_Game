#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include<iostream>
#include<ctime>
#include <string>
#include <stack>
#include <fstream>
#include <sstream>
#include <map>
enum ButtonState { BTN_IDLE, BTN_HOVERD, BTN_ACTIVATED };
struct Button
{


private:
    short unsigned Button_State;
    sf::RectangleShape shape;
    sf::Font* font;
    sf::Text text;
    sf::Color textIdelcolor;
    sf::Color textHovercolor;
    sf::Color textActivatecolor;

    sf::Color idelcolor;
    sf::Color hovercolor;
    sf::Color activecolor;
    sf::Sound sound[3];
    sf::SoundBuffer buffer[3];
public:

    Button(
        float x,
        float y,
        float width,
        float height,
        sf::Font* font,
        std::string text,
        unsigned character_Sisze,
        sf::Color text_idel_color,
        sf::Color text_hover_color,
        sf::Color text_active_color,
        sf::Color idelcolor,
        sf::Color hovercolor,
        sf::Color activecolor);

    virtual ~Button();
    const bool ispressed() const;
    void update(const sf::Vector2f& mouseposView);
    void render(sf::RenderTarget* target);
};