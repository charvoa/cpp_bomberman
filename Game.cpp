//
// Game.cpp for Game in /home/antgar/rendu/cpp_bomberman
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Mon Apr 27 05:05:48 2015 Antoine Garcia
// Last update Fri Jun 12 11:27:40 2015 Audibert Louis
//

#include "Game.hh"

Sound&	Game::_sound = Sound::getInstance();

Game::Game()
{
}

Game::~Game()
{
  std::cout << "GAME DESTRUCTOR" << std::endl;
}

bool	Game::initialize()
{
  _camera = new Camera(glm::vec3(0, 0, -0.0001), glm::vec3(0, 0, 0));
  if (!_context.start(1920, 1080, "Bomberman !", SDL_INIT_VIDEO, SDL_WINDOW_OPENGL /* | SDL_WINDOW_FULLSCREEN */))
    return false;
  glEnable(GL_DEPTH_TEST);
  _shader.load("LibBomberman_linux_x64/shaders/basic.fp", GL_FRAGMENT_SHADER);
  _shader.load("LibBomberman_linux_x64/shaders/basic.vp", GL_VERTEX_SHADER);

  _shader.build();

  _camera->Init();

  _shader.bind();
  _shader.setUniform("view", _camera->getTransformation());
  _shader.setUniform("projection", _camera->getProjection());

  _sound.initialize();
  pushState(new Intro(this));
  return true;
}

bool	Game::update()
{
  if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
    return false;
  // Mise a jour des inputs et de l'horloge de jeu
  _context.updateClock(_clock);
  _context.updateInputs(_input);
  if(peekState()->update(_clock, _input) == false)
    return false;
  return true;
}

void	Game::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _shader.bind();
  peekState()->draw(_clock, _shader);
  _context.flush();
}

void	Game::run()
{
  initialize();
  while (this->update())
    draw();
}

void	Game::pushState(GameState *state)
{
  _states.push(state);
}

void	Game::popState()
{
  delete _states.top();
  _states.pop();
}

void	Game::changeState(GameState *state)
{
  if (!_states.empty())
    popState();
  pushState(state);
}

GameState	*Game::peekState()
{
  if (!_states.empty())
    return _states.top();
  return NULL;
}

gdl::BasicShader	Game::getShader()
{
  return (_shader);
}

void	Game::flushContext()
{
  _context.flush();
}
