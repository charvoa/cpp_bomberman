//
// Menu.cpp for Menu in /home/antgar/rendu/cpp_bomberman
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Fri May  8 13:43:01 2015 Antoine Garcia
// Last update Tue May 12 19:50:55 2015 Nicolas Charvoz
//

#include "Menu.hh"
#include <OpenGL.hh>
#include <iostream>

Menu::Menu(Game *game)
{
  _game = game;
  std::cout << "Je suis dans le Menu" << std::endl;
}

GLuint LoadTexture(const char *filename)
{
  GLuint texture;
  int width, height;
  unsigned char *data;
  FILE *file;

  file = fopen( filename, "rb" );
  if (file == NULL)
    return 0;
  width = 1024;
  height = 768;
  data = (unsigned char *)malloc(width * height * 3);
  fread(data, width * height * 3, 1, file);
  fclose(file);

  for(int i = 0; i < width * height ; ++i)
    {
      int index = i*3;
      unsigned char B, R;
      B = data[index];
      R = data[index+2];
      data[index] = R;
      data[index+2] = B;
    }
  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
		   GL_LINEAR_MIPMAP_NEAREST);

  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT);
  gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height,GL_RGB,
		     GL_UNSIGNED_BYTE, data);
  free(data);
  return texture;
}

void Menu::drawBackground()
{
  GLuint texture = LoadTexture("./images/background.bmp");

  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, texture);

  glBegin(GL_QUADS);

  glTexCoord2d(0, 0);
  glVertex2f(0, 768);

  glTexCoord2d(0, 1);
  glVertex2f(0, 0);

  glTexCoord2d(1, 1);
  glVertex2f(1024, 0);

  glTexCoord2d(1, 0);
  glVertex2f(1024, 768);

  glEnd();
}

void Menu::drawButtons() {}

void Menu::draw(gdl::Clock clock, gdl::BasicShader shader)
{
  glLoadIdentity();
  glMatrixMode(GL_PROJECTION);

  gluOrtho2D(0.0, (GLdouble)1024, 0.0, (GLdouble)768);
  glDisable(GL_DEPTH_TEST);
  glClear(GL_COLOR_BUFFER_BIT);

  this->drawBackground();
  this->drawButtons();

  glFlush();
}

bool Menu::update(gdl::Clock shader, gdl::Input input)
{
  return true;
}

Menu::~Menu()
{}
