//
// Letters.hh for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Thu May 28 15:03:51 2015 Nicolas Charvoz
// Last update Thu Jun  4 01:06:07 2015 Nicolas Charvoz
//

#ifndef LETTERS_HH_
# define LETTERS_HH_

# include "AObject.hh"

class Letters : public AObject
{

private:

  gdl::Texture _texture;
  gdl::Geometry _geometry;
  float _speed;

public:

  Letters() { }
  virtual ~Letters() { }

  virtual bool initialize(const std::string &tex)
  {
    _speed = 10.0f;
    if (_texture.load(tex) == false)
      {
	std::cerr << "Cannot load the cube texture" << std::endl;
	return (false);
      }

    // 0.9  , 0.5 , 0.5
    // Ratio Marwin * Background = 1602

    _geometry.pushVertex(glm::vec3(0.03, 0.03, 0.5));
    _geometry.pushVertex(glm::vec3(0.03, -0.03, 0.5));
    _geometry.pushVertex(glm::vec3(-0.03, -0.03, 0.5));
    _geometry.pushVertex(glm::vec3(-0.03, 0.03, 0.5));

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
