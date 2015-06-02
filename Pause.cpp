//
// Pause.cpp for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat May 16 15:18:59 2015 Nicolas Charvoz
// Last update Mon Jun  1 19:39:42 2015 Nicolas Charvoz
//

#include "Pause.hh"
#include "SousMenuButton.hh"
#include "MenuBackground.hh"
#include <OpenGL.hh>
#include <iostream>
#include <Texture.hh>

TextureManager &Pause::_texManag = TextureManager::getInstance();

Pause::Pause(Game *game)
{
  _game = game;
  std::cout << "Je suis dans Pause" << std::endl;
  _texManag.registerTexture("backgroundPause", "backPause");
  this->loadBackground();
  this->loadButtons();
  // _game->_camera->move(glm::vec3(0, 0, -0.0001), glm::vec3(0, 0, 0));
  // gdl::BasicShader shader = _game->getShader();
  // shader.bind();
  // shader.setUniform("view", _game->_camera->getTransformation());
  // shader.setUniform("projection", _game->_camera->getProjection());
  _inputManager = new InputManager();
  _command = new Command(_game, NULL, true);
}

void Pause::loadBackground()
{
  AObject *background = new GameBackground();

  background->initialize(_texManag.getTexture("backPause"));
  _background = background;
}

void Pause::loadButtons()
{
}

void Pause::drawBackground(gdl::Clock& clock, gdl::BasicShader& shader)
{
  _background->draw(shader, clock);
}

void Pause::drawButtons(gdl::Clock& clock, gdl::BasicShader& shader)
{
  (void) clock;
  (void) shader;
}

void Pause::getNameOfButton(gdl::Input &input)
{
  glm::ivec2 mouse = input.getMousePosition();
}

void Pause::draw(gdl::Clock& clock, gdl::BasicShader& shader)
{
  this->drawButtons(clock, shader);
  this->drawBackground(clock, shader);
}

bool Pause::update(gdl::Clock& clock, gdl::Input& input)
{
  _command->exec(_inputManager->getTouche(input), clock);
  if (input.getInput(SDL_BUTTON_LEFT, true) == true)
    this->getNameOfButton(input);
  return true;
}

Pause::~Pause()
{}
