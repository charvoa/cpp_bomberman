//
// Cube.hh for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri May 22 14:48:05 2015 Nicolas Charvoz
// Last update Fri May 22 17:24:13 2015 Nicolas Charvoz
//

#ifndef MENUBACKGROUND_HH_
# define MENUBACKGROUND_HH_

# include "AObject.hh"

class MenuBackground : public AObject
{
private:
  gdl::Texture _texture;
  gdl::Geometry _geometry;
  float _speed;
public:
  MenuBackground() { }
  virtual ~MenuBackground() { }
  virtual bool initialize(const std::string &tex)
  {
    _speed = 10.0f;
    // On charge la texture qui sera affichee sur chaque face du cube
    if (_texture.load(tex) == false)
      {
	std::cerr << "Cannot load the cube texture" << std::endl;
	return (false);
      }
    // on set la color d'une premiere face
    // _geometry.setColor(glm::vec4(0, 1, 0, 1));
    // tout les pushVertex qui suivent seront de cette couleur
    // On y push les vertices d une premiere face
    _geometry.pushVertex(glm::vec3(0.9, 0.5, 0.5));
    _geometry.pushVertex(glm::vec3(0.9, -0.5, 0.5));
    _geometry.pushVertex(glm::vec3(-0.9, -0.5, 0.5));
    _geometry.pushVertex(glm::vec3(-0.9, 0.5, 0.5));
    // Les UVs d'une premiere face
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));

    // Tres important, on n'oublie pas de build la geometrie pour envoyer ses informations a la carte graphique
  _geometry.build();
 return (true);
  }
  // Ici le cube bougera avec les fleches du clavier
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
