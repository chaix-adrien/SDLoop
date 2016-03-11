/*
** new_window.c for sdloop in SDLoop
**
** Made by Adrien Chaix
** email <adrien.chaix@epitech.eu>
**
** Started on  Thu Mar 10 20:49:47 2016 Adrien Chaix
** Last update Fri Mar 11 13:52:31 2016 Adrien Chaix
*/

#include "sdloop.h"

t_pix	*new_window(int w, int h, int fullscreen, char *name)
{
  t_pix	*out;
  int	flag;

  flag = SDL_DOUBLEBUF | SDL_HWSURFACE;
  if (fullscreen)
    flag |= SDL_FULLSCREEN;
  out = SDL_SetVideoMode(w, h, 0, flag);
  if (name)
    SDL_WM_SetCaption(name, NULL);
  return (out);
}
