//
// Menu.cpp for Menu in /home/antgar/rendu/cpp_bomberman
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Fri May  8 13:43:01 2015 Antoine Garcia
// Last update Tue Jun  2 12:15:41 2015 Nicolas Charvoz
//

#include "Menu.hh"

Sound&	Menu::_sound = Sound::getInstance();
TextureManager &Menu::_texManag = TextureManager::getInstance();

Menu::Menu(Game *game)
{
  _game = game;
  _sound.registerSound("./resources/sounds/menu.wav", "main");
  _sound.registerSound("./resources/sounds/beretta.mp3", "shot");
  //_sound.playMusic("main", 1);

  _texManag.registerTexture("background-desert", "backgroundMenu");
  _texManag.registerTexture("ExitButton", "exit");
  _texManag.registerTexture("OptionsButton", "options");
  _texManag.registerTexture("LoadButton", "load");
  _texManag.registerTexture("LeaderboardButton", "leaderboard");
  _texManag.registerTexture("PlayButton", "play");

  std::cout << "Je suis dans le Menu" << std::endl;
  this->loadButtons();
  this->loadBackground();
}

void Menu::loadBackground()
{
  AObject *background = new MenuBackground();

  background->initialize(_texManag.getTexture("backgroundMenu"));
  _background = background;
}

void Menu::drawBackground(gdl::Clock& clock, gdl::BasicShader& shader)
{
  _background->draw(shader, clock);
}

void Menu::loadButtons()
{
  AObject *exitButton = new LittleButton();
  AObject *optionsButton = new LittleButton();
  AObject *leaderButton = new LittleButton();
  AObject *loadButton = new LittleButton();
  AObject *playButton = new BigButton();

  exitButton->initialize(_texManag.getTexture("exit"));
  optionsButton->initialize(_texManag.getTexture("options"));
  leaderButton->initialize(_texManag.getTexture("leaderboard"));
  loadButton->initialize(_texManag.getTexture("load"));
  playButton->initialize(_texManag.getTexture("play"));

  glm::vec3 trans(-0.38, -0.3, 0);
  exitButton->translate(trans);

  trans = glm::vec3(0.38, -0.3, 0);
  optionsButton->translate(trans);

  trans = glm::vec3(0.38, -0.08, 0);
  leaderButton->translate(trans);

  trans = glm::vec3(0.38, 0.14, 0);
  loadButton->translate(trans);

  trans = glm::vec3(-0.38, 0.03, 0);
  playButton->translate(trans);

  _buttons.push_back(playButton);
  _buttons.push_back(loadButton);
  _buttons.push_back(leaderButton);
  _buttons.push_back(optionsButton);
  _buttons.push_back(exitButton);
}

void Menu::drawButtons(gdl::Clock& clock, gdl::BasicShader& shader)
{
  for (size_t i = 0; i < _buttons.size() ; ++i)
    _buttons[i]->draw(shader, clock);
}

void Menu::draw(gdl::Clock& clock, gdl::BasicShader& shader)
{
  shader.bind();
  this->drawButtons(clock, shader);
  this->drawBackground(clock, shader);
}

void Menu::getNameOfButton(gdl::Input& input)
{
  glm::ivec2 mouse = input.getMousePosition();

  std::cout << "X : " << mouse.x << " Y: " << mouse.y << std::endl;
  if (mouse.x >= 996 && mouse.x <= 1746 && mouse.y >= 279 && mouse.y <= 731)
    {
      std::cout << "PLAY" << std::endl;
      _game->pushState(new SelectChar(_game));
    }
  else if (mouse.x >= 174 && mouse.x <= 928 && mouse.y >= 519 && mouse.y <= 729)
    {
      std::cout << "LEADERBOARD" << std::endl;
      _game->pushState(new Leaderboard(_game));
    }
  else if (mouse.x >= 996 && mouse.x <= 1746 && mouse.y >= 759
	   && mouse.y <= 967)
    {
      std::cout << "EXIT" << std::endl;
      _game->pushState(new Exit(_game));
    }
}

bool Menu::update(gdl::Clock& clock, gdl::Input& input)
{
  for (size_t i = 0; i < _buttons.size() ; ++i)
    _buttons[i]->update(clock, input);
  if (input.getInput(SDL_BUTTON_LEFT, true) == true)
    {
      _sound.playMusic("shot");
      this->getNameOfButton(input);
    }
  return true;
}

Menu::~Menu()
{
}
