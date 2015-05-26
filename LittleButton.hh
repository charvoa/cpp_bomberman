//
// Cube.hh for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri May 22 14:48:05 2015 Nicolas Charvoz
// Last update Fri May 22 17:23:27 2015 Nicolas Charvoz
//

#ifndef LITTLEBUTTON_HH_
# define LITTLEBUTTON_HH_

# include "AObject.hh"

class LittleButton : public AObject
{
private:
  // La texture utilisee pour le cube
  gdl::Texture _texture;
  // La geometrie du cube
  gdl::Geometry _geometry;
  // La vitesse de deplacement du cube
  float _speed;
public:

  LittleButton(){ }
  virtual ~LittleButton() { }
  virtual bool initialize(const std::string &tex)
  {
    _speed = 10.0f;
    if (_texture.load(tex) == false)
      {
	std::cerr << "Cannot load the cube texture" << std::endl;
	return (false);
      }

    _geometry.pushVertex(glm::vec3(0.35, 0.1, 0.5));
    _geometry.pushVertex(glm::vec3(0.35, -0.1, 0.5));
    _geometry.pushVertex(glm::vec3(-0.35, -0.1, 0.5));
    _geometry.pushVertex(glm::vec3(-0.35, 0.1, 0.5));

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
    // On bind la texture pour dire que l'on veux l'utiliser
    _texture.bind();
    // Et on dessine notre cube
    _geometry.draw(shader, getTransformation(), GL_QUADS);
  }
};

#endif
