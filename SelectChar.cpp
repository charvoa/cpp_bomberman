//
// SelectChar.cpp for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat May 16 15:18:59 2015 Nicolas Charvoz
// Last update Tue Jun  2 14:21:22 2015 Nicolas Charvoz
//

#include "SelectChar.hh"
#include "SousMenuButton.hh"
#include "MenuBackground.hh"
#include "RandomMenu.hh"
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
  _texManag.registerTexture("ONEIA", "1ia");
  _texManag.registerTexture("5IA", "5ia");
  _texManag.registerTexture("10IA", "10ia");
  _texManag.registerTexture("15IA", "15ia");
  _texManag.registerTexture("20IA", "20ia");
  _texManag.registerTexture("1Player", "1P");
  _texManag.registerTexture("2Player", "2P");
  _texManag.registerTexture("SC_Map1", "Map1");
  _texManag.registerTexture("SC_Map2", "Map2");
  _texManag.registerTexture("SC_Map3", "Map3");
  _texManag.registerTexture("SC_Map4", "Map4");
  _texManag.registerTexture("SC_Map5", "Map5");
  _texManag.registerTexture("SC_Map6", "Map6");

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
  _nbrIA = 1;
}

void SelectChar::loadBackground()
{
  AObject *background = new MenuBackground();

  background->initialize(_texManag.getTexture("back"));
  _background = background;
}

void SelectChar::loadButtons()
{
  AObject *b = new DisplayButton();

  b = new DisplayButton();
  b->initialize(_texManag.getTexture("1ia"));
  b->translate(glm::vec3(0, -0.39, 0));
  _buttons["1ia"] = b;

  b = new DisplayButton();
  b->initialize(_texManag.getTexture("5ia"));
  b->translate(glm::vec3(0, -0.39, 0));
  _buttons["5ia"] = b;

  b = new DisplayButton();
  b->initialize(_texManag.getTexture("10ia"));
  b->translate(glm::vec3(0, -0.39, 0));
  _buttons["10ia"] = b;

  b = new DisplayButton();
  b->initialize(_texManag.getTexture("15ia"));
  b->translate(glm::vec3(0, -0.39, 0));
  _buttons["15ia"] = b;

  b = new DisplayButton();
  b->initialize(_texManag.getTexture("20ia"));
  b->translate(glm::vec3(0, -0.39, 0));
  _buttons["20ia"] = b;

  b = new DisplayButton();
  b->initialize(_texManag.getTexture("1P"));
  b->translate(glm::vec3(0.4, -0.39, 0));
  _buttons["1P"] = b;

  b = new DisplayButton();
  b->initialize(_texManag.getTexture("2P"));
  b->translate(glm::vec3(0.4, -0.39, 0));
  _buttons["2P"] = b;

  b = new DisplayButton();
  b->initialize(_texManag.getTexture("Map1"));
  b->translate(glm::vec3(-0.42, -0.39, 0));
  _buttons["Map1"] = b;

  b = new DisplayButton();
  b->initialize(_texManag.getTexture("Map2"));
  b->translate(glm::vec3(-0.42, -0.39, 0));
  _buttons["Map2"] = b;

  b = new DisplayButton();
  b->initialize(_texManag.getTexture("Map3"));
  b->translate(glm::vec3(-0.42, -0.39, 0));
  _buttons["Map3"] = b;

  b = new DisplayButton();
  b->initialize(_texManag.getTexture("Map4"));
  b->translate(glm::vec3(-0.42, -0.39, 0));
  _buttons["Map4"] = b;

  b = new DisplayButton();
  b->initialize(_texManag.getTexture("Map5"));
  b->translate(glm::vec3(-0.42, -0.39, 0));
  _buttons["Map5"] = b;

  b = new DisplayButton();
  b->initialize(_texManag.getTexture("Map6"));
  b->translate(glm::vec3(-0.42, -0.39, 0));
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
      _map1 = _map2 = _map3 = _map4 = _map5 = _mapR = false;
      _map1 = true;
    }
  if (mouse.x >= 760 && mouse.x <= 1160 && mouse.y >= 77 && mouse.y <= 473)
    {
      // MAP 2
      _map = new Map("./maps/hard.map");
      _map1 = _map2 = _map3 = _map4 = _map5 = _mapR = false;
      _map2 = true;
    }
  if (mouse.x >= 1192 && mouse.x <= 1594 && mouse.y >= 77 && mouse.y <= 473)
    {
      // MAP 3
      _map = new Map("./maps/big.map");
      _map1 = _map2 = _map3 = _map4 = _map5 = _mapR = false;
      _map3 = true;
    }
  if (mouse.x >= 330 && mouse.x <= 730 && mouse.y >= 501 && mouse.y <= 899)
    {
      // MAP 4
      _map = new Map("./maps/+.map");
      _map1 = _map2 = _map3 = _map4 = _map5 = _mapR = false;
      _map4 = true;
    }
  if (mouse.x >= 760 && mouse.x <= 1158 && mouse.y >= 501 && mouse.y <= 899)
    {
      // MAP 5
      _map = new Map("./maps/x.map");
      _map1 = _map2 = _map3 = _map4 = _map5 = _mapR = false;
      _map5 = true;
    }
  if (mouse.x >= 1192 && mouse.x <= 1592 && mouse.y >= 501 && mouse.y <= 899)
    {
      // RANDOM
      //      _map = new Map("./maps/lp.map");
      //_mapR = true;
      _game->pushState(new RandomMenu(_game));
    }
  //PLAY
  if (mouse.x >= 1566 && mouse.x <= 1906 && mouse.y >= 949 && mouse.y <= 1039)
    {
      // BOUTON PLAY
      if (_p2)
	_game->pushState(new World(_game, *_map, 2, _nbrIA));
      else
	_game->pushState(new World(_game, *_map, 1, _nbrIA));
    }
  //PLAYER
  if (mouse.x >= 86 && mouse.x <= 212 && mouse.y >= 307 && mouse.y <= 431)
    {
      //BOUTON 1 PLAYER
      _p1 = true;
      _p2 = false;
    }
  if (mouse.x >= 86 && mouse.x <= 212 && mouse.y >= 615 && mouse.y <= 741)
    {
      //BOUTON 2 PLAYER
      _p1 = false;
      _p2 = true;
    }
  //IA
  if (mouse.x >= 1700 && mouse.x <= 1830 && mouse.y >= 140 && mouse.y <= 275)
    {
      // IA 1
      _ia1 = _ia5 = _ia10 = _ia15 = _ia20 = false;
      _ia1 = true;
      _nbrIA = 1;
    }
  else if (mouse.x >= 1700 && mouse.x <= 1830 && mouse.y >= 309
	   && mouse.y <= 433)
    {
      // IA 5
      _ia1 = _ia5 = _ia10 = _ia15 = _ia20 = false;
      _ia5 = true;
      _nbrIA = 5;
    }
  else if (mouse.x >= 1700 && mouse.x <= 1828 && mouse.y >= 471
	   && mouse.y <= 593)
    {
      // IA 10
      _ia1 = _ia5 = _ia10 = _ia15 = _ia20 = false;
      _ia10 = true;
      _nbrIA = 10;
    }
  else if (mouse.x >= 1700 && mouse.x <= 1828 && mouse.y >= 633
	   && mouse.y <= 753)
    {
      // IA 15
      _ia1 = _ia5 = _ia10 = _ia15 = _ia20 = false;
      _ia15 = true;
      _nbrIA = 15;
    }
  else if (mouse.x >= 1700 && mouse.x <= 1828 && mouse.y >= 799
	   && mouse.y <= 919)
    {
      // IA 20
      _ia1 = _ia5 = _ia10 = _ia15 = _ia20 = false;
      _ia20 = true;
      _nbrIA = 20;
    }
}

  //PLAYER

void SelectChar::drawDisplayButton(gdl::Clock& clock, gdl::BasicShader& shader)
{
  if (_p1)
    {
      _buttons["1P"]->draw(shader, clock);
    }
  else if (_p2)
    {
      _buttons["2P"]->draw(shader, clock);
    }
}

// MAP
void SelectChar::drawDisplayMap(gdl::Clock& clock, gdl::BasicShader& shader)
{
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
}

// IA
void SelectChar::drawDisplayIA(gdl::Clock& clock, gdl::BasicShader& shader)
{
  if (_ia1)
    {
      _buttons["1ia"]->draw(shader, clock);
    }
  else if (_ia5)
    {
      _buttons["5ia"]->draw(shader, clock);
    }
  else if (_ia10)
    {
      _buttons["10ia"]->draw(shader, clock);
    }
  else if (_ia15)
    {
      _buttons["15ia"]->draw(shader, clock);
    }
  else if (_ia20)
    {
      _buttons["20ia"]->draw(shader, clock);
    }
}

void SelectChar::draw(gdl::Clock& clock, gdl::BasicShader& shader)
{
  this->drawButtons(clock, shader);
  this->drawBackground(clock, shader);
  this->drawDisplayButton(clock, shader);
  this->drawDisplayIA(clock, shader);
  this->drawDisplayMap(clock, shader);
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
