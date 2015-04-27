//
// Game.cpp for Game in /home/antgar/rendu/cpp_bomberman
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Mon Apr 27 05:05:48 2015 Antoine Garcia
// Last update Mon Apr 27 06:05:43 2015 Antoine Garcia
//

#include "Game.hh"

Game::Game()
{
}

bool	Game::initialize()
{
  if (!_context.start(800,600, "Bomberman !"))
    return false;
  glEnable(GL_DEPTH_TEST);
  _shader.load("LibBomberman_linux_x64/shaders/basic.fp", GL_FRAGMENT_SHADER);
  _shader.load("LibBomberman_linux_x64/shaders/basic.vp", GL_VERTEX_SHADER);
  return true;
}

bool	Game::update()
{
  if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
    return false;
  // Mise a jour des inputs et de l'horloge de jeu
  _context.updateClock(_clock);
  _context.updateInputs(_input);
  return true;
}

void	Game::draw()
{

}

void	Game::run()
{
  initialize();
  while (this->update())
    draw();
}
