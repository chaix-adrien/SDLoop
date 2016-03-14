/*
** tektext.c for sdloop in SDLoop
**
** Made by Adrien Chaix
** email <adrien.chaix@epitech.eu>
**
** Started on  Fri Mar 11 10:16:49 2016 Adrien Chaix
** Last update Sat Mar 12 14:56:48 2016 Adrien Chaix
*/

#include "sdloop.h"

void		tektext(t_pix *dest, const char *text, t_font *font,
			const t_pos *pos, unsigned int color)
{
  t_color	col;
  SDL_Color	sdl_col;
  t_pos		pos_to_blit;
  t_pix		*to_blit;

  col.full = color;
  sdl_col.r = col.argb[R];
  sdl_col.g = col.argb[G];
  sdl_col.b = col.argb[B];
  to_blit = TTF_RenderText_Blended(font, text, sdl_col);
  pos_to_blit = *pos;
  if (pos->w == 1)
    pos_to_blit.x -= (double)to_blit->w / 2;
  if (pos->h == 1)
    pos_to_blit.y -= (double)to_blit->h / 2;
  sdl_blit(dest, to_blit, &pos_to_blit);
  free_surface(to_blit);
}
