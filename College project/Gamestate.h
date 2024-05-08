
#pragma once
#include "state.h"
#include "Pausemenustate.h"
enum SnakDirectionState { UP, DOWN, RIGHT, LEFT, RIGHT_TOP, RIGHT_DOWN, LEFT_TOP, LEFT_DWON };
struct Gamestate :
    public State
{
private:
    sf::Font font;
    PauseMenuState* Pmenu[2];
    bool paused = false;
    bool is_die = false;
    sf::Texture backgroundtexture;
    sf::RectangleShape background;
    sf::Clock clock;
    sf::Text scoretext, highscoretext;
    sf::Font scorefont;
    int score = 0, highscore = 0, num = 4;
    short unsigned dir, perviousdir, nextdir, curve;
    double timer = 0, delay = 0.1;
    sf::Texture t1, t2, t3, body, head, tail, bomb, playingtable;
    sf::Sprite sprite1, sprite2, sprite3, shead, stail, splayingtable, sbody, sbomb;
    sf::Sound sound[2];
    sf::SoundBuffer buffer[2];
    struct snake
    {
        int x, y;
    } s[100];
    struct fod
    {
        int x = 5, y = 5;
    } f[2];
    struct bomb
    {
        int x, y;
    } b[20];
    //fun 
    void initFonts();
    void snakedirection();
    void createsnake();
    void eatingfood();
    void eatingbomb();
    void Snackedie();

    void initTexture();
    void initBackground();
    void initPauseMenu();
public:

    void RenderBackground(sf::RenderTarget* target);
    void Renderthesnacketable(sf::RenderTarget* target);
    void Renderthesnackebody(sf::RenderTarget* target);
    void Renderthefood(sf::RenderTarget* target);
    void Renderthebomb(sf::RenderTarget* target);
    void Renderthetexts(sf::RenderTarget* target);
    void reachthewallborder();
    Gamestate(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~Gamestate();

    //function 
    void pausedstate();
    void unpausedstate();
    void updatepausedkeys(const float& dt);
    void updateButtons();
    void update(const float& dt);
    void render(sf::RenderTarget* target);
    void updatekeybinds(const float& dt);

};
