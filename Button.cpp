//
// Button.cpp for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri May 15 15:52:36 2015 Nicolas Charvoz
// Last update Fri May 15 16:08:52 2015 Nicolas Charvoz
//

#include "Button.hh"

Button::Button(std::string texture, int xL, int yL) : _texture(texture),
						      _xL(xL), _yL(yL)
{
  this->draw();
}

Button::~Button() {}

void Button::draw()
{
  gdl::Texture button;
  button.load(_texture);
  GLuint x = button.getWidth();
  GLuint y = button.getHeight();

  glEnable(GL_TEXTURE_2D);
  button.bind();

  glBegin(GL_QUADS);

  glTexCoord2d(0, 0);
  glVertex2f(_xL, _yL);

  glTexCoord2d(1, 0);
  glVertex2f(_xL + x, _yL);

  glTexCoord2d(1, 1);
  glVertex2f(_xL + x, _yL + y);

  glTexCoord2d(0, 1);
  glVertex2f(_xL, _yL + y);

  glEnd();
}
