//
// Leaderboard.cpp for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat May 16 15:18:59 2015 Nicolas Charvoz
// Last update Thu Jun  4 16:25:01 2015 Nicolas Charvoz
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
  this->loadBackground();
  this->loadButtons();
  this->loadLetters();
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
      _letters[ss.str()] = letter;
    }
  for (char c = '0'; c <= '9'; ++c)
    {
      ss.str("");
      ss.clear();
      ss << "fonts/" << c;
      letter = new Letters();
      _texManag.registerTexture(ss.str(), ss.str());
      letter->initialize(_texManag.getTexture(ss.str()));
      _letters[ss.str()] = letter;
    }
  this->buildScore();
}

std::vector<std::string> &Leaderboard::split2(const std::string &s, char delim, std::vector<std::string> &elems) {
  std::stringstream ss(s);
  std::string item;
  while (std::getline(ss, item, delim))
    {
      elems.push_back(item);
    }
  return elems;
}

void Leaderboard::handleWords(std::vector<std::string> &words)
{
  static int i = 0;
  static int y = 20;

  for (std::vector<std::string>::iterator it = words.begin();
       it != words.end(); ++it)
    {
      if (i % 2 == 0)
	{
	  this->buildWord(*it, 70, y);
	}
      else if (i % 2 != 0)
	{
	  this->buildWord(*it, -60, y);
	  y -= 12;
	}
      i++;
    }
}

std::vector<std::string> Leaderboard::splitWord(const std::string &s, char delim) {
  std::vector<std::string> elems;
  this->split2(s, delim, elems);
  return elems;
}

void Leaderboard::buildScore()
{
  std::cout << "buildScore() >> " << std::endl;
  std::vector<std::string> elems;

  for (std::vector<std::string>::iterator it = _bestScore.begin();
       it != _bestScore.end() ; ++it)
    {
      elems.clear();
      std::transform((*it).begin(), (*it).end(), (*it).begin(), ::toupper);
      elems = this->splitWord(*it, ' ');
      this->handleWords(elems);
    }
}

void Leaderboard::loadButtons()
{
}

void Leaderboard::getScore()
{
  std::stringstream ss;
  typedef std::multimap<std::string, std::string> multimap_type;
  typedef std::reverse_iterator<multimap_type::iterator> reverse_iterator;

  for (auto it = _scores.rbegin(),
	 end = _scores.rend();
       it != end;
       it = reverse_iterator(_scores.lower_bound(it->first)))
    {
      ss.str("");
      ss.clear();
      ss << (*it).second << ' ' << (*it).first;
      _bestScore.push_back(ss.str());
    }
}

void Leaderboard::buildWord(const std::string &str, int x, int y)
{
  int i = 0;
  AObject* letter;
  std::stringstream ss;

  _word.clear();
  while (str[i])
    {
      ss.str("");
      ss.clear();
      ss << "fonts/";
      ss << str[i];
      letter = new Letters();
      letter->initialize(_texManag.getTexture(ss.str()));
      letter->translate(glm::vec3(-0.06 * (i + 1) + x * 0.01,
				  0 + y * 0.01, 0));
      _word.push_back(letter);
      i++;
    }
  _words.push_back(_word);
}

void Leaderboard::drawLetters(gdl::Clock& clock, gdl::BasicShader& shader)
{
  for (size_t i = 0; i < _word.size() ; ++i)
    {
      _word[i]->draw(shader, clock);
    }
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

void Leaderboard::drawScore(gdl::Clock& clock, gdl::BasicShader& shader)
{
  for (size_t i = 0; i < _words.size() ; ++i)
    {
      size_t innerSize = _words[i].size();
      for (size_t j = 0; j < innerSize ; ++j)
	{
	  _words[i][j]->draw(shader, clock);
	}
    }
}

void Leaderboard::draw(gdl::Clock& clock, gdl::BasicShader& shader)
{
  this->drawLetters(clock, shader);
  this->drawButtons(clock, shader);
  this->drawBackground(clock, shader);
  this->drawScore(clock, shader);
}

bool Leaderboard::update(gdl::Clock& clock, gdl::Input& input)
{
  _command->exec(_inputManager->getTouche(input), clock);
  return true;
}

Leaderboard::~Leaderboard()
{}
