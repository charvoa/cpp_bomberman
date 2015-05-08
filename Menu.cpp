//
// Menu.cpp for Menu in /home/antgar/rendu/cpp_bomberman
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Fri May  8 13:43:01 2015 Antoine Garcia
// Last update Fri May  8 14:10:19 2015 Antoine Garcia
//

#include "Menu.hh"

#include <iostream>

Menu::Menu(Game *game)
{
  _game = game;
  std::cout << "Je suis dans le Menu" << std::endl;
}

void Menu::draw(gdl::Clock clock, gdl::BasicShader shader)
{

}

bool Menu::update(gdl::Clock shader, gdl::Input input)
{}

Menu::~Menu()
{}
