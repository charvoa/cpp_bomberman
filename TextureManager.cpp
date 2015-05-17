//
// TextureManager.cpp for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sun May 17 15:06:38 2015 Nicolas Charvoz
// Last update Sun May 17 15:08:42 2015 Nicolas Charvoz
//

#include "TextureManager.hh"

TextureManager&	TextureManager::getInstance()
{
  static TextureManager instance;
  return instance;
}

void	TextureManager::registerTexture(const std::string &filename,
					const std::string&title)
{
  _textures[title] = filename;
}
