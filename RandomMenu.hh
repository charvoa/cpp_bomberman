//
// Options.hh for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat May 16 15:17:24 2015 Nicolas Charvoz
// Last update Thu Jun  4 09:23:01 2015 Nicolas Charvoz
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
  void loadLetters();
  void drawBackground(gdl::Clock&, gdl::BasicShader&);
  void drawButtons(gdl::Clock&, gdl::BasicShader&);
  void drawLetters(gdl::Clock&, gdl::BasicShader&, int, int);
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
  std::map<std::string, AObject*> _letters;
  std::vector<AObject*> _word;
  std::vector<std::vector<AObject*> > _words;
};

#endif
