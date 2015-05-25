//
// Camera.hh for bomberman in /home/nicolas/rendu/cpp_bomberman
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Thu May 21 16:43:10 2015 Nicolas Girardot
// Last update Mon May 25 15:15:43 2015 Nicolas Girardot
//

#ifndef CAMERA_HH_
# define CAMERA_HH_

#include <stack>
#include <Game.hh>
#include <SdlContext.hh>
#include <Clock.hh>
#include <Input.hh>
#include <BasicShader.hh>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

class Camera
{
public:
  Camera();
  ~Camera();
  void	Init();
};

#endif
