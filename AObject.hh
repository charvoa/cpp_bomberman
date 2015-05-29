//
// AObject.hh for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue May 19 11:19:54 2015 Nicolas Charvoz
// Last update Fri May 29 17:21:16 2015 Nicolas Girardot
//

#ifndef AOBJECT_HH_
# define AOBJECT_HH_

#include <stack>
#include <Game.hh>
#include <SdlContext.hh>
#include <Clock.hh>
#include <Input.hh>
#include <BasicShader.hh>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <Texture.hh>
#include <Geometry.hh>

class AObject
{
public:
  AObject() :
    _position(0, 0, 0), // On initialise la position a 0
    _rotation(0, 0, 0), // pareil pour la rotation
    _scale(1, 1, 1) // l'echelle est mise a 1
  {
  }
  virtual ~AObject()
  {}
  // La fonction initialize charge l'objet ou le construit
  virtual bool initialize(const std::string &tex)
  {
    (void)tex;
    return (true);
  }
  // La fonction update sert a gerer le comportement de l'objet
  virtual void update(gdl::Clock const &clock, gdl::Input &input)
  {
    (void)clock;
    (void)input;
  }
  // La fonction draw sert a dessiner l'objet
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock) = 0;
  virtual bool getStatus()
  {
    return (true);
  }
  void translate(glm::vec3 const &v)
  {
    _position += v;
  }
  void rotate(glm::vec3 const& axis, float angle)
  {
    _rotation += axis * angle;
  }
  void scale(glm::vec3 const& scale)
  {
    _scale *= scale;
  }
  glm::mat4 getTransformation()
  {
    glm::mat4 transform(1); // On cree une matrice identite
    // On applique ensuite les rotations selon les axes x, y et z
    transform = glm::translate(transform, _position);
    transform = glm::rotate(transform, _rotation.x, glm::vec3(1, 0, 0));
    transform = glm::rotate(transform, _rotation.y, glm::vec3(0, 1, 0));
    transform = glm::rotate(transform, _rotation.z, glm::vec3(0, 0, 1));
    // On effectue ensuite la translation
    // Et pour finir, on fait la mise a l'echelle
    transform = glm::scale(transform, _scale);
    return (transform);
  }
protected:
  glm::vec3 _position;
  glm::vec3 _rotation;
  glm::vec3 _scale;
};

#endif
