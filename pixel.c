/*
** pixel.c for sdloop in SDLoop
**
** Made by Adrien Chaix
** email <adrien.chaix@epitech.eu>
**
** Started on  Fri Mar 11 00:55:16 2016 Adrien Chaix
** Last update Sat Mar 12 13:45:35 2016 Adrien Chaix
*/

#include "sdloop.h"

unsigned int color(unsigned char cA, unsigned char cR,
		   unsigned char cG, unsigned char cB)
{
  return (16777216 * cA + 65536 * cR + 256 * cG + cB);
}

Uint32 getpixel(const t_pix *surface, t_pos *pos)
{
  int bpp = surface->format->BytesPerPixel;
  if (pos->x < 0 || pos->x >= surface->w || pos->y < 0 || pos->y >= surface->h)
    return (BLACK(255));
  /* Here p is the address to the pixel we want to retrieve */
  Uint8 *p = (Uint8 *)surface->pixels + pos->y * surface->pitch + pos->x * bpp;

  switch(bpp) {
  case 1:
    return *p;
    break;

  case 2:
    return *(Uint16 *)p;
    break;

  case 3:
    if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
      return p[0] << 16 | p[1] << 8 | p[2];
    else
      return p[0] | p[1] << 8 | p[2] << 16;
    break;

  case 4:
    return *(Uint32 *)p;
    break;

  default:
    return 0;       /* shouldn't happen, but avoids warnings */
  }
}

void tekpixel(SDL_Surface *surface, t_pos *pos, Uint32 pixel)
{
  if (pos->x < 0 || pos->x >= surface->w || pos->y < 0 || pos->y >= surface->h)
    return ;
  int bpp = surface->format->BytesPerPixel;
  /* Here p is the address to the pixel we want to set */
  Uint8 *p = (Uint8 *)surface->pixels + pos->y * surface->pitch + pos->x * bpp;
  t_color	col;

  col.full = pixel;
  if (col.argb[A] < 10)
    return ;
  switch(bpp) {
  case 1:
    *p = pixel;
    break;

  case 2:
    *(Uint16 *)p = pixel;
    break;

  case 3:
    if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
      p[0] = (pixel >> 16) & 0xff;
      p[1] = (pixel >> 8) & 0xff;
      p[2] = pixel & 0xff;
    } else {
      p[0] = pixel & 0xff;
      p[1] = (pixel >> 8) & 0xff;
      p[2] = (pixel >> 16) & 0xff;
    }
    break;

  case 4:
    *(Uint32 *)p = pixel;
    break;
  }
}

void	tekrect(t_pix *pix, const t_pos *rect, uint color)
{
  t_pos	nav;

  nav.x = rect->x - 1;
  while (++nav.x < rect->x + rect->w)
    {
      nav.y = rect->y - 1;
      while (++nav.y < rect->y + rect->h)
	{
	  tekpixel(pix, &nav, color);
	}
    }
}
