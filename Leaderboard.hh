//
// Options.hh for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat May 16 15:17:24 2015 Nicolas Charvoz
// Last update Wed Jun  3 19:18:55 2015 Nicolas Charvoz
//

#ifndef LEADERBOARD_HH_
# define LEADERBOARD_HH_

#include "./Sound/SoundManager.hh"
#include "SousMenuButton.hh"
#include "Game.hh"
#include "GameState.hh"
#include "Camera.hh"
#include "TextureManager.hh"
#include "InputManager.hh"
#include "Command.hh"
#include "Scoring.hh"
#include <memory>

class Command;

class Leaderboard : public GameState {

public:
  Leaderboard(Game *game);
  virtual ~Leaderboard();
  virtual void draw(gdl::Clock&, gdl::BasicShader&);
  virtual bool update(gdl::Clock&, gdl::Input&);
  void loadBackground();
  void loadButtons();
  void drawBackground(gdl::Clock&, gdl::BasicShader&);
  void drawButtons(gdl::Clock&, gdl::BasicShader&);
  void loadLetters();
  void drawLetters(gdl::Clock&, gdl::BasicShader&);
  void drawScore(gdl::Clock&, gdl::BasicShader&);
  void getScore();
  void buildWord(const std::string&, int, int);

private:
  static Sound& _sound;
  static TextureManager& _texManag;
  InputManager *_inputManager;
  Command *_command;
  AObject *_background;
  std::multimap<std::string, std::string> _scores;
  std::vector<std::string> _bestScore;
  std::map<std::string, AObject*> _letters;
  std::vector<AObject*> _word;
  std::vector< std::vector<AObject*> > _words;
};

#endif
