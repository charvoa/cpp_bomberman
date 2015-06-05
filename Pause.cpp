//
// Pause.cpp for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat May 16 15:18:59 2015 Nicolas Charvoz
// Last update Fri Jun  5 11:52:28 2015 Nicolas Charvoz
//

#include "Pause.hh"
#include "SousMenuButton.hh"
#include "MenuBackground.hh"
#include "SaveGame.hh"
#include <OpenGL.hh>
#include <iostream>
#include <Texture.hh>

TextureManager &Pause::_texManag = TextureManager::getInstance();

Pause::Pause(Game *game, World *world)
{
  _game = game;
  _world = world;
  std::cout << "Je suis dans Pause" << std::endl;
  _texManag.registerTexture("backgroundPause", "backPause");
  this->loadBackground();
  this->loadButtons();
  glViewport(0, 0, 1920, 1080);
  _game->_camera->move(glm::vec3(0, 900, 0), glm::vec3(0, 0, -750));
  _game->getShader().bind();
  _game->getShader().setUniform("view", _game->_camera->getTransformation());
  _game->getShader().setUniform("projection", _game->_camera->getProjection());
  _inputManager = new InputManager();
  _command = new Command(_game, NULL, "PAUSE");
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

   std::cout << "X : " << mouse.x << " Y : " << mouse.y << std::endl;

   if (mouse.x >= 812 && mouse.x <= 1166 && mouse.y >= 337 && mouse.y <= 427)
     _game->popState();
   else if (mouse.x >= 812 && mouse.x <= 1166 && mouse.y >= 483
	    && mouse.y <= 569)
     {
       std::cout << "PAUSE : " << _world->getMapName() << std::endl;
       SaveGame(*_world, _world->getMapName());
     }
   else if (mouse.x >= 812 && mouse.x <= 1166 && mouse.y >= 627
	    && mouse.y <= 723)
     {
       _game->pushState(new Exit(_game));
     }
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
