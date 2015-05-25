//
// SelectChar.cpp for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat May 16 15:18:59 2015 Nicolas Charvoz
// Last update Mon May 25 17:52:04 2015 Nicolas Charvoz
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
  this->loadModel();
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

void SelectChar::loadModel()
{
  _model = new ModelLoad();

  _model->initialize(_texManag.getTexture("back"));

  glm::vec3 trans(0, -200, 800);
  _model->translate(trans);

  trans = glm::vec3(0.5, 0.5, 0.5);
  _model->scale(trans);

}

void SelectChar::drawModel(gdl::Clock& clock, gdl::BasicShader& shader)
{
  _model->draw(shader, clock);
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
  this->drawModel(clock, shader);
  this->drawBackground(clock, shader);
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
