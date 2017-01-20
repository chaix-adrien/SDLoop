/*
** main.c for test in SDLoop/demo/
**
** Made by Adrien Chaix
** email <adrien.chaix@epitech.eu>
**
** Started on  Thu Mar 10 16:14:45 2016 Adrien Chaix
** Last update Fri Mar 11 15:25:47 2016 Adrien Chaix
*/

#include "header.h"


int		my_loop_func(void *data)
/* Appelée à chaques frame */
{
  t_all		*all;

  all = data;
  sdl_blit(all->win, all->pix, NULL);
  return (1);
}

int	my_key_func(int key, int state, void *data)
/* Appelée à chaques entrées clavier */
{
  t_all	*all;
  t_pos	size;

  all = data;
  size.x = size.y = 0;
  size.w = W;
  size.h = H;
  printf("%s key is pressed\n", SDL_GetKeyName(key));
  if (key == SDLK_ESCAPE)
    return (0);
  if (state)
    {
      play_sound(all->sound, 0);
      tekfill(all->pix, BLUE(5));
    }
  else
    {
      sdl_blit_size(all->pix, all->img, &size);
    }
  return (1);
}

int	my_move_func(const t_pos *mouse, void *data)
/* Appelée a chaques mouvments de souris */
{
  t_all	*all;
  t_pos	centre;

  all = data;
  centre.x = W / 2;
  centre.y = H / 2;
  tekline(all->pix, &centre, mouse, all->color);
  return (1);
}

int	my_click_func(int button, int state, void *data)
/* Appelées a chaques clics de souris */
{
  t_all	*all;

  all = data;
  if (button == SDL_BUTTON_LEFT)
    printf("Mouse's Left button pressed\n");
  if (state)
    {
      pause_music();
      all->color = GREEN(255);
    }
  else
    {
      resume_music();
      all->color = WHITE(255);
    }
  return (1);
}

int	set_all(t_all *all)
{
  t_pos	pos;

  /* load des surfaces / sons */
  if(!(all->win = new_window(W, H, 0, "my_name")))
    {
      fprintf(stderr, "Could not set video mode: %s\n", SDL_GetError());
      SDL_Quit();
      exit(-1);
    }
  if (!(all->pix = new_pixelarray(W, H)))
    return (1);
  if (!(all->img = load_picture("ressources/back.jpg")))
    return (2);
  if (!(all->font = load_font("ressources/fontroboto.ttf", 30)))
    return (3);
  if (!(all->music = load_music("ressources/sound.wav")))
    return (4);
  if (!(all->sound = load_sound("ressources/sound.wav")))
    return (5);
  tekfill(all->pix, SAUMON(255));
  pos.x = W / 2 - all->img->w / 2;
  pos.y = 0;
  all->color = color(255, 255, 255, 255);
  sdl_blit(all->pix, all->img, &pos);
  /* Set Callback function */
  set_key_func(my_key_func);
  set_loop_func(my_loop_func);
  set_move_func(my_move_func);
  set_click_func(my_click_func);
  /* Set volumes */
  set_music_volume(MUSIC_MAX_VOLUME / 2);
  set_sound_volume(all->sound, 70);
  return (0);
}

int	main()
{
  t_all	all;
  t_pos	pos;
  int ret;
  
  if (sdloop_init()) /* initialise SDL / TTF / Mixer */
    return (1);
  if ((ret = set_all(&all)))
    return (ret);
  pos.x = W / 2;
  pos.y = H / 2;
  pos.w = 1; /*centre le texte sur X */
  pos.h = 0;
  tektext(all.pix, "Bougez la souris, Pressez une touche pour reset, \
cliquez pour changer la couleur",
	  all.font, &pos, TEAL(255));
  play_music(all.music, 1);
  sdl_loop(all.win, 200, &all);
  free_surface(all.win);
  free_surface(all.pix);
  free_surface(all.img);
  free_font(all.font);
  free_sound(all.sound);
  sdloop_close(); /* Close SDL / TTF / Mixer */
  return (0);
}
