//
// SelectChar.cpp for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat May 16 15:18:59 2015 Nicolas Charvoz
// Last update Wed May 27 11:18:32 2015 Nicolas Charvoz
//

#include "SelectChar.hh"
#include "SousMenuButton.hh"
#include "MenuBackground.hh"
#include <OpenGL.hh>
#include <iostream>
#include <Texture.hh>

TextureManager &SelectChar::_texManag = TextureManager::getInstance();

SelectChar::SelectChar(Game *game)
{
  _game = game;
  std::cout << "Je suis dans SelectChar" << std::endl;
  _texManag.registerTexture("backgroundSelectChar", "back");
  _texManag.registerTexture("PlaySousMenu", "playSM");
  this->loadBackground();
  this->loadButtons();
  this->loadModel();
  // _camera = new Camera(glm::vec3(0, 0, -0.0001), glm::vec3(0, 0, 0));
  // _game->getShader().load("LibBomberman_linux_x64/shaders/basic.fp",
  // 		     GL_FRAGMENT_SHADER);
  // _game->getShader().load("LibBomberman_linux_x64/shaders/basic.vp",
  // 		     GL_VERTEX_SHADER);

  // _game->getShader().build();

  // _camera->Init();

  // _game->getShader().bind();
  // _game->getShader().setUniform("view", _camera->getTransformation());
  // _game->getShader().setUniform("projection", _camera->getProjection());
}

void SelectChar::loadBackground()
{
  AObject *background = new MenuBackground();

  background->initialize(_texManag.getTexture("back"));
  _background = background;
}

void SelectChar::loadButtons()
{
  AObject *play = new SousMenuButton();

  play->initialize(_texManag.getTexture("playSM"));

  glm::vec3 trans(-0.6, -0.38, 0);
  play->translate(trans);

  _buttons.push_back(play);
}

void SelectChar::loadModel()
{
  _model = new ModelLoad();

  _model->initialize("./images/marvin.fbx");

  glm::vec3 trans(0, 350, 800);
  _model->translate(trans);

    trans = glm::vec3(0.5, 0.5, 0.5);
  _model->scale(trans);

  //  trans = glm::vec3(0, 1, 0);
  // _model->rotate(trans, 180.0f);
  // _camera->move(glm::vec3(0, 0, 0.0001), glm::vec3(0, 0, 0));
  // _camera->Init();
  // We need to rotate that fucking little shit ..
}

void SelectChar::drawModel(gdl::Clock& clock, gdl::BasicShader& shader)
{
  _model->draw(shader, clock);
}

void SelectChar::drawBackground(gdl::Clock& clock, gdl::BasicShader& shader)
{
  _background->draw(shader, clock);
}

void SelectChar::drawButtons(gdl::Clock& clock, gdl::BasicShader& shader)
{
  for (size_t i = 0; i < _buttons.size() ; ++i)
    _buttons[i]->draw(shader, clock);
}

void SelectChar::getNameOfButton(gdl::Input &input)
{
  glm::ivec2 mouse = input.getMousePosition();

  std::cout << "X : " << mouse.x << " Y: " << mouse.y << std::endl;
  if (mouse.x >= 1394 && mouse.x <= 1820 && mouse.y >= 900 && mouse.y <= 1000)
    {
      std::cout << "PLAY NEW MAP" << std::endl;
      Map map("./maps/x.map");
      _game->pushState(new World(_game, map, 2, 10));
    }
}

void SelectChar::draw(gdl::Clock& clock, gdl::BasicShader& shader)
{
  this->drawButtons(clock, shader);
  this->drawModel(clock, shader);
  this->drawBackground(clock, shader);
}

bool SelectChar::update(gdl::Clock& clock, gdl::Input& input)
{
  _model->update(clock, input);
  if (input.getInput(SDLK_BACKSPACE) == true)
    {
      _game->popState();
    }
  if (input.getInput(SDL_BUTTON_LEFT, true) == true)
    {
      this->getNameOfButton(input);
    }
  return true;
}

SelectChar::~SelectChar()
{}
