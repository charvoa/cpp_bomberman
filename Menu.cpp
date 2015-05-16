//
// Menu.cpp for Menu in /home/antgar/rendu/cpp_bomberman
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Fri May  8 13:43:01 2015 Antoine Garcia
// Last update Sat May 16 16:49:06 2015 Nicolas Charvoz
//

#include "Menu.hh"

Sound&	Menu::_sound = Sound::getInstance();

Menu::Menu(Game *game)
{
  _game = game;
  _sound.registerSound("./resources/sounds/menu.wav", "main");
  _sound.registerSound("./resources/sounds/beretta.mp3", "shot");
  _sound.playMusic("main");
  std::cout << "Je suis dans le Menu" << std::endl;
}

void Menu::drawBackground()
{
  gdl::Texture texture;
  texture.load(std::string("./images/background-desert.tga"));

  glEnable(GL_TEXTURE_2D);
  texture.bind();
  glBegin(GL_QUADS);

  glTexCoord2d(0, 0);
  glVertex2f(0, 0);

  glTexCoord2d(1, 0);
  glVertex2f(1920, 0);

  glTexCoord2d(1, 1);
  glVertex2f(1920, 1080);

  glTexCoord2d(0, 1);
  glVertex2f(0, 1080);

  glEnd();
}

void Menu::drawButtons()
{
  _exitButton = new Button(std::string("./images/ExitButton.tga"),
				  964, 148);
  _optionsButton = new Button(std::string("./images/OptionsButton.tga"),
				    60, 148);
  _loadButton = new Button(std::string("./images/LoadButton.tga"),
				  60, 600);
  _leaderboardButton =
    new Button(std::string("./images/LeaderboardButton.tga"), 60, 375);
  _playButton = new Button(std::string("./images/PlayButton.tga"),
				  964, 375);
}

void Menu::draw(gdl::Clock clock, gdl::BasicShader shader)
{
  (void) clock;
  (void)shader;

  glLoadIdentity();
  glMatrixMode(GL_PROJECTION);

  gluOrtho2D(0.0, (GLdouble)1920, 0.0, (GLdouble)1080);
  glDisable(GL_DEPTH_TEST);
  glClear(GL_COLOR_BUFFER_BIT);

  this->drawBackground();
  this->drawButtons();
}

void Menu::getNameOfButton(gdl::Input input)
{
  glm::ivec2 mouse = input.getMousePosition();

  if (mouse.x >= _exitButton->getPosX()
      && mouse.x <= _exitButton->getPosX() + _exitButton->getWidth()
      && mouse.y <= 1080 - _exitButton->getPosY()
      && mouse.y >= 1080 - _exitButton->getPosY() - _exitButton->getHeight()
      )
    {
      std::cout << "EXIT" << std::endl;
      _game->pushState(new Exit(_game));
    }
  else if (mouse.x >= _playButton->getPosX()
      && mouse.x <= _playButton->getPosX() + _playButton->getWidth()
      && mouse.y <= 1080 - _playButton->getPosY()
      && mouse.y >= 1080 - _playButton->getPosY() - _playButton->getHeight()
      )
    {
      std::cout << "PLAY" << std::endl;
      _game->pushState(new SelectChar(_game));
    }
    else if (mouse.x >= _loadButton->getPosX()
      && mouse.x <= _loadButton->getPosX() + _loadButton->getWidth()
      && mouse.y <= 1080 - _loadButton->getPosY()
      && mouse.y >= 1080 - _loadButton->getPosY() - _loadButton->getHeight()
      )
      {
	std::cout << "LOAD" << std::endl;
	_game->pushState(new Load(_game));
      }
    else if (mouse.x >= _leaderboardButton->getPosX()
	   && mouse.x <= _leaderboardButton->getPosX()
	   + _leaderboardButton->getWidth()
      && mouse.y <= 1080 - _leaderboardButton->getPosY()
      && mouse.y >= 1080 - _leaderboardButton->getPosY()
	   - _leaderboardButton->getHeight()
      )
    {
      std::cout << "LEADERBOARD" << std::endl;
      _game->pushState(new Leaderboard(_game));
    }
  else if (mouse.x >= _optionsButton->getPosX()
      && mouse.x <= _optionsButton->getPosX() + _optionsButton->getWidth()
      && mouse.y <= 1080 - _optionsButton->getPosY()
      && mouse.y >= 1080 - _optionsButton->getPosY()
	   - _optionsButton->getHeight()
	   )
    {
      std::cout << "OPTIONS" << std::endl;
      _game->pushState(new Options(_game));
    }
}

bool Menu::update(gdl::Clock shader, gdl::Input input)
{
  (void) shader;

  if (input.getInput(SDL_BUTTON_LEFT, true) == true)
    {
      _sound.playMusic("shot");
      this->getNameOfButton(input);
    }
  return true;
}

Menu::~Menu()
{}
