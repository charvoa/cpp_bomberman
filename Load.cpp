//
// Load.cpp for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat May 16 15:18:59 2015 Nicolas Charvoz
// Last update Sat May 23 12:12:23 2015 Nicolas Charvoz
//

#include "Load.hh"
#include <OpenGL.hh>
#include <iostream>
#include <Texture.hh>

Load::Load(Game *game)
{
  _game = game;
  std::cout << "Je suis dans Load" << std::endl;
  this->loadBackground();
  this->loadButtons();
}

void Load::loadBackground()
{
}

void Load::loadButtons()
{
}

void Load::drawBackground(gdl::Clock& clock, gdl::BasicShader& shader)
{
  (void) clock;
  (void) shader;
}

void Load::drawButtons(gdl::Clock& clock, gdl::BasicShader& shader)
{
  (void) clock;
  (void) shader;
}

void Load::draw(gdl::Clock& clock, gdl::BasicShader& shader)
{
  this->drawButtons(clock, shader);
  this->drawBackground(clock, shader);
}

bool Load::update(gdl::Clock& shader, gdl::Input& input)
{
  (void) shader;
  if (input.getInput(SDLK_BACKSPACE) == true)
    {
      _game->popState();
    }
  return true;
}

Load::~Load()
{}
