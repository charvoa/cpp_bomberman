//
// Camera.hh for bomberman in /home/nicolas/rendu/cpp_bomberman
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Thu May 21 16:43:10 2015 Nicolas Girardot
// Last update Tue Jun  9 16:08:34 2015 Nicolas Girardot
//

#ifndef CAMERA_HH_
# define CAMERA_HH_

#include <stack>
#include <Game.hh>
#include <SdlContext.hh>
#include <Clock.hh>
#include <Input.hh>
#include <BasicShader.hh>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

class Camera
{
private:
  glm::mat4 _projection;
  glm::mat4 _transformation;
  glm::vec3 _cameraP;
  glm::vec3 _cameraS;
public:
  Camera(glm::vec3, glm::vec3);
  ~Camera();
  void	Init();
  void	move(glm::vec3, glm::vec3);
  glm::mat4 getTransformation();
  glm::mat4 getProjection();
};

#endif
