//
// InputManager.hh for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed May 27 14:45:11 2015 Nicolas Charvoz
// Last update Wed May 27 15:03:33 2015 Nicolas Charvoz
//

#ifndef INPUTMANAGER_HH_
# define INPUTMANAGER_HH_

#include <Game.hh>
#include <SdlContext.hh>
#include <Clock.hh>
#include <Input.hh>
#include <BasicShader.hh>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

class InputManager {

public:

  enum direction {
    UP,
    LEFT,
    RIGHT,
    DOWN
  };
  enum touche {
    PAUSE,
    MUTE,
    BACK,
  };

  InputManager();
  ~InputManager();
  InputManager::direction getDirection(gdl::Input&) const;
  InputManager::touche getTouche(gdl::Input&) const;

  private:

  gdl::Input _input;

};

#endif
