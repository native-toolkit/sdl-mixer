/*
  SDL_mixer:  An audio mixer library based on the SDL library
  Copyright (C) 1997-2016 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

#ifdef MODPLUG_MUSIC

#include <modplug.h>

typedef struct {
    int loaded;
    void *handle;

    ModPlugFile* (*ModPlug_Load)(const void* data, int size);
    void (*ModPlug_Unload)(ModPlugFile* file);
    int  (*ModPlug_Read)(ModPlugFile* file, void* buffer, int size);
    void (*ModPlug_Seek)(ModPlugFile* file, int millisecond);
    void (*ModPlug_GetSettings)(ModPlug_Settings* settings);
    void (*ModPlug_SetSettings)(const ModPlug_Settings* settings);
    void (*ModPlug_SetMasterVolume)(ModPlugFile* file,unsigned int cvol) ;
} modplug_loader;

extern modplug_loader modplug;

#endif /* MODPLUG_MUSIC */

extern int Mix_InitModPlug();
extern void Mix_QuitModPlug();
