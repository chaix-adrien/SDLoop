/*
** get_mouse_pos.c for sdloop in /home/chaix_a/Personal_Work/SDLoop
**
** Made by Adrien Chaix
** Login   <chaix_a@epitech.net>
**
** Started on  Sat Mar 12 14:09:44 2016 Adrien Chaix
** Last update Sat Mar 12 14:10:23 2016 Adrien Chaix
*/

#include "sdloop.h"

t_pos	get_mouse()
{
  t_pos	mouse;

  SDL_GetMouseState((int *)&mouse.x, (int *)&mouse.y);
  return (mouse);
}
