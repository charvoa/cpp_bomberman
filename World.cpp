//
// World.cpp for World in /home/antgar/rendu/cpp_bomberman
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Sat May 23 18:46:16 2015 Antoine Garcia
// Last update Mon May 25 18:11:38 2015 Nicolas Girardot
//

#include "World.hh"

TextureManager &World::_texManag = TextureManager::getInstance();

World::World(Map &map, int nb_players, int nb_ia)
{
  (void)nb_ia;
  _map = map.getMap();
  _texManag.registerTexture("backgroundInGame", "backIG");
  _player1 = new HumanCharacter(1);
  this->loadBackground();
  if (nb_players == 2)
    _player2 = new HumanCharacter(2);
}

void	World::draw(gdl::Clock& clock, gdl::BasicShader& shader)
{
  this->drawBackground(clock, shader);
}

bool	World::update(gdl::Clock& clock, gdl::Input& shader)
{
  clock = clock;
  shader = shader;
  return true;
}

void	World::loadBackground()
{
  AObject *background = new MenuBackground();

  background->initialize(_texManag.getTexture("backIG"));
  _background = background;
}

void	World::drawBackground(gdl::Clock& clock, gdl::BasicShader &shader)
{
  _background->draw(shader, clock);
}

bool	World::setItemAtPosition(int x, int y, char c)
{
  if (c == '1' || c == '2')
    return (this->checkPlayerCanMove(x, y, c));
  return true;
}

char	World::getItemAtPosition(int x, int y)
{
  return (_map.at(y).at(x));
}

bool	World::checkPlayerCanMove(int x, int y, char c)
{
  char	test;

  test = getItemAtPosition(x, y);
  if (test == 'F')
    {
      _map.at(y).at(x) = c;
      return true;
    }
  return false;
}
