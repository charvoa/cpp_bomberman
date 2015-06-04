//
// Camera.cpp for bomberman in /home/nicolas/rendu/cpp_bomberman
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Thu May 21 16:43:06 2015 Nicolas Girardot
// Last update Thu Jun 11 15:53:49 2015 Nicolas Girardot
//

#include "Camera.hh"

Camera::Camera(glm::vec3 cameraP, glm::vec3 cameraS) : _cameraP(cameraP), _cameraS(cameraS)
{
}

Camera::~Camera()
{

}

void	Camera::Init()
{
  _projection = glm::perspective(90.0f, 1920.0f / 1080.0f, 0.1f, 1000000.0f);
  _transformation = glm::lookAt(_cameraP, _cameraS, glm::vec3(0, 1, 0));
}

void	Camera::move(glm::vec3 cameraP, glm::vec3 cameraS)
{
  _transformation = glm::lookAt(cameraP, cameraS, glm::vec3(0, 1, 0));
}

glm::mat4 Camera::getTransformation()
{
  return (this->_transformation);
}

glm::mat4 Camera::getProjection()
{
  return (this->_projection);
}
