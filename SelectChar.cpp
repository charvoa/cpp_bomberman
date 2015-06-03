//
// SelectChar.cpp for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat May 16 15:18:59 2015 Nicolas Charvoz
// Last update Wed Jun  3 14:51:54 2015 Antoine Garcia
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
  _game->_camera->move(glm::vec3(0, 0, -0.0001), glm::vec3(0, 0, 0));
  gdl::BasicShader shader = _game->getShader();
  shader.bind();
  shader.setUniform("view", _game->_camera->getTransformation());
  shader.setUniform("projection", _game->_camera->getProjection());
  _inputManager = new InputManager();
  _command = new Command(_game, NULL, "SELECTCHAR");
  _map = new Map("./maps/basic.map");
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

  glm::vec3 trans(-0.6, -0.40, 0);
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

void SelectChar::getNameOfButton(gdl::Input &input)
{
  glm::ivec2 mouse = input.getMousePosition();

  std::cout << "X : " << mouse.x << " Y: " << mouse.y << std::endl;
  if (mouse.x >= 328 && mouse.x <= 730 && mouse.y >= 77 && mouse.y <= 473)
    {
      // MAP 1
      _map = new Map("./maps/basic.map");
    }
  if (mouse.x >= 760 && mouse.x <= 1160 && mouse.y >= 77 && mouse.y <= 473)
    {
      // MAP 2
      _map = new Map("./maps/hard.map");
    }
  if (mouse.x >= 1192 && mouse.x <= 1594 && mouse.y >= 77 && mouse.y <= 473)
    {
      // MAP 3
      _map = new Map("./maps/big.map");
    }
  if (mouse.x >= 330 && mouse.x <= 730 && mouse.y >= 501 && mouse.y <= 899)
    {
      // MAP 4
      _map = new Map("./maps/+.map");
    }
  if (mouse.x >= 760 && mouse.x <= 1158 && mouse.y >= 501 && mouse.y <= 899)
    {
      // MAP 5
      _map = new Map("./maps/x.map");
    }
  if (mouse.x >= 1192 && mouse.x <= 1592 && mouse.y >= 501 && mouse.y <= 899)
    {
      // RANDOM
      _map = new Map("./maps/lp.map");
    }
  if (mouse.x >= 1394 && mouse.x <= 1820 && mouse.y >= 919 && mouse.y <= 1025)
    {
      // BOUTON PLAY
      _game->pushState(new World(_game, *_map, 1, 10));
    }

}

void SelectChar::draw(gdl::Clock& clock, gdl::BasicShader& shader)
{
  this->drawButtons(clock, shader);
  this->drawBackground(clock, shader);
}

bool SelectChar::update(gdl::Clock& clock, gdl::Input& input)
{
  _command->exec(_inputManager->getTouche(input), clock);
  if (input.getInput(SDL_BUTTON_LEFT, true) == true)
    this->getNameOfButton(input);
  return true;
}

SelectChar::~SelectChar()
{}
