//
// TextureManager.hh for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sun May 17 15:05:00 2015 Nicolas Charvoz
// Last update Sun May 17 16:03:44 2015 Nicolas Charvoz
//

#ifndef TEXTUREMANAGER_HH_
# define TEXTUREMANAGER_HH_

#include <map>
#include <string>
#include <OpenGL.hh>
#include <iostream>
#include <Texture.hh>
#include <SDL/SDL.h>
#include <sstream>

class	TextureManager
{
  std::map<std::string, std::string> _textures;
  gdl::Texture _texture;
  TextureManager(){};
  ~TextureManager(){};
  TextureManager(TextureManager const&);
  TextureManager&	operator=(TextureManager&);

public:

  static TextureManager&	getInstance();
  void		registerTexture(const std::string &filename,
				const std::string &title);
  gdl::Texture &loadTexture(const std::string &);
  const std::string &getTexture(const std::string &);

};

#endif
