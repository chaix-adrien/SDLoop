/*
** pixel.c for sdloop in SDLoop
**
** Made by Adrien Chaix
** email <adrien.chaix@epitech.eu>
**
** Started on  Fri Mar 11 00:55:16 2016 Adrien Chaix
** Last update Fri Mar 11 15:02:28 2016 Adrien Chaix
*/

#include "sdloop.h"

unsigned int color(unsigned char cA, unsigned char cR,
		   unsigned char cG, unsigned char cB)
{
  return (16777216 * cA + 65536 * cR + 256 * cG + cB);
}

unsigned int	getpixel(const t_pix *surface, const t_pos *pos)
{
  if (pos->y >= surface->h || pos->y < 0 || pos->x >= surface->w || pos->x < 0)
    return (0);
  int		bpp = surface->format->BytesPerPixel;
  Uint8		*p = (Uint8 *)surface->pixels + pos->y *
    surface->pitch + pos->x * bpp;

  switch(bpp)
    {
    case 1:
      return *p;
      break;
    case 2:
      return *(Uint16 *)p;
      break;
    case 3:
      if(!(SDL_BYTEORDER == SDL_BIG_ENDIAN))
	return (p[0] << 16 | p[1] << 8 | p[2]) | 0xFF000000;
      else
	return (p[0] | p[1] << 8 | p[2] << 16) | 0x000000FF;
      break;
    case 4:
      return *(Uint32 *)p;
      break;
    default:
      return 0;
    }
}

void	tekpixel(t_pix *surface, const t_pos *pos, unsigned int pixel)
{
  if (pos->y >= surface->h || pos->y < 0 || pos->x >= surface->w || pos->x < 0)
    return ;
  int	bpp = surface->format->BytesPerPixel;
  Uint8	*p = (Uint8 *)surface->pixels + pos->y * surface->pitch + pos->x * bpp;

  switch(bpp)
    {
    case 1:
      *p = pixel;
      break;
    case 2:
      *(Uint16 *)p = pixel;
      break;
    case 3:
      if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
	{
	  p[0] = (pixel >> 16) & 0xff;
	  p[1] = (pixel >> 8) & 0xff;
	  p[2] = pixel & 0xff;
	}
      else
	{
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
