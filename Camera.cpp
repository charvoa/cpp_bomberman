//
// Camera.cpp for bomberman in /home/nicolas/rendu/cpp_bomberman
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Thu May 21 16:43:06 2015 Nicolas Girardot
// Last update Mon May 25 15:05:45 2015 Nicolas Girardot
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
  glm::mat4 projection;
  glm::mat4 transformation;

  projection = glm::perspective(60.0f, 1920.0f / 1080.0f, 0.1f, 100.0f);
  transformation = glm::lookAt(glm::vec3(0, 10, 30), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
}
