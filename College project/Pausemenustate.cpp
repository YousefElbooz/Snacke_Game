#include "Pausemenustate.h"

PauseMenuState::PauseMenuState(sf::RenderWindow& window,sf::Font &font,std::string Headline)
:font(font),headline(Headline)
{
	for(int i=0;i<2;i++)
	{
		this->buttons[i] = NULL;
	}
	this->background.setSize(
		sf::Vector2f(
			(static_cast<float>(window.getSize().x)),
			(static_cast<float>(window.getSize().y))
		));
	this->background.setFillColor(sf::Color(20, 20, 50, 100));

	this->container.setSize(
		sf::Vector2f(
			(static_cast<float>(window.getSize().x)/4.f),
			(static_cast<float>(window.getSize().y)-100.f)
		));	this->container.setFillColor(sf::Color(20, 20, 50, 200));
	this->container.setPosition((static_cast<float>(window.getSize().x)/2.f-this->container.getSize().x/2.f),30.f);
	
	this->Pmenutext.setFont(font);
	this->Pmenutext.setFillColor(sf::Color(255, 255, 255, 200));
	this->Pmenutext.setCharacterSize(60);
	this->Pmenutext.setString(headline);
	this->Pmenutext.setPosition(this->container.getPosition().x+this->container.getSize().x/2.f-this->Pmenutext.getGlobalBounds().width/2.f, this->container.getPosition().y+20.f);
}

PauseMenuState::~PauseMenuState()
{
	for (int i = 0; i < 2; i++)
	{
		delete this->buttons[i];
	}
}

//Button*& PauseMenuState::getbuttons(int i)
//{
//	return this->buttons[i];
//	// TODO: insert return statement here
//}

void PauseMenuState::addButton(int i,float x, float y, const std::string text)
{
	this->buttons[i] = new Button(
		x,y, 300, 70,
		&this->font,
		text,
		70,
		sf::Color(170, 70, 70, 200),
		sf::Color(250, 150, 150, 250),
		sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0),
		sf::Color(150, 150, 150, 0),
		sf::Color(20, 20, 20, 0)
	);
}

const bool PauseMenuState::getButtonPresed(int i)
{
	return this->buttons[i]->ispressed();
}

void PauseMenuState::update(sf::Vector2f mousePosView)
{
	for (int i = 0; i < 2; i++) 
	{
		this->buttons[i]->update(mousePosView);
	}
}

void PauseMenuState::render(sf::RenderTarget& target)
{
	target.draw(background);
	target.draw(container);
	target.draw(this->Pmenutext);
	for (int i = 0; i < 2; i++)
	{
		this->buttons[i]->render(&target);
	}
}
