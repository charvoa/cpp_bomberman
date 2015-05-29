//
// Options:.cpp for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat May 16 15:18:59 2015 Nicolas Charvoz
// Last update Thu May 28 21:09:09 2015 Nicolas Charvoz
//

#include "Options.hh"
#include "SousMenuButton.hh"
#include "MenuBackground.hh"
#include <OpenGL.hh>
#include <iostream>
#include <Texture.hh>

Options::Options(Game *game)
{
  _game = game;
  std::cout << "Je suis dans Options" << std::endl;
  this->loadBackground();
  this->loadButtons();
}

void Options::loadBackground()
{
}

void Options::loadButtons()
{
}

void Options::drawBackground(gdl::Clock& clock, gdl::BasicShader& shader)
{
  (void) clock;
  (void) shader;
}

void Options::drawButtons(gdl::Clock& clock, gdl::BasicShader& shader)
{
  (void) clock;
  (void) shader;
}

void Options::draw(gdl::Clock& clock, gdl::BasicShader& shader)
{
  this->drawButtons(clock, shader);
  this->drawBackground(clock, shader);
}

bool Options::update(gdl::Clock& shader, gdl::Input& input)
{
  (void) shader;
  if (input.getInput(SDLK_BACKSPACE) == true)
    {
      _game->popState();
    }
  return true;
}

Options::~Options()
{}
