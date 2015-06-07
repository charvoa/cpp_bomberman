//
// Thread.hpp for Thread in /home/antgar/rendu/cpp_plazza/app
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Sat Apr 18 11:21:26 2015 Antoine Garcia
// Last update Thu Apr 23 11:16:13 2015 Antoine Garcia
//

#ifndef THREAD_HPP_
# define THREAD_HPP_

#include <pthread.h>
#include "IBrun.hh"
#include <iostream>
class	Thread
{
  pthread_t	_thread;
public:
  static void	*run(void *Class)
  {
    return ((IBrun*)Class)->backRun(Class);
  }
  Thread(IBrun *backrun)
  {
    pthread_create(&_thread, NULL, &Thread::run, backrun);
  }
  void join()
  {
    void	*ptr;

    pthread_join(_thread, &ptr);
  }
};

#endif
