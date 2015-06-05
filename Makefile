##
## Makefile<2> for girard_s in /home/nicolas/rendu/PSU_2014_zappy/sources/graph
##
## Made by Nicolas Girardot
## Login   <girard_s@epitech.net>
##
## Started on  Tue May 26 17:42:11 2015 Nicolas Girardot
## Last update Fri Jun  5 13:50:02 2015 Antoine Garcia
##

MAIN		=	bomberman

EXEC		=	$(MAIN)

SRC		+=	Button.cpp			\
			Exit.cpp			\
			Game.cpp			\
			Leaderboard.cpp			\
			Load.cpp			\
			Menu.cpp			\
			Options.cpp			\
			Map.cpp				\
			SelectChar.cpp			\
			Camera.cpp			\
			./Sound/SoundManager.cpp	\
			./ia/IAEngine.cpp		\
			TextureManager.cpp		\
			HumanCharacter.cpp		\
			World.cpp			\
			Bomb.cpp			\
			InputManager.cpp		\
			Command.cpp			\
			IACharacter.cpp			\
			Scoring.cpp			\
			Pause.cpp			\
			Box.cpp				\
			Flame.cpp			\
			Random.cpp			\
			RandomMenu.cpp

SRC_MAIN	=	$(SRC) main.cpp

OBJ_MAIN	=	$(SRC_MAIN:.cpp=.o)

LDFLAGS		=	-L./LibBomberman_linux_x64/libs/ -lgdl_gl	\
			-lGLEW -lrt -lfbxsdk -lSDL2 -lpthread		\
			-ldl -lGL -lGLU -lSDL_image			\
			-L ./Sound/lib -lfmodex64 -lglut		\

CPPFLAGS	=	-Wall -Wextra -std=c++11 -Wno-ignored-qualifiers \
			-Werror
CPPFLAGS	+=	-I./LibBomberman_linux_x64/includes/

ifeq ($(DEBUG), YES)
	CPPFLAGS = -g -std=c++11
	CPPFLAGS += -I./LibBomberman_linux_x64/includes/
	DEBUGFLAGS = -\033[1;31mDEBUG\033[0m-

endif

CPP		=	g++

DEL_FILE	=	rm -f

all:		$(EXEC)
		@printf "\r[\033[2;35mMAKE\033[0m] Bomberman\n"

$(MAIN):	$(OBJ_MAIN)
		@$(CPP) -o $@ $^ $(LDFLAGS)

%.o:		%.cpp
		@$(CPP) -o $@ -c $< $(CPPFLAGS)
		@printf "\r$(DEBUGFLAGS)$(PROFILFLAGS)[\033[1;32mBUILD\033[0m] $<\n"

clean:
		@$(DEL_FILE) $(OBJ_MAIN)
		@printf "\r[\033[1;31mDELETE\033[0m] *.o\n"
		@$(DEL_FILE)
		@printf "\r[\033[1;31mDELETE\033[0m] *~\n"

fclean:		clean
		@$(DEL_FILE) $(MAIN)
		@printf "\r[\033[1;31mDELETE\033[0m] $(EXEC)\n"

re:		fclean all

.PHONY:		all clean fclean re
