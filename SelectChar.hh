//
// Options.hh for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat May 16 15:17:24 2015 Nicolas Charvoz
// Last update Tue Jun  2 14:19:23 2015 Nicolas Charvoz
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
#include "Command.hh"
#include "DisplayButton.hh"

class Command;

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
  void drawDisplayButton(gdl::Clock&, gdl::BasicShader&);
  void drawDisplayIA(gdl::Clock&, gdl::BasicShader&);
  void drawDisplayMap(gdl::Clock&, gdl::BasicShader&);

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
  bool _map1;
  bool _map2;
  bool _map3;
  bool _map4;
  bool _map5;
  bool _mapR;
  bool _p1;
  bool _p2;
  bool _ia1;
  bool _ia5;
  bool _ia10;
  bool _ia15;
  bool _ia20;
  int _nbrIA;
};

#endif
