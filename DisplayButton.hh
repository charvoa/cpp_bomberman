//
// Cube.hh for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri May 22 14:48:05 2015 Nicolas Charvoz
// Last update Tue Jun  2 09:47:23 2015 Nicolas Charvoz
//

#ifndef DISPLAYBUTTON_HH_
# define DISPLAYBUTTON_HH_

# include <string>
# include <iostream>
# include "MenuBackground.hh"

class DisplayButton : public AObject
{
private:
  gdl::Texture _texture;
  gdl::Geometry _geometry;
  float _speed;

public:

  DisplayButton(){ }
  virtual ~DisplayButton() { }
  virtual bool initialize(const std::string &tex)
  {
    _speed = 10.0f;
    if (_texture.load(tex) == false)
      {
	std::cerr << "Cannot load the cube texture" << std::endl;
	return (false);
      }

    _geometry.pushVertex(glm::vec3(0.07, 0.05, 0.5));
    _geometry.pushVertex(glm::vec3(0.07, -0.05, 0.5));
    _geometry.pushVertex(glm::vec3(-0.07, -0.05, 0.5));
    _geometry.pushVertex(glm::vec3(-0.07, 0.05, 0.5));

    _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));

    _geometry.build();
    return (true);
  }
  virtual void update(gdl::Clock const &clock, gdl::Input &input)
  {
    (void)clock;
    (void)input;
  }
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock)
  {
    (void)clock;

    _texture.bind();
    _geometry.draw(shader, getTransformation(), GL_QUADS);
  }
};

#endif
