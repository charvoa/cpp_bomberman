//
// Leaderboard.cpp for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat May 16 15:18:59 2015 Nicolas Charvoz
// Last update Tue Jun  2 14:55:42 2015 Nicolas Charvoz
//

#include "Leaderboard.hh"
#include "SousMenuButton.hh"
#include "MenuBackground.hh"
#include "Letters.hh"
#include <OpenGL.hh>
#include <iostream>
#include <Texture.hh>

TextureManager &Leaderboard::_texManag = TextureManager::getInstance();

Leaderboard::Leaderboard(Game *game)
{
  _game = game;
  std::cout << "Je suis dans Leaderboard" << std::endl;
  _texManag.registerTexture("LeaderBoardMenu", "lbMenu");
  this->loadBackground();
  this->loadButtons();
  this->loadLetters();
  _game->_camera->move(glm::vec3(0, 0, -0.0001), glm::vec3(0, 0, 0));
  gdl::BasicShader shader = _game->getShader();

  shader.bind();
  shader.setUniform("view", _game->_camera->getTransformation());
  shader.setUniform("projection", _game->_camera->getProjection());

  _inputManager = new InputManager();
  _command = new Command(_game);
  Scoring scoring;
  _scores = scoring.highScore();
  this->getScore();
}

void Leaderboard::loadBackground()
{
  AObject *background = new MenuBackground();

  background->initialize(_texManag.getTexture("lbMenu"));
  _background = background;
}

void Leaderboard::loadLetters()
{
  AObject *letter = new Letters();
  std::stringstream ss;

  for (char c = 'A'; c <= 'Z'; ++c)
    {
      ss.str("");
      ss.clear();
      ss << "fonts/" << c;
      letter = new Letters();
      _texManag.registerTexture(ss.str(), ss.str());
      letter->initialize(_texManag.getTexture(ss.str()));
      std::cout << ss.str() << std::endl;
      _letters[ss.str()] = letter;
    }
}

void Leaderboard::loadButtons()
{
}

void Leaderboard::getScore()
{
  std::stringstream ss;

  std::multimap<std::string, std::string>::iterator it = _scores.begin();
  while (it != _scores.end())
    {
      ss.str("");
      ss.clear();
      ss << (*it).first << ' ' << (*it).second;
      _bestScore.push_back(ss.str());
      ++it;
    }
}

void Leaderboard::drawLetters(gdl::Clock& clock, gdl::BasicShader& shader)
{
  _letters["fonts/N"]->draw(shader, clock);
}

void Leaderboard::drawBackground(gdl::Clock& clock, gdl::BasicShader& shader)
{
  _background->draw(shader, clock);
}

void Leaderboard::drawButtons(gdl::Clock& clock, gdl::BasicShader& shader)
{
  (void) clock;
  (void) shader;
}

void Leaderboard::draw(gdl::Clock& clock, gdl::BasicShader& shader)
{
  this->drawLetters(clock, shader);
  this->drawButtons(clock, shader);
  this->drawBackground(clock, shader);
}

bool Leaderboard::update(gdl::Clock& clock, gdl::Input& input)
{
  (void) clock;

  _command->exec(_inputManager->getTouche(input), clock);

  return true;
}

Leaderboard::~Leaderboard()
{}
