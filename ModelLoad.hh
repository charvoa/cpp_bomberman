//
// Cube.hh for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri May 22 14:48:05 2015 Nicolas Charvoz
// Last update Sat May 23 17:00:48 2015 Nicolas Charvoz
//

#ifndef MODELLOAD_HH_
# define MODELLOAD_HH_

# include "AObject.hh"
# include <Model.hh>

class ModelLoad : public AObject
{
private:
  gdl::Model _model;
  gdl::Texture _texture;
  gdl::Geometry _geometry;

public:

  ModelLoad(){}
  virtual ~ModelLoad() {}
  virtual bool initialize(const std::string &tex)
  {
    (void) tex;
    _model.load("./images/marvin.fbx");
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

    glm::mat4 trans(1);
    double deltaTime = 0;
    // On bind la texture pour dire que l'on veux l'utiliser
    _model.draw(shader, getTransformation(), deltaTime);
    // Et on dessine notre cube
  }
};

#endif
