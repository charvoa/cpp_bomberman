//
// SelectChar.cpp for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat May 16 15:18:59 2015 Nicolas Charvoz
// Last update Thu Jun  4 16:06:32 2015 Audibert Louis
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
  _map1 = true;
  _map2 = false;
  _map3 = false;
  _map4 = false;
  _map5 = false;
  _mapR = false;
  _p1 = true;
  _p2 = false;
  _ia1 = true;
  _ia5 = false;
  _ia10 = false;
  _ia15 = false;
  _ia20 = false;
}

void SelectChar::loadBackground()
{
  AObject *background = new MenuBackground();

  background->initialize(_texManag.getTexture("back"));
  _background = background;
}

void SelectChar::loadButtons()
{
  _texManag.registerTexture("5IA", "5IA");
  _texManag.registerTexture("10IA", "10IA");
  _texManag.registerTexture("15IA", "15IA");
  _texManag.registerTexture("20IA", "20IA");
  _texManag.registerTexture("1Player", "1P");
  _texManag.registerTexture("2Player", "2P");
  _texManag.registerTexture("ONEIA", "ONEIA");
  _texManag.registerTexture("SC_Map1", "Map1");
  _texManag.registerTexture("SC_Map2", "Map2");
  _texManag.registerTexture("SC_Map3", "Map3");
  _texManag.registerTexture("SC_Map4", "Map4");
  _texManag.registerTexture("SC_Map5", "Map5");
  _texManag.registerTexture("SC_Map6", "Map6");

  AObject *b = new DisplayButton();

  b->initialize(_texManag.getTexture("10IA"));
  b->translate(glm::vec3(0, -0.39, 0));
  _buttons["10IA"] = b;

  b = new DisplayButton();
  b->initialize(_texManag.getTexture("5IA"));
  _buttons["5IA"] = b;

  b = new DisplayButton();
  b->initialize(_texManag.getTexture("15IA"));
  _buttons["15IA"] = b;

  b = new DisplayButton();
  b->initialize(_texManag.getTexture("20IA"));
  _buttons["20IA"] = b;

  b = new DisplayButton();
  b->initialize(_texManag.getTexture("1P"));
  b->translate(glm::vec3(0.4, -0.39, 0));
  _buttons["1P"] = b;

  b = new DisplayButton();
  b->initialize(_texManag.getTexture("2P"));
  b->translate(glm::vec3(0.4, -0.39, 0));
  _buttons["2P"] = b;

  b = new DisplayButton();
  b->initialize(_texManag.getTexture("ONEIA"));
  b->translate(glm::vec3(0, -0.39, 0));
  _buttons["ONEIA"] = b;

  b = new DisplayButton();
  b->initialize(_texManag.getTexture("Map1"));
  b->translate(glm::vec3(-0.42, -0.39, 0));
  _buttons["Map1"] = b;

  b = new DisplayButton();
  b->initialize(_texManag.getTexture("Map2"));
  _buttons["Map2"] = b;

  b = new DisplayButton();
  b->initialize(_texManag.getTexture("Map3"));
  _buttons["Map3"] = b;

  b = new DisplayButton();
  b->initialize(_texManag.getTexture("Map4"));
  _buttons["Map4"] = b;

  b = new DisplayButton();
  b->initialize(_texManag.getTexture("Map5"));
  _buttons["Map5"] = b;

  b = new DisplayButton();
  b->initialize(_texManag.getTexture("Map6"));
  _buttons["Map6"] = b;
}

void SelectChar::drawBackground(gdl::Clock& clock, gdl::BasicShader& shader)
{
  _background->draw(shader, clock);
}

void SelectChar::drawButtons(gdl::Clock& clock, gdl::BasicShader& shader)
{
  (void) clock;
  (void) shader;
}

void SelectChar::getNameOfButton(gdl::Input &input)
{
  glm::ivec2 mouse = input.getMousePosition();

  std::cout << "X : " << mouse.x << " Y: " << mouse.y << std::endl;
  if (mouse.x >= 328 && mouse.x <= 730 && mouse.y >= 77 && mouse.y <= 473)
    {
      // MAP 1
      _map = new Map("./maps/basic.map");
      _map1 = true;
    }
  if (mouse.x >= 760 && mouse.x <= 1160 && mouse.y >= 77 && mouse.y <= 473)
    {
      // MAP 2
      _map = new Map("./maps/hard.map");
      _map2 = true;
    }
  if (mouse.x >= 1192 && mouse.x <= 1594 && mouse.y >= 77 && mouse.y <= 473)
    {
      // MAP 3
      _map = new Map("./maps/big.map");
      _map3 = true;
    }
  if (mouse.x >= 330 && mouse.x <= 730 && mouse.y >= 501 && mouse.y <= 899)
    {
      // MAP 4
      _map = new Map("./maps/+.map");
      _map4 = true;
    }
  if (mouse.x >= 760 && mouse.x <= 1158 && mouse.y >= 501 && mouse.y <= 899)
    {
      // MAP 5
      _map = new Map("./maps/x.map");
      _map5 = true;
    }
  if (mouse.x >= 1192 && mouse.x <= 1592 && mouse.y >= 501 && mouse.y <= 899)
    {
      // RANDOM
      _map = new Map("./maps/lp.map");
      _mapR = true;
    }
  if (mouse.x >= 1566 && mouse.x <= 1906 && mouse.y >= 949 && mouse.y <= 1039)
    {
      // BOUTON PLAY
      _game->pushState(new World(_game, *_map, 2, 10));
    }

}

void SelectChar::drawDisplayButton(gdl::Clock& clock, gdl::BasicShader& shader)
{

  if (_p1)
    {
      _buttons["1P"]->draw(shader, clock);
    }
  if (_map1)
    {
      _buttons["Map1"]->draw(shader, clock);
    }
  else if (_map2)
    {
      _buttons["Map2"]->draw(shader, clock);
    }
  else if (_map3)
    {
      _buttons["Map3"]->draw(shader, clock);
    }
  else if (_map4)
    {
      _buttons["Map4"]->draw(shader, clock);
    }
  else if (_map5)
    {
      _buttons["Map5"]->draw(shader, clock);
    }
  else if (_mapR)
    {
      _buttons["Map6"]->draw(shader, clock);
    }
  if (_ia1)
    {
      _buttons["ONEIA"]->draw(shader, clock);
    }
  else if (_ia5)
    {
      _buttons["5IA"]->draw(shader, clock);
    }
 else if (_ia10)
    {
      _buttons["10IA"]->draw(shader, clock);
    }
 else if (_ia15)
    {
      _buttons["15IA"]->draw(shader, clock);
    }
 else if (_ia20)
    {
      _buttons["20IA"]->draw(shader, clock);
    }
}

void SelectChar::draw(gdl::Clock& clock, gdl::BasicShader& shader)
{
  this->drawButtons(clock, shader);
  this->drawBackground(clock, shader);
  this->drawDisplayButton(clock, shader);
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
