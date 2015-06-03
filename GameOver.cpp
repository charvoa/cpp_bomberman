//
// GameOver.cpp for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat May 16 15:18:59 2015 Nicolas Charvoz
// Last update Wed Jun  3 22:13:17 2015 Nicolas Charvoz
//

#include "GameOver.hh"
#include "SousMenuButton.hh"
#include "MenuBackground.hh"
#include "RandomMenu.hh"
#include <OpenGL.hh>
#include <iostream>
#include <Texture.hh>

TextureManager &GameOver::_texManag = TextureManager::getInstance();
Sound &GameOver::_sound = Sound::getInstance();

GameOver::GameOver(Game *game, int player)
{
  _game = game;
  std::cout << "Je suis dans GameOver" << std::endl;
  _player = player;
  _sound.registerSound("./reources/sounds/terrorist_win_effect.wav",
		       "terr_win");
  _sound.registerSound("./reources/sounds/credit.mp3",
		       "army_win");
  _texManag.registerTexture("GameOverIA", "GoIA");
  _texManag.registerTexture("GameOverPlayer1", "Go1");
  _texManag.registerTexture("GameOverPlayer2", "Go2");
  _texManag.registerTexture("GameOverOri", "GoOri");
  this->loadBackground();
  this->loadButtons();
  _game->_camera->move(glm::vec3(0, 0, -0.0001), glm::vec3(0, 0, 0));
  gdl::BasicShader shader = _game->getShader();
  shader.bind();
  shader.setUniform("view", _game->_camera->getTransformation());
  shader.setUniform("projection", _game->_camera->getProjection());
  _inputManager = new InputManager();
  _command = new Command(_game, NULL, "GAMEOVER");
}

void GameOver::loadBackground()
{
  AObject *background = new MenuBackground();

  if (_player == 0)
    {
      _sound.playMusic("terr_win");
      background->initialize(_texManag.getTexture("GoIA"));
    }
  else if (_player == 1)
    {
      _sound.playMusic("terr_win");
      background->initialize(_texManag.getTexture("Go1"));
    }
  else if (_player == 2)
    {
      _sound.playMusic("usa_win");
      background->initialize(_texManag.getTexture("Go2"));
    }
  else
    background->initialize(_texManag.getTexture("GoOri"));
  _background = background;
}

void GameOver::loadButtons()
{
}

void GameOver::drawBackground(gdl::Clock& clock, gdl::BasicShader& shader)
{
  _background->draw(shader, clock);
}

void GameOver::drawButtons(gdl::Clock& clock, gdl::BasicShader& shader)
{
  (void) clock;
  (void) shader;
}

void GameOver::getNameOfButton(gdl::Input &input)
{
  glm::ivec2 mouse = input.getMousePosition();

  std::cout << "X : " << mouse.x << " Y: " << mouse.y << std::endl;
}

void GameOver::draw(gdl::Clock& clock, gdl::BasicShader& shader)
{
  this->drawButtons(clock, shader);
  this->drawBackground(clock, shader);
}

bool GameOver::update(gdl::Clock& clock, gdl::Input& input)
{
  _command->exec(_inputManager->getTouche(input), clock);
  if (input.getInput(SDL_BUTTON_LEFT, true) == true)
    this->getNameOfButton(input);
  return true;
}

GameOver::~GameOver()
{}
