//
// Menu.cpp for Menu in /home/antgar/rendu/cpp_bomberman
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Fri May  8 13:43:01 2015 Antoine Garcia
// Last update Tue May 12 13:11:41 2015 Nicolas Charvoz
//

#include "Menu.hh"
#include <OpenGL.hh>
#include <iostream>

Menu::Menu(Game *game)
{
  _game = game;
  std::cout << "Je suis dans le Menu" << std::endl;
}

void Menu::draw(gdl::Clock clock, gdl::BasicShader shader)
{
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  gluOrtho2D(0,800,0,600);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glEnable(GL_BLEND);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_TEXTURE_2D);
  glDisable(GL_LIGHTING);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  /* Draw the gray transparent zone over the game */
  glColor3ub(255, 255, 0);
  //GLuint test = loadTexture("./images/background.png");
  glBindTexture(GL_TEXTURE_2D, test);
  glBegin(GL_QUADS);
  glTexCoord2f(0, 0);
  glVertex3f(0, 0, 0);
  glTexCoord2f(1, 0);
  glVertex3f(0, 600, 0);
  glTexCoord2f(1, 1);
  glVertex3f(800, 600, 0);
  glTexCoord2f(0, 1);
  glVertex3f(800, 0, 0);
  glEnd();
  glFlush();
  SDL_GL_SwapBuffers();

  /* Switch back to 3D Mode */
  glEnable(GL_LIGHTING);
  glDisable(GL_BLEND);
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
}

bool Menu::update(gdl::Clock shader, gdl::Input input)
{
  return true;
}

Menu::~Menu()
{}
