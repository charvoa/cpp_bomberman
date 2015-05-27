//
// InputManager.cpp for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed May 27 14:45:44 2015 Nicolas Charvoz
// Last update Wed May 27 14:57:53 2015 Nicolas Charvoz
//

#include "InputManager.hh"

InputManager::InputManager()
{}

InputManager::~InputManager()
{}

InputManager::direction InputManager::getDirection(gdl::Input &input) const
{
  (void) input;
  return UP;
}

InputManager::touche InputManager::getTouche(gdl::Input &input) const
{
  (void) input;
  return BACK;
}
