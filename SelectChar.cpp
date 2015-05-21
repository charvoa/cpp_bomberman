//
// Menu.cpp for Menu in /home/antgar/rendu/cpp_bomberman
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Fri May  8 13:43:01 2015 Antoine Garcia
// Last update Thu May 21 13:20:55 2015 Nicolas Charvoz
//

#include "SelectChar.hh"
#include <OpenGL.hh>
#include <iostream>
#include <Texture.hh>

TextureManager &SelectChar::_texManag = TextureManager::getInstance();

SelectChar::SelectChar(Game *game)
{
  _game = game;
  std::cout << "Je suis dans la Selection Perso" << std::endl;
  _texManag.registerTexture("backgroundSelectChar", "playMenu");
}

void SelectChar::drawBackground()
{
  gdl::Texture texture = _texManag.loadTexture("playMenu");
  //d  texture.load(std::string("./images/backgroundSelectChar.tga"));

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

void SelectChar::drawButtons() {}

void SelectChar::draw(gdl::Clock clock, gdl::BasicShader shader)
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

bool SelectChar::update(gdl::Clock shader, gdl::Input input)
{
  (void) shader;

  if (input.getInput(SDLK_BACKSPACE) == true)
    {
      _game->popState();
    }
  return true;
}

SelectChar::~SelectChar()
{}
