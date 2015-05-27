//
// Options.hh for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat May 16 15:17:24 2015 Nicolas Charvoz
// Last update Wed May 27 15:03:43 2015 Nicolas Charvoz
//

#ifndef SELECTCHAR_HH_
# define SELECTCHAR_HH_

#include "./Sound/SoundManager.hh"
#include "Game.hh"
#include "GameState.hh"
#include "TextureManager.hh"
#include "ModelLoad.hh"
#include "World.hh"
#include "Camera.hh"
#include "GameBackground.hh"
#include "InputManager.hh"

class SelectChar : public GameState {

public:
  SelectChar(Game *game);
  virtual ~SelectChar();
  virtual void draw(gdl::Clock&, gdl::BasicShader&);
  virtual bool update(gdl::Clock&, gdl::Input&);
  void loadBackground();
  void loadButtons();
  void drawBackground(gdl::Clock&, gdl::BasicShader&);
  void drawButtons(gdl::Clock&, gdl::BasicShader&);
  void getNameOfButton(gdl::Input&);

private:
  static Sound& _sound;
  static TextureManager& _texManag;
  std::vector<AObject*> _buttons;
  AObject* _background;
  Camera *_camera;
  InputManager *_inputManager;
};

#endif
