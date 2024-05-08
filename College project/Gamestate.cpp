#include "Gamestate.h"

void Gamestate::initTexture()
{
    scorefont.loadFromFile("imageserterte/NineTsuki.otf");    sf::Texture temp;
    t1.loadFromFile("imageserterte/white.png");
    t2.loadFromFile("imageserterte/green.png");
    t3.loadFromFile("imageserterte/apple_alt_32.png");
    bomb.loadFromFile("imageserterte/bomb_32.png");
    scoretext.setFont(scorefont);
    scoretext.setString("Highscore :" + std::to_string(score));
    scoretext.setFillColor(sf::Color::Black);
    scoretext.setCharacterSize(50);
    scoretext.setPosition(95.f, 200.f);
    sbomb.setTexture(bomb);
    sbomb.setScale(0.5, 0.5);
    highscoretext.setFont(scorefont);
    highscoretext.setString("Highscore :" + std::to_string(highscore));
    highscoretext.setFillColor(sf::Color::Black);
    highscoretext.setCharacterSize(50);
    highscoretext.setPosition(95.f, 400.f);
    sprite1.setTexture(t1);
    sprite2.setTexture(t2);
    sprite3.setTexture(t3);
    sprite3.setScale(0.5, 0.5);
    head.loadFromFile("imageserterte/head_up.png");
    shead.setTexture(head);
    shead.setScale(0.5, 0.5);
    tail.loadFromFile("imageserterte/tail_down.png");
    stail.setTexture(tail);
    stail.setScale(0.5, 0.5);
    body.loadFromFile("imageserterte/tail_down.png");
    sbody.setTexture(body);
    sbody.setScale(0.5, 0.5);
    playingtable.loadFromFile("imageserterte/Cartoon_green_texture_grasst.jpg");
    splayingtable.setTexture(playingtable);
    splayingtable.setScale(1.5, 1.6667);
    buffer[0].loadFromFile("Resources/btn/food_G1U6tlb.mp3");
    buffer[1].loadFromFile("Resources/btn/90s-game-ui-6-185099.mp3");
    this->sound[0].setBuffer(buffer[0]);
    this->sound[1].setBuffer(buffer[1]);
}
void Gamestate::initFonts()
{


    if (!font.loadFromFile("imageserterte/NineTsuki.otf"))
    {
        throw("MAINMENUSTATE::ERROR IN FONTs");
    }
}
void Gamestate::RenderBackground(sf::RenderTarget* target)
{
    target->draw(background);
}
void Gamestate::Renderthesnacketable(sf::RenderTarget* target)
{
    for (int i = 0; i < 60; i++)
        for (int j = 0; j < 50; j++)
        {
            sprite1.setPosition((2800 / 2) - float(i) * 16, float((1700 / 2)) - float(j) * 16); target->draw(sprite1);
        }
    splayingtable.setPosition((2800 / 2) - 59 * 16, float((1700 / 2)) - 49 * 16); target->draw(splayingtable);

}
void Gamestate::Renderthesnackebody(sf::RenderTarget* target)
{
    for (int i = 0; i < num; i++)
    {
        if (i == 0)
        {
            switch (dir)
            {
            case UP:
                head.loadFromFile("imageserterte/head_up.png");
                shead.setPosition(float(2800 / 2) - s[i].x * 16, float((1700 / 2)) - s[i].y * 16); target->draw(shead);
                break;

            case DOWN:
                head.loadFromFile("imageserterte/head_down.png");
                shead.setPosition(float(2800 / 2) - s[i].x * 16, float((1700 / 2)) - s[i].y * 16); target->draw(shead);
                break;

            case LEFT:
                head.loadFromFile("imageserterte/head_left.png");
                shead.setPosition(float(2800 / 2) - s[i].x * 16, float((1700 / 2)) - s[i].y * 16); target->draw(shead);
                break;

            case RIGHT:
                head.loadFromFile("imageserterte/head_right.png");
                shead.setPosition(float(2800 / 2) - s[i].x * 16, float((1700 / 2)) - s[i].y * 16); target->draw(shead);
                break;

            default:
                break;
            }
        }

        else if (i == num - 1)
        {
            switch (s[i].x - s[i + 1].x)
            {
            case 0:
                switch (s[i].y - s[i + 1].y)
                {
                case 1:
                    tail.loadFromFile("imageserterte/tail_down.png");
                    stail.setPosition(float(2800 / 2) - s[i].x * 16, float(float((1700 / 2))) - s[i].y * 16); target->draw(stail);
                    break;
                case -1:
                    tail.loadFromFile("imageserterte/tail_up.png");
                    stail.setPosition(float(2800 / 2) - s[i].x * 16, float((1700 / 2)) - s[i].y * 16); target->draw(stail);
                    break;
                default:
                    break;
                }
                break;
            case 1:
                tail.loadFromFile("imageserterte/tail_right.png");
                stail.setPosition(float(2800 / 2) - s[i].x * 16, float((1700 / 2)) - s[i].y * 16); target->draw(stail);
                break;

            case -1:
                tail.loadFromFile("imageserterte/tail_left.png");
                stail.setPosition(float(2800 / 2) - s[i].x * 16, float(1700 / 2) - s[i].y * 16); target->draw(stail);
                break;

            default:
                break;
            }
        }
        else
        {
            switch (s[i].x - s[i + 1].x)
            {
            case 0:
                switch (s[i].y - s[i + 1].y)
                {
                case 1:
                    body.loadFromFile("imageserterte/body_vertical.png");
                    sbody.setPosition(float(2800 / 2) - s[i].x * 16, float(1700 / 2) - s[i].y * 16); target->draw(sbody);
                    break;
                case -1:
                    body.loadFromFile("imageserterte/body_vertical.png");
                    sbody.setPosition(float(2800 / 2) - s[i].x * 16, float(1700 / 2) - s[i].y * 16); target->draw(sbody);
                    break;
                default:
                    break;
                }
                break;
            case 1:
                body.loadFromFile("imageserterte/body_horizontal.png");
                sbody.setPosition(float(2800 / 2) - s[i].x * 16, float(1700 / 2) - s[i].y * 16); target->draw(sbody);
                break;

            case -1:
                body.loadFromFile("imageserterte/body_horizontal.png");
                sbody.setPosition(float(2800 / 2) - s[i].x * 16, float(1700 / 2) - s[i].y * 16); target->draw(sbody);
                break;
            default:
                break;
            }
            //switch (s[i + 2].x - s[i + 1].x)
            //{
            //case 0:
            //    switch (s[i + 2].y - s[i + 1].y)
            //    {
            //    case 1:nextdir = UP;
            //        break;
            //    case -1:nextdir = DOWN;
            //        break;
            //    default:
            //        break;
            //    }
            //    break;
            //case 1:nextdir = LEFT;
            //    break;
            //case -1:nextdir = RIGHT;
            //    break;
            //default:
            //    break;
            //}
            //switch (s[i].x - s[i - 1].x)
            //{
            //case 0:
            //    switch (s[i].y - s[i - 1].y)
            //    {
            //    case 1:perviousdir = UP;
            //        break;
            //    case -1:perviousdir = DOWN;
            //        break;
            //    default:
            //        break;
            //    }
            //    break;
            //case 1:perviousdir = LEFT;
            //    break;
            //case -1:perviousdir = RIGHT;
            //    break;
            //default:
            //    break;
            //}
            //if (perviousdir == LEFT && nextdir == UP)
            //{
            //    curve = LEFT_TOP;
            //}
            //else if (perviousdir == LEFT && nextdir == DOWN)
            //{
            //    curve = LEFT_DWON;
            //}
            //else if (perviousdir == RIGHT && nextdir == UP)
            //{
            //    curve = RIGHT_TOP;
            //}
            //else if (perviousdir == RIGHT && nextdir == DOWN)
            //{
            //    curve = RIGHT_DOWN;
            //}
            ////
            //else if (perviousdir == UP && nextdir == LEFT)
            //{
            //    curve = RIGHT_DOWN;
            //}
            //else if (perviousdir == DOWN && nextdir == LEFT)
            //{
            //    curve = RIGHT_TOP;
            //}
            //else if (perviousdir == UP && nextdir == RIGHT)
            //{
            //    curve = LEFT_DWON;
            //}
            //else if  (perviousdir == DOWN && nextdir == RIGHT)
            //{
            //    curve = LEFT_TOP;
            //}
            //switch (curve)
            //{
            //case LEFT_TOP:
            //    body.loadFromFile("imageserterte/body_topright.png");
            //    sbody.setPosition((2180 / 2) - s[i].x * 16, (1350 / 2) - s[i].y * 16); target->draw(sbody);
            //    break;

            //case LEFT_DWON:
            //    body.loadFromFile("imageserterte/body_bottomright.png");
            //    sbody.setPosition((2180 / 2) - s[i].x * 16, (1350 / 2) - s[i].y * 16); target->draw(sbody);
            //    break;

            //case RIGHT_TOP:
            //    body.loadFromFile("imageserterte/body_topleft.png");
            //    sbody.setPosition((2180 / 2) - s[i].x * 16, (1350 / 2) - s[i].y * 16); target->draw(sbody);
            //    break;

            //case RIGHT_DOWN:
            //    body.loadFromFile("imageserterte/body_bottomleft.png");
            //    sbody.setPosition((2180 / 2) - s[i].x * 16, (1350 / 2) - s[i].y * 16); target->draw(sbody);
            //    break;

            //default:
            //    break;
            //}
        }
    }
}

void Gamestate::Renderthefood(sf::RenderTarget* target)
{
    {
        sprite3.setPosition(float(2800 / 2) - f[0].x * 16, float(1700 / 2) - f[0].y * 16); target->draw(sprite3);
        sprite3.setPosition(float(2800 / 2) - f[1].x * 16, float(1700 / 2) - f[1].y * 16); target->draw(sprite3);
    }
}


void Gamestate::initPauseMenu()
{

    this->Pmenu[0] = new PauseMenuState(*this->window, this->font, "PAUSED");
    this->Pmenu[1] = new PauseMenuState(*this->window, this->font, "You Losed");
    this->Pmenu[0]->addButton(1, 700.f, 400.f, "Continuoe");
    this->Pmenu[0]->addButton(0, 700.f, 700.f, "Quit");
    this->Pmenu[1]->addButton(1, 700.f, 400.f, "Continuoe");
    this->Pmenu[1]->addButton(0, 700.f, 700.f, "Quit");
}

void Gamestate::Renderthebomb(sf::RenderTarget* target)
{
    { sbomb.setPosition(float(2800 / 2) - b[0].x * 16, float(1700 / 2) - b[0].y * 16); target->draw(sbomb); }
    { sbomb.setPosition(float(2800 / 2) - b[1].x * 16, float(1700 / 2) - b[1].y * 16); target->draw(sbomb); }
}

void Gamestate::Renderthetexts(sf::RenderTarget* target)
{
    target->draw(scoretext);
    target->draw(highscoretext);
}

void Gamestate::reachthewallborder()
{
    //-->>//reach the wall border
    if (s[0].x < 0) s[0].x = 59; if (s[0].x > 59) s[0].x = 0;
    if (s[0].y < 0) s[0].y = 49; if (s[0].y > 49) s[0].y = 0;
}

Gamestate::Gamestate(sf::RenderWindow* window, std::stack<State*>* states)
    :State(window, states)
{

    this->initBackground();
    this->initFonts();
    this->initTexture();
    this->initPauseMenu();
}

Gamestate::~Gamestate()
{
    delete this->Pmenu[0];
    delete this->Pmenu[1];
}

; void Gamestate::updatekeybinds(const float& dt)
{

    //updaete player move 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        dir = LEFT;
        //this->player->move(dt, -1, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        dir = RIGHT;
        //this->player->move(dt, 1, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        dir = UP;
        //this->player->move(dt, 0, -1);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        dir = DOWN;
        //this->player->move(dt, 0, 1);
    }

}
void Gamestate::pausedstate()
{
    this->paused = true;
}
void Gamestate::unpausedstate()
{
    this->paused = false;
}
void Gamestate::updatepausedkeys(const float& dt)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && this->getkeytime()) {
        if (!this->paused && !this->is_die)
        {
            this->pausedstate();
        }
        else if (this->paused) {
            this->unpausedstate();
        }
        else {
            this->is_die = false;
        }
    }
}
void Gamestate::updateButtons()
{
    for (int i = 0; i < 2; i++)
        if (this->Pmenu[i]->getButtonPresed(0) && this->getkeytime())
        {
            this->endState();
        }
        else if (this->Pmenu[i]->getButtonPresed(1) && this->getkeytime())
        {
            if (paused)
            {
                this->unpausedstate();
            }
            else if (is_die)
            {
                this->is_die = false;
            }
        }

}
void Gamestate::initBackground()
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
void Gamestate::update(const float& dt)
{
    this->updatekeytime(dt);
    this->updatemousepostion();
    this->updatepausedkeys(dt);
    this->updateButtons();
    if (!this->paused && !this->is_die) {
        this->updatekeybinds(dt);
        float time = dt;
        clock.restart();
        timer += 1.5 * time;
        if (timer >= delay) {
            timer = 0;
            this->reachthewallborder();
            this->createsnake();
            this->snakedirection();
            this->eatingfood();
            this->eatingbomb();
            this->Snackedie();
        }
    }
    else if (is_die) {
        this->Pmenu[1]->update(this->mousePosView);
    }
    else {
        this->Pmenu[0]->update(this->mousePosView);
    }
}
void Gamestate::render(sf::RenderTarget* target)
{
    //-->>render the all snakcke and backgroud
    if (!target)
        target = this->window;
    this->RenderBackground(target);
    this->Renderthesnacketable(target);
    this->Renderthebomb(target);
    this->Renderthefood(target);
    this->Renderthetexts(target);
    this->Renderthesnackebody(target);
    if (this->paused) {
        this->Pmenu[0]->render(*target);
    }
    else if (this->is_die) {
        this->Pmenu[1]->render(*target);
    }
}


void Gamestate::snakedirection()
{

    //-->>//snacke direction
    if (dir == UP) s[0].y += 1;
    if (dir == DOWN) s[0].y -= 1;
    if (dir == LEFT) s[0].x += 1;
    if (dir == RIGHT) s[0].x -= 1;

}

void Gamestate::createsnake()
{
    //-->>//creating the snacke 
    for (int i = num; i > 0; i--)
    {
        s[i].x = s[i - 1].x; s[i].y = s[i - 1].y;
    }
}



void Gamestate::eatingfood()
{
    //-->>//eating apple
    if (s[0].x == f[0].x && s[0].y == f[0].y || s[0].x == f[1].x && s[0].y == f[1].y) {
        sound[0].play();
        num++;
        f[0].x = rand() % 59;
        f[0].y = rand() % 49;

        f[1].x = rand() % 59;
        f[1].y = rand() % 49;
        b[0].x = rand() % 59;
        b[0].y = rand() % 49;

        b[1].x = rand() % 59;
        b[1].y = rand() % 49;

        b[2].x = rand() % 59;
        b[2].y = rand() % 49;
        score += 1;
        if (score % 3 == 0) {
            sound[1].play();
        }
        scoretext.setString("score :" + std::to_string(score));
        if (highscore <= score) { highscore = score; }
        highscoretext.setString("Highscore :" + std::to_string(highscore));
    }
}
void Gamestate::eatingbomb()
{
    //-->>//eating bomb shrinks until dying
    if (s[0].x == b[0].x && s[0].y == b[0].y || s[0].x == b[1].x && s[0].y == b[1].y)
    {
        if (num > 4)
        {
            num--;
        }
        else {
            num = 3, score = 0, scoretext.setString("score :" + std::to_string(score)), highscoretext.setString("Highscore :" + std::to_string(highscore));

            if (this->getkeytime()) {
            } is_die = true;


        }
        b[0].x = rand() % 59;
        b[0].y = rand() % 49;
        b[1].x = rand() % 59;
        b[1].y = rand() % 49;
        b[2].x = rand() % 59;
        b[2].y = rand() % 49;
    }
}
void Gamestate::Snackedie()
{
    //-->>//snacke bite it self
    for (int i = num; i > 0; i--)
        if (s[0].x == s[i].x && s[0].y == s[i].y && s[0].x != s[1].x && s[0].y != s[1].y) {
            num = 3, score = 0, scoretext.setString("score :" + std::to_string(score)), highscoretext.setString("Highscore :" + std::to_string(highscore));
            if (this->getkeytime()) {
            } is_die = true;
        }
}