//
// Button.hh for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri May 15 15:52:58 2015 Nicolas Charvoz
// Last update Sun May 17 14:45:12 2015 Nicolas Charvoz
//

#ifndef BUTTON_HH_
# define BUTTON_HH_

#include <OpenGL.hh>
#include <iostream>
#include <Texture.hh>
#include <SDL/SDL.h>

class Button {

public:

  Button(const std::string&, int, int);
  ~Button();
  void draw();
  int getWidth() const;
  int getHeight() const;
  int getPosX() const;
  int getPosY() const;

private:
  const std::string &_texture;
  int _xL;
  int _yL;
  GLuint _x;
  GLuint _y;
};

#endif
