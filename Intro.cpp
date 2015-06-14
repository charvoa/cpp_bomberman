//
// Intro.cpp for bomberman in /home/audibe_l/rendu/cpp_bomberman
//
// Made by Audibert Louis
// Login   <audibe_l@epitech.net>
//
// Started on  Wed Jun 10 14:53:07 2015 Audibert Louis
// Last update Fri Jun  5 06:12:39 2015 Nicolas Charvoz
//

#include "Intro.hh"
#include "SousMenuButton.hh"
#include "MenuBackground.hh"
#include "Letters.hh"
#include <OpenGL.hh>
#include <iostream>
#include <Texture.hh>
#include <unistd.h>

Sound&	Intro::_sound = Sound::getInstance();
TextureManager &Intro::_texManag = TextureManager::getInstance();

Intro::Intro(Game *game)
{
  std::cout << "Je suis dans Intro" << std::endl;
  _game = game;
  _sound.registerSound("./resources/sounds/batman.mp3", "main");
  _sound.registerSound("./resources/sounds/beretta.mp3", "shot");

  this->loadImages();
}

Intro::~Intro()
{}

void Intro::loadImages()
{
  AObject *image;
  std::stringstream ss;
  int	i = 1;

  while (i < 64)
    {
      ss.str("");
      ss.clear();
      ss << "batman" << i;
      _texManag.registerTexture(ss.str(), ss.str());
      image = new MenuBackground();
      image->initialize(_texManag.getTexture(ss.str()));
      _images.push_back(image);
      i++;
    }
}

void Intro::drawBackground(gdl::Clock& clock, gdl::BasicShader& shader)
{
  _sound.playMusic("main", 1);
  for (std::vector<AObject*>::iterator it = _images.begin(); it != _images.end(); ++it)
    {
      (*it)->draw(shader, clock);
      usleep(50000);
      _game->flushContext();
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
  _sound.Pause("main");
}

void Intro::draw(gdl::Clock& clock, gdl::BasicShader& shader)
{
  shader.bind();
  this->drawBackground(clock, shader);
  _game->pushState(new Menu(_game));
}

bool Intro::update(gdl::Clock& clock, gdl::Input& input)
{
  (void) clock;
  (void) input;
  return true;
}
