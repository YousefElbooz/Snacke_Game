#include "game.h"
#include "mainmenustate.h"

void Game::initwindow()
{
    //creates a sfml window using optin from a window .inti file.
    std::ifstream ifs("config/window.txt");

    std::string title = "none";
    unsigned frameratelim = 120;
    bool fullscreen = false;
    bool verticalsyncenabeld = false;


    sf::VideoMode window_bounds = sf::VideoMode::getDesktopMode();
    if (ifs.is_open())
    {
        std::getline(ifs, title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> fullscreen;
        ifs >> frameratelim;
        ifs >> verticalsyncenabeld;

    }
    ifs.close();
    this->fullscreen = fullscreen;
    if (this->fullscreen)
    {
        this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Fullscreen);
    }
    else
    {
        this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Titlebar | sf::Style::Close);

    }
    this->window->setFramerateLimit(frameratelim);
    this->window->setVerticalSyncEnabled(verticalsyncenabeld);
}
void Game::initvariables()
{
    this->window = NULL;
    this->fullscreen = 0;
    this->dt = 0.f;

}
void Game::initstate()
{
    this->states.push(new  MainMenuState(this->window, &this->states));
}

void Game::initsound()
{
    this->buffer.loadFromFile("Resources/btn/snake_music.mp3");
    this->sound.setBuffer(buffer);
    this->sound.play();
    this->sound.setLoop(true);
}

//Constructor/distructor
Game::Game()
{
    this->initsound();
    this->initvariables();
    this->initwindow();
    this->initstate();

}
Game::~Game()
{
    delete this->window;
    while (!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
}
//functions
void Game::update()
{
    if (!this->states.empty())
    {
        this->states.top()->update(this->dt);
        if (this->states.top()->getQuit())
        {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }
    else
    {
        this->endApplication();
        this->window->close();
    }
    this->UpdateEvents();
}
void Game::render()
{
    this->window->clear();
    //render items
    if (!this->states.empty())
    {
        this->states.top()->render(this->window);
    }
    this->window->display();
}
void Game::run()
{
    while (this->window->isOpen())
    {
        this->updatedt();
        this->update();
        this->render();
    }
}
void Game::UpdateEvents()
{
    this->sfEvent;
    while (this->window->pollEvent(sfEvent))
    {
        if (sfEvent.type == sf::Event::Closed)
            this->window->close();
    }
}
void Game::endApplication()
{
    std::cout << "Ending application " << "\n";
}
void Game::updatedt()
{
    this->dt = this->dtClock.restart().asSeconds();
    
}