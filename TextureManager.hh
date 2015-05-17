//
// TextureManager.hh for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sun May 17 15:05:00 2015 Nicolas Charvoz
// Last update Sun May 17 15:27:55 2015 Nicolas Charvoz
//

#ifndef TEXTUREMANAGER_HH_
# define TEXTUREMANAGER_HH_

#include <map>
#include <string>
#include <OpenGL.hh>
#include <iostream>
#include <Texture.hh>
#include <SDL/SDL.h>

class	TextureManager
{
  std::map<std::string, std::string> _textures;
  TextureManager(){};
  ~TextureManager(){};
  TextureManager(TextureManager const&);
  TextureManager&	operator=(TextureManager&);
public:
  static TextureManager&	getInstance();
  void		registerTexture(const std::string &filename,
				const std::string &title);
};

#endif
