//
// RandomMenu.cpp for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat May 16 15:18:59 2015 Nicolas Charvoz
// Last update Tue Jun  2 19:32:58 2015 Nicolas Charvoz
//

#include "RandomMenu.hh"
#include <OpenGL.hh>
#include <iostream>
#include <Texture.hh>

TextureManager &RandomMenu::_texManag = TextureManager::getInstance();

RandomMenu::RandomMenu(Game *game)
{
  _game = game;
  std::cout << "Je suis dans RandomMenu" << std::endl;
  _texManag.registerTexture("backgroundRandom", "backRM");
  this->loadBackground();
  this->loadButtons();
}

void RandomMenu::loadBackground()
{
  AObject *background = new MenuBackground();

  background->initialize(_texManag.getTexture("backgroundRM"));
  _background = background;
}

void RandomMenu::loadButtons()
{
}

void RandomMenu::drawBackground(gdl::Clock& clock, gdl::BasicShader& shader)
{
  _background->draw(shader, clock);
}

void RandomMenu::drawButtons(gdl::Clock& clock, gdl::BasicShader& shader)
{
  (void) shader;
  (void) clock;
}

void RandomMenu::draw(gdl::Clock& clock, gdl::BasicShader& shader)
{
  this->drawButtons(clock, shader);
  this->drawBackground(clock, shader);
}

bool RandomMenu::update(gdl::Clock& shader, gdl::Input& input)
{
  (void) shader;
  if (input.getInput(SDLK_BACKSPACE) == true)
    {
      _game->popState();
    }
  return true;
}

RandomMenu::~RandomMenu()
{}
