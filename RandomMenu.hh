//
// Options.hh for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat May 16 15:17:24 2015 Nicolas Charvoz
// Last update Thu Jun  4 18:00:34 2015 Nicolas Charvoz
//

#ifndef RANDOMMENU_HH_
# define RANDOMMENU_HH_

#include "./Sound/SoundManager.hh"
#include "SousMenuButton.hh"
#include "Game.hh"
#include "GameState.hh"
#include "TextureManager.hh"
#include "Letters.hh"
#include "Command.hh"
#include "InputManager.hh"

class Command;

class RandomMenu : public GameState {

public:
  RandomMenu(Game *game);
  virtual ~RandomMenu();
  virtual void draw(gdl::Clock&, gdl::BasicShader&);
  virtual bool update(gdl::Clock&, gdl::Input&);
  void loadBackground();
  void loadButtons();
  void drawBackground(gdl::Clock&, gdl::BasicShader&);
  void drawButtons(gdl::Clock&, gdl::BasicShader&);
  void displayIA(int);
  void displayX(int);
  void displayY(int);
  void getNameOfButton(gdl::Input &);

private:
  static Sound& _sound;
  static TextureManager& _texManag;
  InputManager *_inputManager;
  Command *_command;
  AObject *_background;
  std::vector<AObject*> _xMap;
  std::vector<AObject*> _yMap;
  std::vector<AObject*> _iaNb;
  std::vector<std::vector<AObject*> > _objects;
  int _x;
  int _y;
  int _ia;
};

#endif
