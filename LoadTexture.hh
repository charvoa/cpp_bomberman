//
// sdlglutils.hh for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue May 12 11:00:14 2015 Nicolas Charvoz
// Last update Tue May 12 11:06:16 2015 Nicolas Charvoz
//

#ifndef LOADTEXTURE_HH_
#define LOADTEXTURE_HH_

#include <GL/gl.h>
#include <SDL/SDL.h>

#ifndef GL_CLAMP_TO_EDGE
# define GL_CLAMP_TO_EDGE 0x812F
#endif

class LoadTexture
{

public:
  LoadTexture();
  ~LoadTexture();
  GLuint LoadImageTexture(const char *filename,bool useMipMap = true);
  int takeScreenshot(const char *filename);
  void drawAxis(double scale = 1);
  int initFullScreen(unsigned int *width = NULL,unsigned int *height = NULL);
  int XPMFromImage(const char *imagefile, const char *XPMfile);
  SDL_Cursor *cursorFromXPM(const char *xpm[]);
  SDL_Surface *flipSurface(SDL_Surface *surface);
};

#endif
