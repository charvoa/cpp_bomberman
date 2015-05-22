//
// Menu.cpp for Menu in /home/antgar/rendu/cpp_bomberman
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Fri May  8 13:43:01 2015 Antoine Garcia
// Last update Fri May 22 17:44:15 2015 Nicolas Charvoz
//

#include "Menu.hh"

Sound&	Menu::_sound = Sound::getInstance();
TextureManager &Menu::_texManag = TextureManager::getInstance();

Menu::Menu(Game *game)
{
  _game = game;
  _sound.registerSound("./resources/sounds/menu.wav", "main");
  _sound.registerSound("./resources/sounds/beretta.mp3", "shot");
  _sound.playMusic("main");

  _texManag.registerTexture("background-desert", "backgroundMenu");
  _texManag.registerTexture("ExitButton", "exit");
  _texManag.registerTexture("OptionsButton", "options");
  _texManag.registerTexture("LoadButton", "load");
  _texManag.registerTexture("LeaderboardButton", "leaderboard");
  _texManag.registerTexture("PlayButton", "play");

  std::cout << "Je suis dans le Menu" << std::endl;
}

void Menu::drawBackground()
{

}

void Menu::drawButtons()
{
  AObject *background = new MenuBackground();
  AObject *exitButton = new LittleButton();
  AObject *optionsButton = new LittleButton();
  AObject *leaderButton = new LittleButton();
  AObject *loadButton = new LittleButton();
  AObject *playButton = new BigButton();

  background->initialize(_texManag.getTexture("backgroundMenu"));
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

  _objects.push_back(playButton);
  _objects.push_back(loadButton);
  _objects.push_back(leaderButton);
  _objects.push_back(optionsButton);
  _objects.push_back(exitButton);
  _objects.push_back(background);
  // _exitButton = new Button(_texManag.getTexture("exit"), 964, 148);
  // _optionsButton = new Button(_texManag.getTexture("options"), 60, 148);
  // _loadButton = new Button(_texManag.getTexture("load"), 60, 600);
  // _leaderboardButton = new Button(_texManag.getTexture("leaderboard"), 60, 375);
  // _playButton = new Button(_texManag.getTexture("play"), 964, 375);
}

void Menu::draw(gdl::Clock& clock, gdl::BasicShader& shader)
{
  shader.bind();

  this->drawButtons();
  for (size_t i = 0; i < _objects.size() ; ++i)
    _objects[i]->draw(shader, clock);
}

void Menu::getNameOfButton(gdl::Input& input)
{
  (void) input;
  //  glm::ivec2 mouse = input.getMousePosition();
}

bool Menu::update(gdl::Clock& clock, gdl::Input& input)
{
  (void) clock;
  //  for (size_t i = 0; i < _objects.size() ; ++i)
  //_objects[i]->update(clock, input);
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
