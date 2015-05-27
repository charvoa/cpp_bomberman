//
// InputManager.hh for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed May 27 14:45:11 2015 Nicolas Charvoz
// Last update Wed May 27 16:12:42 2015 Nicolas Charvoz
//

#ifndef INPUTMANAGER_HH_
# define INPUTMANAGER_HH_

#include <Game.hh>
#include <SdlContext.hh>
#include <Input.hh>
#include <vector>

class InputManager {

public:

  enum touche {
    NO,
    PAUSE,
    MUTE,
    BACK,
    UP,
    LEFT,
    RIGHT,
    DOWN
  };

  InputManager();
  ~InputManager();
  InputManager::touche getTouche(gdl::Input&) const;

  private:

  gdl::Input _input;

};

#endif
