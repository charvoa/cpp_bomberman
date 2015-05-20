//
// AObject.hh for  in /home/nicolaschr/Work/cpp_bomberman
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue May 19 11:19:54 2015 Nicolas Charvoz
// Last update Wed May 20 14:59:32 2015 Nicolas Charvoz
//

#ifndef AOBJECT_HH_
# define AOBJECT_HH_

# include <Texture.hh>

class AObject {

public:

  virtual ~AObject();
  virtual void createObject() = 0;
  virtual AObject *getObject() = 0;
  virtual void delObject() = 0;
  virtual void draw() = 0;
  virtual void upadate() = 0;
protected:

  std::string name;
  int id;
  gdl::Texture _texture;

};

#endif
