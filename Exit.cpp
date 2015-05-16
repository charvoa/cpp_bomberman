//
// Exit.cpp for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat May 16 15:18:59 2015 Nicolas Charvoz
// Last update Sat May 16 15:54:49 2015 Nicolas Charvoz
//

#include "Exit.hh"
#include <OpenGL.hh>
#include <iostream>
#include <Texture.hh>

Exit::Exit(Game *game)
{
  _game = game;
  std::cout << "Je suis dans Exit" << std::endl;
}

void Exit::drawBackground()
{
  gdl::Texture texture;
  texture.load(std::string("./images/BackgroundCredit.tga"));

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

void Exit::drawButtons() {}

void Exit::draw(gdl::Clock clock, gdl::BasicShader shader)
{
  glLoadIdentity();
  glMatrixMode(GL_PROJECTION);

  gluOrtho2D(0.0, (GLdouble)1920, 0.0, (GLdouble)1080);
  glDisable(GL_DEPTH_TEST);
  glClear(GL_COLOR_BUFFER_BIT);

  this->drawBackground();
  this->drawButtons();
}

bool Exit::update(gdl::Clock shader, gdl::Input input)
{
  // A FAIRE MIEUX
  usleep(1000000);
  exit(0);
  // CECI EST CACA

  return true;
}

Exit::~Exit()
{}
