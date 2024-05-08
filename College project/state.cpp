
#include "state.h"
State::State(sf::RenderWindow* window, std::stack<State*>* states)
{
    this->window = window;
    this->states = states;
    this->Quit = false;
}
State::~State()
{
}
const bool& State::getQuit() const
{
    return this->Quit;
}
const bool State::getkeytime()
{
    if (this->keytime >= this->keytimemax)
    {
        this->keytime = 0.f;
        return true;
    }
    else
        return false;
}
void State::updatekeytime(const float& dt)
{
    if (this->keytime < this->keytimemax) {
        this->keytime += 100.f * dt;
    }
}
void State::updatemousepostion()
{
    this->mousePosScreen = sf::Mouse::getPosition();
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}
void State::endState()
{
    std::cout << "Ending Gamestate" << "\n";
    this->Quit = true;
}
