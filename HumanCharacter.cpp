//
// HumanCharacter.cpp for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue May 19 11:55:01 2015 Nicolas Charvoz
// Last update Tue May 19 12:15:28 2015 Nicolas Charvoz
//

#include "HumanCharacter.hh"

TextureManager &HumanCharacter::_texManag = TextureManager::getInstance();

HumanCharacter::HumanCharacter(int id)
{
  this->_id = id;
  this->_hp = 100;
  _model.load(std::string("./images/marvin.fbx"));
}

HumanCharacter::~HumanCharacter()
{
}

int HumanCharacter::getHp() const
{
  return _hp;
}

void HumanCharacter::dropBomb()
{
  std::cout << "I droped a bomb hahah" << std::endl;
}

void HumanCharacter::takeObject(AObject *object)
{
  this->_listObject.push_back(object);
}

void HumanCharacter::die()
{
  std::cout << "I died" << std::cout;
}
