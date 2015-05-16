//
// Load.cpp for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat May 16 15:18:59 2015 Nicolas Charvoz
// Last update Sat May 16 16:42:39 2015 Nicolas Charvoz
//

#include "Load.hh"
#include <OpenGL.hh>
#include <iostream>
#include <Texture.hh>

Load::Load(Game *game)
{
  _game = game;
  std::cout << "Je suis dans Load" << std::endl;
}

void Load::drawBackground()
{
  gdl::Texture texture;
  texture.load(std::string("./images/backgroundSelectChar.tga"));

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

void Load::drawButtons() {}

void Load::draw(gdl::Clock clock, gdl::BasicShader shader)
{
  (void) clock;
  (void) shader;

  glLoadIdentity();
  glMatrixMode(GL_PROJECTION);

  gluOrtho2D(0.0, (GLdouble)1920, 0.0, (GLdouble)1080);
  glDisable(GL_DEPTH_TEST);
  glClear(GL_COLOR_BUFFER_BIT);

  this->drawBackground();
  this->drawButtons();
}

bool Load::update(gdl::Clock shader, gdl::Input input)
{
  (void) shader;

  if (input.getInput(SDLK_BACKSPACE) == true)
    {
      _game->popState();
    }
  return true;
}

Load::~Load()
{}
