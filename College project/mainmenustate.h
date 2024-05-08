#pragma once
#include "state.h"
#include "Gamestate.h"
struct MainMenuState
    :public State
{
private:
    //variables
    sf::Texture playicon;
    sf::Texture settingsicon;
    sf::Texture exiticon;
    sf::RectangleShape splayicon;
    sf::RectangleShape ssettingsicon;
    sf::RectangleShape sexiticon;
    sf::Texture backgroundtexture;
    sf::RectangleShape background;
    sf::Font font;
    Button* buttons[3];

    //fun 
    void initVariabeles();
    void initBackground();
    void initFonts();
    void initButtons();
    void UpdateButtons();
    void RenderButtons(sf::RenderTarget* target);
public:
    MainMenuState(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~MainMenuState();
    //function 
    void update(const float& dt);
    void render(sf::RenderTarget* target);
};