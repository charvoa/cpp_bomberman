//
// Leaderboard.cpp for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat May 16 15:18:59 2015 Nicolas Charvoz
// Last update Thu May 28 14:38:09 2015 Nicolas Charvoz
//

#include "Exit.hh"
#include "SousMenuButton.hh"
#include "MenuBackground.hh"
#include <OpenGL.hh>
#include <iostream>
#include <Texture.hh>

TextureManager &Exit::_texManag = TextureManager::getInstance();

Exit::Exit(Game *game)
{
  _game = game;
  std::cout << "Je suis dans Exit" << std::endl;
  _texManag.registerTexture("BackgroundCredit", "backEnd");
  this->loadBackground();
  this->loadButtons();
}

void Exit::loadBackground()
{
  AObject *background = new MenuBackground();

  background->initialize(_texManag.getTexture("backEnd"));
  _background = background;
}

void Exit::loadButtons()
{
}

void Exit::drawBackground(gdl::Clock& clock, gdl::BasicShader& shader)
{
  _background->draw(shader, clock);
}

void Exit::drawButtons(gdl::Clock& clock, gdl::BasicShader& shader)
{
  (void) clock;
  (void) shader;
}

void Exit::draw(gdl::Clock& clock, gdl::BasicShader& shader)
{
  this->drawButtons(clock, shader);
  this->drawBackground(clock, shader);
}

bool Exit::update(gdl::Clock& shader, gdl::Input& input)
{
  (void) shader;
  if (input.getInput(SDLK_BACKSPACE) == true)
    {
      _game->popState();
    }
  return true;
}

Exit::~Exit()
{}
