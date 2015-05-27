//
// InputManager.cpp for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed May 27 14:45:44 2015 Nicolas Charvoz
// Last update Wed May 27 16:24:25 2015 Nicolas Charvoz
//

#include "InputManager.hh"

InputManager::InputManager()
{}

InputManager::~InputManager()
{}

InputManager::touche InputManager::getTouche(gdl::Input &input) const
{
  if (input.getInput(SDLK_BACKSPACE) == true)
    return BACK;
  else if (input.getInput(SDLK_m) == true)
    return PAUSE;
  return NO;
}
