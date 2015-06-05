//
// Intro.hh for bomberman in /home/audibe_l/rendu/cpp_bomberman
//
// Made by Audibert Louis
// Login   <audibe_l@epitech.net>
//
// Started on  Wed Jun 10 14:45:05 2015 Audibert Louis
// Last update Fri Jun  5 13:01:52 2015 Nicolas Charvoz
//

#ifndef _INTRO_HH_
# define _INTRO_HH_

#include "./Sound/SoundManager.hh"
#include "SelectChar.hh"
#include "TextureManager.hh"
#include "Game.hh"
#include "GameState.hh"
#include "Button.hh"
#include "Options.hh"
#include "Leaderboard.hh"
#include "Exit.hh"
#include <OpenGL.hh>
#include <iostream>
#include <Texture.hh>
#include <vector>
#include "MenuBackground.hh"
#include "LittleButton.hh"
#include "BigButton.hh"

class Intro : public GameState
{
public:
  Intro(Game *game);
  virtual void draw(gdl::Clock&, gdl::BasicShader&);
  virtual bool update(gdl::Clock&, gdl::Input&);
  virtual ~Intro();
  void drawBackground(gdl::Clock&, gdl::BasicShader&);
  void loadImages();

private:
  static Sound& _sound;
  static TextureManager& _texManag;
  std::vector<AObject*> _images;
  AObject *_background;
};

#endif /* _INTRO_HH_ */
