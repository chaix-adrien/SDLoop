/*
** blit_size.c for sdloop in SDLoop
**
** Made by Adrien Chaix
** email <adrien.chaix@epitech.eu>
**
** Started on  Fri Mar 11 00:42:16 2016 Adrien Chaix
** Last update Sat Mar 12 12:55:50 2016 Adrien Chaix
*/

#include "sdloop.h"

void		sdl_blit_size(t_pix *dest, const t_pix *apply, const t_pos *pos)
{
  t_pos		nav;
  t_pos		pic;
  t_pos		pic_dest;
  double	rapport[2];

  rapport[X] = (double)apply->w / pos->w;
  rapport[Y] = (double)apply->h / pos->h;
  nav.y = -1;
  pic.y = 0;
  while (++nav.y < pos->h && nav.y + pos->y < dest->h
	 && pic.y < apply->h)
    {
      pic_dest.y = nav.y + pos->y;
      pic.y = nav.y * rapport[Y];
      pic.x = 0;
      nav.x = -1;
      while (++nav.x < pos->w && nav.x + pos->x < dest->w
	     && pic.x < apply->w)
	{
	  pic_dest.x = nav.x + pos->x;
	  pic.x = nav.x * rapport[X];
	  tekpixel(dest, &pic_dest, getpixel(apply, &pic));
	}
    }
}
