/*
** sdloop.h for sdloop.h in /home/chaix_a/Personal_Work/SDL_lapin
**
** Made by Adrien Chaix
** Login   <chaix_a@epitech.net>
**
** Started on  Thu Mar 10 15:03:57 2016 Adrien Chaix
** Last update Sat Mar 12 15:29:53 2016 Adrien Chaix
*/

#ifndef SDLOOP_H_
# define SDLOOP_H_
# include <SDL/SDL.h>
# include <SDL/SDL_image.h>
# include <SDL/SDL_ttf.h>
# include <SDL/SDL_mixer.h>
# include <sys/timeb.h>
# include <unistd.h>
# include <stdio.h>


typedef SDL_Rect	t_pos;
typedef SDL_Surface	t_pix;
typedef TTF_Font	t_font;
typedef Mix_Music	t_music;
typedef Mix_Chunk	t_sound;
typedef unsigned int	uint;

# define STATE_DOWN 1
# define STATE_UP 0
# define X 0
# define Y 1

// #####  ##   #  #####  #####
//   #    # #  #    #      #
//   #    #  # #    #      #
//   #    #  # #    #      #
// #####  #   ##  #####    #

int	sdloop_init(); /* Return >= 0 on error */
void	sdloop_close();


// #     #####  #####  ####      ####   #####  #####  #####
// #     #   #  #   #  #   #     #   #  #   #    #    #   #
// #     #   #  #####  #   #     #   #  #####    #    #####
// #     #   #  #   #  #   #     #   #  #   #    #    #   #
// ####  #####  #   #  ####      ####   #   #    #    #   #

t_pix	*new_window(int w, int h, int fullscreen, char *name);
// Fullscreen : 0 / 1
t_pix	*new_pixelarray(int w, int h);
// Create a Black pixelarray
t_pix	*load_picture(const char *path);
t_font	*load_font(const char *path, int size);
t_music	*load_music(const char *path);
t_sound	*load_sound(const char *path); // WAV / AIIF / RIFF/ VOC / OGG
// Return NULL on error


// #####  ####   #####  #####  #    #  #####  #####
// #      #   #  #   #  #   #  #    #    #    #
// # ###  ####   #####  #####  ######    #    #
// #   #  #  #   #   #  #      #    #    #    #
// #####  #   #  #   #  #      #    #  #####  #####

Uint32 getpixel(const t_pix *surface, t_pos *pos);
void	tekpixel(t_pix *surface, t_pos *pos, Uint32 pixel);
void	tekline(t_pix* surf, const t_pos *pos1,
		const t_pos *pos2, unsigned int couleur);
void	tekfill(t_pix *surface, const unsigned int color);
void	tekrect(t_pix *pix, const t_pos *rect, unsigned int color);
// Fill from (rect->x to rect->x + rect->w) / (rect->y to rect->y + rect->h)
void	tektext(t_pix *dest, const char *text, t_font *font,
		const t_pos *pos, unsigned int color);
// if (pos->w / h) == 1 : center on (pos->x / y)
void	sdl_blit_size(t_pix *dest, const t_pix *apply, const t_pos *pos);
// size is taken is apply->w / h
void	sdl_blit(t_pix *dest, const t_pix *src, const t_pos *pos);
// For blits, if pos == NULL, blit on {0, 0}


//  #####  #####  #    #  ##   #  ####
//  #      #   #  #    #  # #  #  #   #
//  #####  #   #  #    #  # #  #  #   #
//      #  #   #  #    #  #  # #  #   #
//  #####  #####  ######  #   ##  ####

// MUSIC
t_music	*load_music(const char *path);
void	set_music_volume(int volume); /* 0 - MUSIC_MAX_VOLUME */
void	play_music(t_music *music, int loop); // loop: -1 pour l'infini
void	stop_music();
void	pause_music();
void	resume_music();
void	rewind_music();
int	music_paused();
int	music_played();

// SOUND
t_sound	*load_sound(const char *path); // WAV / AIIF / RIFF/ VOC / OGG
void	set_sound_volume(t_sound *sound, int volume); // 0 - MUSIC_MAX_VOLUME
void	play_sound(t_sound *sound, int loop); // loop: -1 pour l'infini



//  #####  #   #  #####  ##   #  #####  #####
//  #      #   #  #      # #  #    #    #
//  ###    #   #  ###    # #  #    #    #####
//  #       # #   #      #  # #    #        #
//  #####    #    #####  #   ##    #    #####

typedef int	(*sdl_key_response)(int key, int state, void *data);
typedef int	(*sdl_move_response)(const t_pos *mouse, void *data);
typedef int	(*sdl_loop_response)(void *data);
typedef int	(*sdl_click_response)(int button, int state, void *data);
// Keycode are listed in SDL/SDL_keysym.h. ex: SDLK_a
// Button are listed in SDL/SDL_mouse.h. ex: SDL_BUTTON_LEFT
// State: STATE_UP / STATE_DOWN

t_pos	get_mouse();

void	sdl_loop(t_pix *win, unsigned char freq, void *data);
void	set_key_func(sdl_key_response func);
void	set_loop_func(sdl_loop_response func);
void	set_move_func(sdl_move_response func);
void	set_click_func(sdl_click_response func);
// Set callbacks functions for specified event
// In your function, data will be equal to the data pointer send to sdl_loop



//  #####  #####  #      #####  ####
//  #      #   #  #      #   #  #   #
//  #      #   #  #      #   #  ####
//  #      #   #  #      #   #  #   #
//  #####  #####  #####  #####  #   #

unsigned int	color(unsigned char cA, unsigned char cR,
		      unsigned char cG, unsigned char cB);
# define A 3
# define R 2
# define G 1
# define B 0
# define WHITE(alpha) ((alpha << (8 * 3)) + 0x00FFFFFF)
# define BLACK(alpha) ((alpha << (8 * 3)) + 0x00000000)
# define GREY(alpha, i) ((alpha << (8 * 3)) + (i << (8 * 2)) + (i << 8) + i)
# define RED(alpha) ((alpha << (8 * 3)) + 0x00FF0000)
# define GREEN(alpha) ((alpha << (8 * 3)) + 0x0000FF00)
# define BLUE(alpha) ((alpha << (8 * 3)) + 0x000000FF)
# define ORANGE(alpha) ((alpha << (8 * 3)) + 0x00FF8000)
# define PINK(alpha) ((alpha << (8 * 3)) + 0x00FF69B4)
# define SAUMON(alpha) ((alpha << (8 * 3)) + 0x00FF8080)
# define TEAL(alpha) (GREEN(alpha) | BLUE(alpha))
# define MAGENTA(alpha) (RED(alpha) | BLUE(alpha))
# define YELLOW(alpha) (RED(alpha) | GREEN(alpha))
typedef union	u_color
{
  unsigned char	argb[4];
  unsigned int	full;
}		t_color;


# include "sdloop_define.h"
#endif /* SDLOOP_H_ */
