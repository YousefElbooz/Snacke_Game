#include "Buttons.h"
Button::Button(
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
    sf::Color activecolor)
{
    this->shape.setPosition(sf::Vector2f(x, y));
    this->shape.setSize(sf::Vector2f(width, height));
    this->font = font;
    this->text.setFont(*this->font);
    this->text.setString(text);
    this->text.setFillColor(this->textIdelcolor);
    this->text.setCharacterSize(character_Sisze);
    this->text.setPosition(
        this->shape.getPosition().x + (this->shape.getSize().x - this->text.getGlobalBounds().width) / 2,
        this->shape.getPosition().y + (this->shape.getSize().y - this->text.getGlobalBounds().height) / 2 - 20
    );

    this->Button_State = BTN_IDLE;
    this->idelcolor = idelcolor;
    this->hovercolor = hovercolor;
    this->activecolor = activecolor;
    this->shape.setFillColor(this->idelcolor);
    this->textIdelcolor = text_idel_color;
    this->textHovercolor = text_hover_color;
    this->textActivatecolor = text_active_color;
    buffer[0].loadFromFile("Resources/btn/mouse-click-153941.mp3");
    buffer[1].loadFromFile("Resources/btn/button-124476.mp3");
    this->sound[0].setBuffer(buffer[0]);
    this->sound[1].setBuffer(buffer[1]);
}
Button::~Button()
{
}
const bool Button::ispressed() const
{
    if (this->Button_State == BTN_ACTIVATED)
    {
        return true;
    }
    return false;
}
void Button::update(const sf::Vector2f& mouseposView)
{
    this->Button_State = BTN_IDLE;
    //hover
    if (this->shape.getGlobalBounds().contains(mouseposView))
    {
        this->Button_State = BTN_HOVERD;
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->Button_State = BTN_ACTIVATED;
        }

    };
    switch (this->Button_State)
    {
    case BTN_IDLE:
        sound[0].play();
        this->shape.setFillColor(this->idelcolor);
        this->text.setFillColor(this->textIdelcolor);
        break;
    case BTN_HOVERD:
        this->shape.setFillColor(this->hovercolor);
        this->text.setFillColor(this->textHovercolor);
        break;
    case BTN_ACTIVATED:
        this->shape.setFillColor(this->activecolor);
        this->text.setFillColor(this->textActivatecolor);
        this->sound[1].play();
        break;
    default:
        this->shape.setFillColor(sf::Color::Red);
        this->text.setFillColor(sf::Color::Blue);
        break;
    }
}
void Button::render(sf::RenderTarget* target)
{
    target->draw(this->shape);
    target->draw(this->text);
}
