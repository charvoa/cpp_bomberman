//
// Cube.hh for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri May 22 14:48:05 2015 Nicolas Charvoz
// Last update Mon May 25 18:50:54 2015 Nicolas Charvoz
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
  virtual bool initialize(const std::string &mod)
  {
    _model.load(mod);
    return (true);
  }
  virtual void update(gdl::Clock const &clock, gdl::Input &input)
  {
    (void) clock;
    (void) input;
    //static int i = 0;

    //glm::vec3 trans(0, 0, 1);
    //i += 10;
    //rotate(trans, i);
  }
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock)
  {
    (void) clock;
    double deltaTime = 1;

    _model.draw(shader, getTransformation(), deltaTime);
  }
};

#endif
