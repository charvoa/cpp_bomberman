//
// GameBackground.hh for GameBackground in /home/nicolas/rendu/cpp_bomberman
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Tue May 26 22:39:24 2015 Nicolas Girardot
// Last update Mon Jun  1 16:04:48 2015 Nicolas Girardot
//

#ifndef GAMEBACKGROUND_HH_
# define GAMEBACKGROUND_HH_

# include "AObject.hh"

class GameBackground : public AObject
{

private:

  gdl::Texture _texture;
  gdl::Geometry _geometry;
  float _speed;

public:

  GameBackground() { }
  virtual ~GameBackground() { }

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

    _geometry.pushVertex(glm::vec3(-2900, 700, -2300));
    _geometry.pushVertex(glm::vec3(-2700, -1200, 230));
    _geometry.pushVertex(glm::vec3(2700, -1200, 230));
    _geometry.pushVertex(glm::vec3(2900, 700, -2300));

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
