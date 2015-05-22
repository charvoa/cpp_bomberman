//
// Game.cpp for Game in /home/antgar/rendu/cpp_bomberman
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Mon Apr 27 05:05:48 2015 Antoine Garcia
// Last update Fri May 22 15:36:34 2015 Nicolas Charvoz
//

#include "Game.hh"
#include "AObject.hh"

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
  glm::mat4 projection;
  glm::mat4 transformation;

  if (!_context.start(1920, 1080, "Bomberman !"))
    return false;
  glEnable(GL_DEPTH_TEST);
  _shader.load("LibBomberman_linux_x64/shaders/basic.fp", GL_FRAGMENT_SHADER);
  _shader.load("LibBomberman_linux_x64/shaders/basic.vp", GL_VERTEX_SHADER);

  _shader.build();

  projection = glm::perspective(90.0f, 1920.0f/1080.0f, 0.1f, 100.0f);
  transformation = glm::lookAt(glm::vec3(0, 0, -0.001), glm::vec3(0, 0, 0),
			       glm::vec3(0, 1, 0));

  _shader.bind();
  _shader.setUniform("view", transformation);
  _shader.setUniform("projection", projection);

  //AObject *cube = new Cube();

  // if (cube->initialize() == false)
  //   {
  //     return false;
  //   }
  // _objects.push_back(cube);
  _sound.initialize();
  pushState(new Menu(this));
  return true;
}

bool	Game::update()
{
  if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
    return false;
  // Mise a jour des inputs et de l'horloge de jeu
  _context.updateClock(_clock);
  _context.updateInputs(_input);
  // for (size_t i = 0; i < _objects.size() ; ++i)
  //   {
  //     _objects[i]->update(_clock, _input);
  //   }
  if(peekState()->update(_clock, _input) == false)
    return false;
  return true;
}

void	Game::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _shader.bind();
  // for (size_t i = 0; i < _objects.size() ; ++i)
  //   {
  //     _objects[i]->draw(_shader, _clock);
  //   }
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
