//
// Camera.cpp for bomberman in /home/nicolas/rendu/cpp_bomberman
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Thu May 21 16:43:06 2015 Nicolas Girardot
// Last update Tue May 26 14:55:34 2015 Nicolas Charvoz
//

#include "Camera.hh"

Camera::Camera()
{

}

Camera::~Camera()
{

}

void	Camera::Init()
{
  _projection = glm::perspective(90.0f, 1920.0f / 1080.0f, 0.1f, 1000.0f);
  _transformation = glm::lookAt(glm::vec3(0, 0, -0.001), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
}

glm::mat4 Camera::getTransformation()
{
  return (this->_transformation);
}

glm::mat4 Camera::getProjection()
{
  return (this->_projection);
}
