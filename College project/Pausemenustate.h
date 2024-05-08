#pragma once
#include "state.h"
struct PauseMenuState
{
private:
    std::string headline;
    sf::Font& font;
    sf::Text Pmenutext;
    sf::RectangleShape background;
    sf::RectangleShape container;
    Button* buttons[2];
public:
    PauseMenuState(sf::RenderWindow& window,sf::Font& font,std::string Headline);
    virtual ~PauseMenuState();
    //Accessor
    //Button* &getbuttons(int i);
    void addButton(int i,float x,float y,const std::string text);
    const bool getButtonPresed(int i);
    void update(sf::Vector2f mousePosView);
    void render(sf::RenderTarget& target);
    
};
