/*
** sdloop_define.h for sdloop in /home/chaix_a/Personal_Work/SDL_lapin
**
** Made by Adrien Chaix
** Login   <chaix_a@epitech.net>
**
** Started on  Fri Mar 11 15:05:30 2016 Adrien Chaix
** Last update Sat Mar 12 11:48:48 2016 Adrien Chaix
*/

#ifndef SDLOOP_DEFINE_H_
# define SDLOOP_DEFINE_H_
# define MUSIC_MAX_VOLUME MIX_MAX_VOLUME
# define sdl_blit(destination, source, position) \
  SDL_BlitSurface(source, NULL, destination, position)
# define tekfill(surface, color_of_fill) \
  SDL_FillRect(surface, NULL, color_of_fill)
# define load_picture IMG_Load

# define play_music Mix_PlayMusic
# define pause_music Mix_PauseMusic
# define resume_music Mix_ResumeMusic
# define rewind_music Mix_RewindMusic
# define set_music_volume Mix_VolumeMusic
# define stop_music Mix_HaltMusic
# define music_paudes Mix_PausedMusic
# define music_played Mix_PlayingMusic

# define set_sound_volume Mix_VolumeChunk
# define play_sound(s, l) Mix_PlayChannel(-1, s, l)
# define load_sound Mix_LoadWAV

# define load_font TTF_OpenFont
# define load_music Mix_LoadMUS
# define free_surface SDL_FreeSurface
# define free_font TTF_CloseFont
# define free_music Mix_FreeMusic
# define free_sound Mix_FreeChunk

#endif /* ! SDLOOP_DEFINE_H_ */
