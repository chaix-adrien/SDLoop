/*
** main_loop_sdl.c for sdloop in SDLoop
**
** Made by Adrien Chaix
** email <adrien.chaix@epitech.eu>
**
** Started on  Thu Mar 10 15:06:58 2016 Adrien Chaix
** Last update Fri Mar 11 14:57:04 2016 Adrien Chaix
*/

#include "sdloop_private.h"

void	set_loop_func(sdl_loop_response func)
{
  sdl_loop_func = func;
}

void	set_key_func(sdl_key_response func)
{
  sdl_key_func = func;
}

void	set_move_func(sdl_move_response func)
{
  sdl_move_func = func;
}

void	set_click_func(sdl_click_response func)
{
  sdl_click_func = func;
}

double          get_time()
{
  struct timeb  curtime;
  double        out;

  ftime(&curtime);
  out = curtime.time;
  out += (double)curtime.millitm / 1000;
  return (out);
}

void		sdl_loop(t_pix *win, unsigned char freq, void *data)
{
  double	act_time = 0;
  int		continuer = 1;
  SDL_Event	event;
  t_pos		mouse;
  double	delay;

  delay = freq / 1000000.0;
  while (continuer)
    {
      if (get_time() - act_time >= delay)
	{
	  act_time = get_time();
	  if (sdl_loop_func)
	    continuer = sdl_loop_func(data);
	  SDL_PollEvent(&event);
	  if (event.type == SDL_QUIT)
	    continuer = 0;
	  if (continuer && (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP))
	    {
	      continuer = sdl_key_func(event.key.keysym.sym,
				       (event.type == SDL_KEYUP) ?
				       STATE_UP : STATE_DOWN, data);
	      event.type = 1;
	    }
	  if (continuer && event.type == SDL_MOUSEMOTION)
	    {
	      mouse.x = event.motion.x;
	      mouse.y = event.motion.y;
	      continuer = sdl_move_func(&mouse, data);
	    }
	  if (continuer && sdl_click_func && (event.type == SDL_MOUSEBUTTONUP ||
					      event.type == SDL_MOUSEBUTTONDOWN))
	    {
	      continuer = sdl_click_func(event.button.button,
					 (event.type == SDL_MOUSEBUTTONUP) ?
					 STATE_UP : STATE_DOWN, data);
	      event.type = 1;
	    }
	  SDL_Flip(win);
	}
      else
	{
	  usleep(delay - (get_time() - act_time));
	}
    }
}
