/*
** ligne.c for sdloop in SDLoop
**
** Made by Adrien Chaix
** email <adrien.chaix@epitech.eu>
**
** Started on  Thu Mar 10 20:10:38 2016 Adrien Chaix
** Last update Fri Mar 11 15:00:31 2016 Adrien Chaix
*/

#include "sdloop.h"

void tekline(SDL_Surface* surf, const t_pos *pos1,
	     const t_pos *pos2, const unsigned int couleur)
{
  t_pos	pos;
  int Dx,Dy;
  int xincr,yincr;
  int erreur;
  int i;

  if (!pos1 || !pos2)
    return ;
  Dx = abs(pos2->x - pos1->x);
  Dy = abs(pos2->y - pos1->y);
  if (pos1->x < pos2->x)
    xincr = 1;
  else
    xincr = -1;
  if (pos1->y < pos2->y)
    yincr = 1;
  else
    yincr = -1;
  pos.x = pos1->x;
  pos.y = pos1->y;
  if(Dx > Dy)
    {
      erreur = Dx / 2;
      for(i = 0; i < Dx; i++)
	{
	  pos.x += xincr;
	  erreur += Dy;
	  if(erreur > Dx)
	    {
	      erreur -= Dx;
	      pos.y += yincr;
	    }
	  tekpixel(surf, &pos, couleur);
	}
    }
  else
    {
      erreur = Dy / 2;
      for(i = 0; i < Dy; i++)
	{
	  pos.y += yincr;
	  erreur += Dx;
	  if(erreur > Dy)
	    {
	      erreur -= Dy;
	      pos.x += xincr;
	    }
	  tekpixel(surf, &pos, couleur);
	}
    }
}
