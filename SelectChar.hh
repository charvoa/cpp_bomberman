//
// Menu.hh for Menu in /home/antgar/rendu/cpp_bomberman
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Fri May  8 13:41:57 2015 Antoine Garcia
// Last update Fri May 22 13:07:03 2015 Nicolas Charvoz
//

#ifndef SELECTCHAR_HH_
# define SELECTCHAR_HH_

#include "./Sound/SoundManager.hh"
#include "TextureManager.hh"
#include "Game.hh"
#include "GameState.hh"
#include "Button.hh"
#include "Model.hh"
#include "AShader.hh"
#include <SDL.h>
#include "SDL.h"
# include <SDL/SDL.h>
# include <SDL/SDL_image.h>
# include <GL/glu.h>
# include <GL/gl.h>
# include <GL/freeglut.h>
# include <X11/Xlib.h>

class	SelectChar: public GameState
{

public:
  SelectChar(Game *game);
  virtual ~SelectChar();
  virtual void draw(gdl::Clock&, gdl::BasicShader&);
  virtual bool update(gdl::Clock&, gdl::Input&);
  void drawBackground();
  void drawButtons();
  void drawPerso(gdl::BasicShader&);
  void writeToScreen();

private:
  static Sound&	_sound;
  static TextureManager &_texManag;
  Button *_playButton;
  gdl::Model _model;

};

#endif
