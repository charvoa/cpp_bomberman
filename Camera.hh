//
// Camera.hh for bomberman in /home/nicolas/rendu/cpp_bomberman
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Thu May 21 16:43:10 2015 Nicolas Girardot
// Last update Mon May 25 15:57:07 2015 Nicolas Girardot
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
private:
  glm::mat4 _projection;
  glm::mat4 _transformation;
public:
  Camera();
  ~Camera();
  void	Init();
  glm::mat4 getTransformation();
  glm::mat4 getProjection();
};

#endif
