//
// Button.hh for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri May 15 15:52:58 2015 Nicolas Charvoz
// Last update Fri May 15 16:07:12 2015 Nicolas Charvoz
//

#ifndef BUTTON_HH_
# define BUTTON_HH_

# include "Menu.hh"

class Button {

public:

  Button(std::string, int, int);
  ~Button();
  void draw();

private:
  std::string _texture;
  int _xL;
  int _yL;

};

#endif
