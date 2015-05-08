//
// Menu.cpp for Menu in /home/antgar/rendu/cpp_bomberman
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Fri May  8 13:43:01 2015 Antoine Garcia
// Last update Fri May  8 15:26:29 2015 Antoine Garcia
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
  glDisable(GL_LIGHTING);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  /* Draw the gray transparent zone over the game */
  glColor4f(0.8, 0.8, 0.8, 0.5);
  glBegin(GL_QUADS);
  glVertex3f(0, 0, 0);
  glVertex3f(0, 600, 0);
  glVertex3f(800, 600, 0);
  glVertex3f(800, 0, 0);
  glEnd();

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
