//
// Button.cpp for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri May 15 15:52:36 2015 Nicolas Charvoz
// Last update Sun May 17 15:53:02 2015 Nicolas Charvoz
//

#include "Button.hh"

TextureManager &Button::_texManag = TextureManager::getInstance();

Button::Button(const std::string &texture, int xL, int yL) : _texture(texture),
						      _xL(xL), _yL(yL)
{
  this->draw();
}

Button::~Button() {}

void Button::draw()
{
  gdl::Texture button;
  button.load(_texture, true);
  _x = button.getWidth();
  _y = button.getHeight();

  glEnable(GL_TEXTURE_2D);
  button.bind();

  glBegin(GL_QUADS);

  glTexCoord2d(0, 0);
  glVertex2f(_xL, _yL);

  glTexCoord2d(1, 0);
  glVertex2f(_xL + _x, _yL);

  glTexCoord2d(1, 1);
  glVertex2f(_xL + _x, _yL + _y);

  glTexCoord2d(0, 1);
  glVertex2f(_xL, _yL + _y);

  glEnd();
}

int Button::getWidth() const
{
  return (int)_x;
}

int Button::getHeight() const
{
  return (int)_y;
}

int Button::getPosX() const
{
  return _xL;
}

int Button::getPosY() const
{
  return _yL;
}
