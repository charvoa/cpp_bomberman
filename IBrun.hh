//
// IBrun.hh for IBrun in /home/antgar/rendu/cpp_plazza/app
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Sat Apr 18 10:33:12 2015 Antoine Garcia
// Last update Tue Jun  9 16:29:55 2015 Audibert Louis
//

#ifndef IBRUN_HH_
# define IBRUN_HH_

class	IBrun
{
public:
  virtual ~IBrun(){};
  virtual void *backRun(void *Class) = 0;
};

#endif /* IBRUN_HH_ */
