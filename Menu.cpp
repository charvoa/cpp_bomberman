//
// Menu.cpp for Menu in /home/antgar/rendu/cpp_bomberman
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Fri May  8 13:43:01 2015 Antoine Garcia
// Last update Fri May 15 16:09:29 2015 Nicolas Charvoz
//

#include "Menu.hh"

Sound&	Menu::_sound = Sound::getInstance();

Menu::Menu(Game *game)
{
  _game = game;
  _sound.initialize();
  _sound.registerSound("./test.mp3", "main");
  _sound.playMusic("main");
  std::cout << "Je suis dans le Menu" << std::endl;
}

void Menu::drawBackground()
{
  gdl::Texture texture;
  texture.load(std::string("./images/background.tga"));

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
  Button *exitButton = new Button(std::string("./images/ExitButton.tga"),
				  964, 148);
}

void Menu::draw(gdl::Clock clock, gdl::BasicShader shader)
{
  glLoadIdentity();
  glMatrixMode(GL_PROJECTION);

  gluOrtho2D(0.0, (GLdouble)1920, 0.0, (GLdouble)1080);
  glDisable(GL_DEPTH_TEST);
  glClear(GL_COLOR_BUFFER_BIT);

  this->drawBackground();
  this->drawButtons();
}

bool Menu::update(gdl::Clock shader, gdl::Input input)
{
  return true;
}

Menu::~Menu()
{}
