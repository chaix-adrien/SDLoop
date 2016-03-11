/*
** header.h for test in /home/chaix_a/Personal_Work/SDL_lapin/test
**
** Made by Adrien Chaix
** Login   <chaix_a@epitech.net>
**
** Started on  Thu Mar 10 17:22:16 2016 Adrien Chaix
** Last update Fri Mar 11 14:55:53 2016 Adrien Chaix
*/

#ifndef TEST_H_
# define TEST_H_
# include <sdloop.h>

# define W 1280
# define H 720

# define test(b, b1, b2) printf(b, NULL, b1, b2)

typedef	struct s_all
{
  t_pix		*win;
  t_pix		*pix;
  t_pix		*img;
  t_font	*font;
  t_music	*music;
  t_sound	*sound;
  uint		color;
}		t_all;
#endif
