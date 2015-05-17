//
// TextureManager.cpp for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sun May 17 15:06:38 2015 Nicolas Charvoz
// Last update Sun May 17 16:04:32 2015 Nicolas Charvoz
//

#include "TextureManager.hh"

TextureManager&	TextureManager::getInstance()
{
  static TextureManager instance;
  return instance;
}

void	TextureManager::registerTexture(const std::string &filename,
					const std::string &title)
{
  std::stringstream ss;

  ss << "./images/" << filename << ".tga";
  _textures[title] = ss.str();
}

gdl::Texture &TextureManager::loadTexture(const std::string &title)
{
  _texture.load(_textures[title]);

  return _texture;
}

const std::string &TextureManager::getTexture(const std::string &title)
{
  return _textures[title];
}
