#include "mainmenustate.h"

void MainMenuState::initVariabeles()
{
}

void MainMenuState::initBackground()
{
    this->background.setSize(
        sf::Vector2f(
            static_cast <float>(this->window->getSize().x),
            static_cast <float>(this->window->getSize().y))
    );
    if (!this->backgroundtexture.loadFromFile("Resources/Images/Backgrounds/snake-game-1680-x-1050-background-6syqer1fr6oahe0b.jpg"))
    {
        throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_THE_BACKGROUND_TEXTURE";
    }
    this->background.setTexture(&this->backgroundtexture);
}

void MainMenuState::initFonts()
{


    if (!font.loadFromFile("imageserterte/River Adventurer.ttf"))
    {
        throw("MAINMENUSTATE::ERROR IN FONTs");
    }
}


void MainMenuState::initButtons()
{
    this->playicon.loadFromFile("Resources/btn/play.png");
    this->splayicon.setTexture(&playicon);
    this->splayicon.setPosition(50.f, 130.f);
    this->splayicon.setSize(sf::Vector2f(50.f, 50.f));
    this->buttons[0] = new Button(
        150, 120, 300, 70,
        &this->font,
        " NEW GAME ",
        70,
        sf::Color(170, 70, 70, 200),
        sf::Color(250, 150, 150, 250),
        sf::Color(20, 20, 20, 50),
        sf::Color(70, 70, 70, 0),
        sf::Color(150, 150, 150, 0),
        sf::Color(20, 20, 20, 0)
    );
    this->settingsicon.loadFromFile("Resources/btn/settings.png");
    this->ssettingsicon.setTexture(&settingsicon);
    this->ssettingsicon.setPosition(50.f, 250.f);
    this->ssettingsicon.setSize(sf::Vector2f(50.f, 50.f));
    this->buttons[1] = new Button(
        150, 240, 300, 70,
        &this->font,
        " SETTINGS ",
        70,
        sf::Color(170, 70, 70, 200),
        sf::Color(250, 150, 150, 250),
        sf::Color(20, 20, 20, 50),
        sf::Color(70, 70, 70, 0),
        sf::Color(150, 150, 150, 0),
        sf::Color(20, 20, 20, 0)
    );
    this->exiticon.loadFromFile("Resources/btn/close.png");
    this->sexiticon.setTexture(&exiticon);
    this->sexiticon.setPosition(50.f, 370.f);
    this->sexiticon.setSize(sf::Vector2f(50.f, 50.f));
    this->buttons[2] = new Button(
        150, 360, 300, 70,
        &this->font,
        " EXIT ",
        70,
        sf::Color(170, 70, 70, 200),
        sf::Color(250, 150, 150, 250),
        sf::Color(20, 20, 20, 50),
        sf::Color(70, 70, 70, 0),
        sf::Color(150, 150, 150, 0),
        sf::Color(20, 20, 20, 0)
    );





}

void MainMenuState::UpdateButtons()
{
    for (int i=0; i < 3; i++)
    {
        buttons[i]->update(this->mousePosView);
    }
 
    if (buttons[2]->ispressed())
    {
        this->endState();
    }
    
    if (buttons[0]->ispressed())
    {
        this->states->push(new  Gamestate(this->window, this->states));
    }
}

void MainMenuState::RenderButtons(sf::RenderTarget* target)
{
    for (int i=0; i < 3; i++)
    {
        buttons[i]->render(target);
    }
}



MainMenuState::MainMenuState(sf::RenderWindow* window, std::stack<State*>* states)
    :State(window, states)
{
    this->initVariabeles();
    this->initBackground();
    this->initFonts();
    this->initButtons();
}

MainMenuState::~MainMenuState()
{

    for (int i=0; i < 3; i++)
    {
        delete buttons[i];
    }
}

void MainMenuState::update(const float& dt)
{
    this->updatemousepostion();
    //system("cls");
    //std::cout << this->mousePosView.x << " " << this->mousePosView.y << "\n";
    this->UpdateButtons();
}
void MainMenuState::render(sf::RenderTarget* target)
{
    if (!target)
        target = this->window;
    target->draw(this->background);
    this->RenderButtons(target);
    target->draw(splayicon);
    target->draw(ssettingsicon);
    target->draw(sexiticon);
    sf::Text mousetext;
    mousetext.setPosition(this->mousePosView.x, this->mousePosView.y - 50);
    mousetext.setFont(this->font);
    mousetext.setCharacterSize(14);
    std::stringstream ss;
    ss << this->mousePosView.x << " , " << this->mousePosView.y;
    mousetext.setString(ss.str());
    target->draw(mousetext);
}