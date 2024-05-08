#pragma once
#include "state.h"
struct Game
{
private:
    //Vars
    sf::Sound sound;
    sf::SoundBuffer buffer;
    sf::RenderWindow* window;//->? point you need to understand we put it pointer because we need to use it dinamically
    sf::Event sfEvent;
    sf::Clock dtClock;
    float dt; //to make const move per frame in any device 
    std::stack<State*>states;
    bool fullscreen;
    //Initialisation
    void initvariables();
    void initwindow();
    void initstate();
    void initsound();
public:
    //Constructor/distructor
    Game();
    virtual ~Game();

    //function

    // regluer
    void endApplication();
    //update
    void updatedt();
    void update();

    //render
    void render();

    //core
    void run();
    void UpdateEvents();

};