//
// InputManager.hh for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed May 27 14:45:11 2015 Nicolas Charvoz
// Last update Mon Jun  1 23:47:51 2015 Nicolas Charvoz
//

#ifndef INPUTMANAGER_HH_
# define INPUTMANAGER_HH_

#include <Game.hh>
#include <SdlContext.hh>
#include <Input.hh>
#include <vector>
#include <iostream>

class InputManager {

public:

  enum touche {
    NO,
    SPACE,
    LSHIFT,
    PAUSE,
    MUTE,
    UNMUTE,
    BACK,
    UP,
    LEFT,
    RIGHT,
    DOWN,
    UP2,
    LEFT2,
    RIGHT2,
    DOWN2,
    ENTER
  };

  InputManager();
  ~InputManager();
  InputManager::touche getTouche(gdl::Input&) const;

  private:

  gdl::Input _input;
};

#endif
