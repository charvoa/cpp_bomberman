//
// RandomMenu.cpp for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat May 16 15:18:59 2015 Nicolas Charvoz
// Last update Fri Jun  5 13:27:39 2015 Nicolas Charvoz
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
  _inputManager = new InputManager();
  _command = new Command(_game);
  _x = 1;
  _y = 1;
  _ia = 1;
}

void RandomMenu::displayIA(int nb)
{
  std::stringstream ss;
  AObject* letter;
  int i = 0;
  int x = 16, y = 12;

  std::string s = std::to_string(nb);
  char const *nbStr = s.c_str();
  _iaNb.clear();
  while (nbStr[i])
    {
      ss.str("");
      ss.clear();
      ss << "./images/fonts/";
      ss << nbStr[i];
      ss << ".tga";
      std::cout << "ss : " << ss.str() << std::endl;
      letter = new Letters();
      letter->initialize(ss.str());
      letter->translate(glm::vec3(-0.06 * (i + 1) + x * 0.01,
				   0 + y * 0.01, 0));
      _iaNb.push_back(letter);
      i++;
    }
}

void RandomMenu::displayX(int nb)
{
  std::stringstream ss;
  AObject* letter;
  int i = 0;
  int x = 60, y = -15;

  std::string s = std::to_string(nb);
  char const *nbStr = s.c_str();
  _xMap.clear();
  while (nbStr[i])
    {
      ss.str("");
      ss.clear();
      ss << "./images/fonts/";
      ss << nbStr[i];
      ss << ".tga";
      std::cout << "ss : " << ss.str() << std::endl;
      letter = new Letters();
      letter->initialize(ss.str());
      letter->translate(glm::vec3(-0.06 * (i + 1) + x * 0.01,
				   0 + y * 0.01, 0));
      _xMap.push_back(letter);
      i++;
    }
}

void RandomMenu::displayY(int nb)
{
   std::stringstream ss;
  AObject* letter;
  int i = 0;
  int x = -30, y = -15;

  std::string s = std::to_string(nb);
  char const *nbStr = s.c_str();
  _yMap.clear();
  while (nbStr[i])
    {
      ss.str("");
      ss.clear();
      ss << "./images/fonts/";
      ss << nbStr[i];
      ss << ".tga";
      std::cout << "ss : " << ss.str() << std::endl;
      letter = new Letters();
      letter->initialize(ss.str());
      letter->translate(glm::vec3(-0.06 * (i + 1) + x * 0.01,
				   0 + y * 0.01, 0));
      _yMap.push_back(letter);
      i++;
    }
}

void RandomMenu::loadBackground()
{
  AObject *background = new MenuBackground();

  background->initialize(_texManag.getTexture("backRM"));
  _background = background;

  AObject *letter = new Letters();
  letter->initialize("./images/fonts/1.tga");
  letter->translate(glm::vec3(-0.06 * (0 + 1) + 16  * 0.01,
			      0 + 12 * 0.01, 0));
  _iaNb.push_back(letter);

  letter = new Letters();
  letter->initialize("./images/fonts/1.tga");
  letter->translate(glm::vec3(-0.06 * (0 + 1) + 60  * 0.01,
			      0 + -15 * 0.01, 0));
  _xMap.push_back(letter);

  letter = new Letters();
  letter->initialize("./images/fonts/1.tga");
  letter->translate(glm::vec3(-0.06 * (0 + 1) + -30  * 0.01,
			      0 + -15 * 0.01, 0));
  _yMap.push_back(letter);
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

  for (size_t i = 0; i < _iaNb.size() ; ++i)
    {
      _iaNb[i]->draw(shader, clock);
    }
  for (size_t i = 0; i < _xMap.size() ; ++i)
    {
      _xMap[i]->draw(shader, clock);
    }
  for (size_t i = 0; i < _yMap.size() ; ++i)
    {
      _yMap[i]->draw(shader, clock);
    }

}

void RandomMenu::getNameOfButton(gdl::Input &input)
{
  glm::ivec2 mouse = input.getMousePosition();
  std::cout << "X : " << mouse.x << " Y : " << mouse.y << std::endl;

  // IA
  if (mouse.x >= 670 && mouse.x <= 752 && mouse.y >= 345 && mouse.y <= 469)
    {
      std::cout << "IA -" << std::endl;
      if (_ia > 0)
	_ia--;
      else
	_ia = 0;
      this->displayIA(_ia);
    }
  else if (mouse.x >= 1178 && mouse.x <= 1254 && mouse.y >= 345
	   && mouse.y <= 469)
    {
      std::cout << "IA +" << std::endl;
      _ia++;
      this->displayIA(_ia);
    }
  // X MAP
  if (mouse.x >= 242 && mouse.x <= 316 && mouse.y >= 649 && mouse.y <= 777)
    {
      std::cout << "X -" << std::endl;
      if (_x > 0)
	_x--;
      else
	_x = 0;
      this->displayX(_x);
    }
  else if (mouse.x >= 750 && mouse.x <= 824 && mouse.y >= 649
	   && mouse.y <= 777)
    {
      std::cout << "X +" << std::endl;
      _x++;
      this->displayX(_x);
    }
  // Y MAP
  if (mouse.x >= 1100 && mouse.x <= 1180 && mouse.y >= 649 && mouse.y <= 777)
    {
      std::cout << "Y -" << std::endl;
      if (_y > 0)
	_y--;
      else
	_y = 0;
      this->displayY(_y);
    }
  else if (mouse.x >= 1612 && mouse.x <= 1684 && mouse.y >= 649
	   && mouse.y <= 777)
    {
      std::cout << "Y +" << std::endl;
      _y++;
       this->displayY(_y);
    }
  //PLAY
  if (mouse.x >= 1568 && mouse.x <= 1910 && mouse.y >= 949 && mouse.y <= 1037)
    {
      std::cout << "PLAY RANDOM" << std::endl;
      // Check if value are Ok
      // Call Generateur with IA Value, X and Y Value .
    }
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
