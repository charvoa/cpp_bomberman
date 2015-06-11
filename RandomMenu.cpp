//
// RandomMenu.cpp for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat May 16 15:18:59 2015 Nicolas Charvoz
// Last update Thu Jun  4 16:17:20 2015 Nicolas Charvoz
//

#include "RandomMenu.hh"
#include <OpenGL.hh>
#include <iostream>
#include <Texture.hh>

TextureManager &RandomMenu::_texManag = TextureManager::getInstance();

RandomMenu::RandomMenu(Game *game)
{
  _game = game;
  std::cout << "Je suis dans RandomMenu" << std::endl;
  _texManag.registerTexture("backgroundRandom", "backRM");
  this->loadBackground();
  this->loadButtons();
  _inputManager = new InputManager();
  _command = new Command(_game);

}

void RandomMenu::loadLetters()
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
}

void RandomMenu::displayIA(int nb)
{
  std::cout << "IA NB : " << nb << std::endl;
}

void RandomMenu::displayX(int nb)
{
  std::cout << "X MAP : " << nb << std::endl;
}

void RandomMenu::displayY(int nb)
{
  std::cout << "Y MAP : " << nb << std::endl;
}

void RandomMenu::loadBackground()
{
  AObject *background = new MenuBackground();

  background->initialize(_texManag.getTexture("backRM"));
  _background = background;
}

void RandomMenu::loadButtons()
{
}

void RandomMenu::drawBackground(gdl::Clock& clock, gdl::BasicShader& shader)
{
  _background->draw(shader, clock);
}

void RandomMenu::drawButtons(gdl::Clock& clock, gdl::BasicShader& shader)
{
  (void) shader;
  (void) clock;
}

void RandomMenu::draw(gdl::Clock& clock, gdl::BasicShader& shader)
{
  this->drawButtons(clock, shader);
  this->drawBackground(clock, shader);
}

void RandomMenu::getNameOfButton(gdl::Input &input)
{
  glm::ivec2 mouse = input.getMousePosition();
  std::cout << "X : " << mouse.x << "Y : " << std::endl;

  (void) mouse;
}

bool RandomMenu::update(gdl::Clock& clock, gdl::Input& input)
{
  _command->exec(_inputManager->getTouche(input), clock);
  if (input.getInput(SDL_BUTTON_LEFT, true) == true)
    this->getNameOfButton(input);
  return true;
}

RandomMenu::~RandomMenu()
{}
