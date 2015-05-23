//
// SelectChar.cpp for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat May 16 15:18:59 2015 Nicolas Charvoz
// Last update Sat May 23 17:01:01 2015 Nicolas Charvoz
//

#include "SelectChar.hh"
#include "SousMenuButton.hh"
#include "MenuBackground.hh"
#include <OpenGL.hh>
#include <iostream>
#include <Texture.hh>

TextureManager &SelectChar::_texManag = TextureManager::getInstance();

SelectChar::SelectChar(Game *game)
{
  _game = game;
  std::cout << "Je suis dans SelectChar" << std::endl;
  _texManag.registerTexture("backgroundSelectChar", "back");
  _texManag.registerTexture("PlaySousMenu", "playSM");
  this->loadBackground();
  this->loadButtons();
}

void SelectChar::loadBackground()
{
  AObject *background = new MenuBackground();

  background->initialize(_texManag.getTexture("back"));
  _background = background;
}

void SelectChar::loadButtons()
{
  AObject *play = new SousMenuButton();

  play->initialize(_texManag.getTexture("playSM"));

  glm::vec3 trans(-0.6, -0.38, 0);
  play->translate(trans);

  _buttons.push_back(play);
}

void SelectChar::drawBackground(gdl::Clock& clock, gdl::BasicShader& shader)
{
  _background->draw(shader, clock);
}

void SelectChar::drawButtons(gdl::Clock& clock, gdl::BasicShader& shader)
{
  for (size_t i = 0; i < _buttons.size() ; ++i)
    _buttons[i]->draw(shader, clock);
}

void SelectChar::draw(gdl::Clock& clock, gdl::BasicShader& shader)
{
  this->drawButtons(clock, shader);
  this->drawBackground(clock, shader);

  AObject *model = new ModelLoad();

  model->initialize(_texManag.getTexture("back"));
  model->draw(shader, clock);
}

bool SelectChar::update(gdl::Clock& shader, gdl::Input& input)
{
  (void) shader;
  if (input.getInput(SDLK_BACKSPACE) == true)
    {
      _game->popState();
    }
  return true;
}

SelectChar::~SelectChar()
{}
