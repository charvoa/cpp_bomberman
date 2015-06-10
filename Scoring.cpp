//
// Scoring.cpp for Scoring in /home/nicolas/rendu/cpp_bomberman
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Fri May 15 13:53:19 2015 Nicolas Girardot
// Last update Wed Jun 10 15:18:46 2015 Nicolas Girardot
//

#include "Scoring.hh"

Scoring::Scoring()
{

}

Scoring::~Scoring()
{

}

int	Scoring::getLowestScore()
{
  std::stringstream ss;
  std::string line;
  std::string name;
  std::string score;
  std::ifstream file;
  std::stringstream nbr;
  int	scorea;

  file.open("./.score", std::ios_base::app);
  while (!file.eof())
    {
      ss.clear();
      getline(file, line);
      ss << line;
      getline(ss, name, ' ');
      getline(ss, score, ' ');
    }
  std::stringstream(score) >> scorea;
  return (scorea);
}

int	Scoring::getScorePos(int pScore)
{
  std::stringstream ss;
  std::string line;
  std::string name;
  std::string score;
  std::ifstream file;
  std::stringstream nbr;
  int	ascore;
  int	pos;

  pos = 1;
  file.open("./.score", std::ios_base::app);
  while (pos <= 5)
    {
      ss.clear();
      getline(file, line);
      ss << line;
      getline(ss, name, ' ');
      getline(ss, score, ' ');
      std::stringstream(score) >> ascore;
      std::cout << "PScore = " << pScore << " ; ascord = " << ascore << " ; pos = " << pos << std::endl;
      if (pScore > ascore)
	return (pos);
      pos++;
    }
  return (0);
}

void	Scoring::storeScore(std::string playerName, int score)
{
  int	i;
  int	lowScore;
  int	scorePosition;
  std::string	line;
  std::ifstream infile;
  std::ofstream outfile;

  i = 1;
  lowScore = getLowestScore();
  if (score < lowScore)
    return;
  scorePosition = getScorePos(score);
  infile.open("./.score", std::ios_base::app);
  outfile.open("./.score.tmp", std::ios_base::app);
  while (i < 5)
    {
      std::cout << "I = " << i << std::endl;
      line.clear();
      getline(infile, line);
      if (i == scorePosition)
	{
	  outfile << playerName << " " << score << std::endl;
	  outfile << line << std::endl;
	}
      else
	outfile << line << std::endl;
      i++;
    }
  i = 1;
  std::cout << "Pos = " << scorePosition << std::endl;
  if (scorePosition == 5)
    outfile << playerName << " " << score << std::endl;
  else if (scorePosition == 0)
    {
      getline(infile, line);
      outfile << line << std::endl;
    }
  std::remove("./.score");
  std::rename("./.score.tmp", "./.score");
}

std::multimap<std::string, std::string> &Scoring::highScore()
{
  int	i = 1;
  std::stringstream ss;
  std::string line;
  std::string name;
  std::string score;
  std::ifstream file;

  file.open("./.score", std::ios_base::app);
  while (i <= 5)
    {
      ss.clear();
      getline(file, line);
      ss << line;
      getline(ss, name, ' ');
      getline(ss, score, ' ');
      _high.insert(std::pair<std::string, std::string>(score, name));
      i++;
    }
  return (_high);
}
