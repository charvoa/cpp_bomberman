//
// Options.hh for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat May 16 15:17:24 2015 Nicolas Charvoz
// Last update Wed Jun  3 11:56:14 2015 Nicolas Charvoz
//

#ifndef GAMEOVER_HH_
# define GAMEOVER_HH_

#include "./Sound/SoundManager.hh"
#include "Game.hh"
#include "GameState.hh"
#include "TextureManager.hh"
#include "ModelLoad.hh"
#include "World.hh"
#include "Camera.hh"
#include "GameBackground.hh"
#include "InputManager.hh"
#include "Command.hh"
#include "DisplayButton.hh"

class Command;

class GameOver : public GameState {

public:
  GameOver(Game *game, int);
  virtual ~GameOver();
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
  std::map<std::string, AObject*> _buttons;
  AObject* _background;
  Camera *_camera;
  InputManager *_inputManager;
  Command *_command;
  Map *_map;
  gdl::BasicShader _shader;
  gdl::Clock _clock;
  int _player;
};

#endif
