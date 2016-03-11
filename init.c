/*
** init.c for sdloop in SDLoop
**
** Made by Adrien Chaix
** email <adrien.chaix@epitech.eu>
**
** Started on  Fri Mar 11 11:34:19 2016 Adrien Chaix
** Last update Fri Mar 11 12:38:47 2016 Adrien Chaix
*/

#include "sdloop.h"

int	sdloop_init()
{
  if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
      fprintf(stderr, "Erreur d'initialisation d' SDL: %s\n",
	      SDL_GetError());
      return (1);
    }
  if(TTF_Init() == -1)
    {
      fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n",
	      TTF_GetError());
      return (2);
    }
  if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
      printf("Erreur d'initialisation de MIX_Audio: %s", Mix_GetError());
      return (3);
    }
  Mix_AllocateChannels(10);
  Mix_Volume(1, MIX_MAX_VOLUME);
  return (0);
}

void	sdloop_close()
{
  SDL_Quit();
  TTF_Quit();
  Mix_CloseAudio();
}
