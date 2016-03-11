/*
** new_pixelarray.c for sdloop in SDLoop
**
** Made by Adrien Chaix
** email <adrien.chaix@epitech.eu>
**
** Started on  Thu Mar 10 20:34:50 2016 Adrien Chaix
** Last update Fri Mar 11 10:03:48 2016 Adrien Chaix
*/

#include "sdloop.h"

t_pix	*new_pixelarray(int w, int h)
{
  t_pix	*out;

  out = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
  out = SDL_DisplayFormatAlpha(out);
  return (out);
}
