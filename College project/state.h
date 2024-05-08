#pragma once
#include "Buttons.h"
struct State
{
protected:
    std::stack<State*>* states;
    sf::RenderWindow* window;
    bool Quit = false;
    bool paused = false;
    bool is_die = false;
    float keytime = 0.f;
    float keytimemax = 10.f;
    //resources
    sf::Vector2i mousePosScreen;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;
    //functin

public:
    State(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~State();

    const bool& getQuit()const;
    const bool getkeytime();
    //functions 

    virtual void updatekeytime(const float& dt);
    virtual void updatemousepostion();
    virtual void endState();
    virtual void update(const float& dt) = 0;
    virtual	void render(sf::RenderTarget* target = nullptr) = 0;

};