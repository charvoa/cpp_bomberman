//
// Options.hh for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat May 16 15:17:24 2015 Nicolas Charvoz
// Last update Tue Jun  2 14:33:49 2015 Nicolas Charvoz
//

#ifndef RANDOMMENU_HH_
# define RANDOMMENU_HH_

#include "./Sound/SoundManager.hh"
#include "SousMenuButton.hh"
#include "Game.hh"
#include "GameState.hh"
#include "TextureManager.hh"
#include "Letters.hh"

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
  void drawLetters(gdl::Clock&, gdl::BasicShader&, int, int);

private:
  static Sound& _sound;
  static TextureManager& _texManag;
  AObject *_background;
  std::map<std::string, AObject*> _letters;
};

#endif
