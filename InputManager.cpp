//
// InputManager.cpp for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed May 27 14:45:44 2015 Nicolas Charvoz
// Last update Wed May 27 16:51:49 2015 Nicolas Charvoz
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
  else if (input.getInput(SDLK_p) == true)
    return PAUSE;
  else if (input.getInput(SDLK_m) == true)
    return MUTE;
  else if (input.getInput(SDLK_u) == true)
    return UNMUTE;
  else if (input.getInput(SDLK_UP) == true)
    return UP;
  else if (input.getInput(SDLK_LEFT) == true)
    return LEFT;
  else if (input.getInput(SDLK_RIGHT) == true)
    return RIGHT;
  else if (input.getInput(SDLK_DOWN) == true)
    return DOWN;
  return NO;
}
