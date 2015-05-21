//
// Scoring.hh for bomberman in /home/nicolas/rendu/cpp_bomberman
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Fri May 15 13:46:29 2015 Nicolas Girardot
// Last update Wed May 20 12:45:27 2015 Nicolas Girardot
//

#ifndef SCORING_HH_
#define SCORING_HH_

#include <sstream>
#include <map>
#include <iostream>
#include <string>
#include <fstream>

class Scoring
{
private:
  std::multimap<std::string, std::string> _high;
public:
  Scoring();
  ~Scoring();
  void		storeScore(std::string, int);
  std::multimap<std::string, std::string>	&highScore();
  int	getLowestScore();
  int	getScorePos(int);
};

#endif
