//BEGIN DESCRIPTION
//END   DESCRIPTION

//BEGIN INCLUDES
//local headers
#include "helper.h"
//END   INCLUDES

//BEGIN CPP DEFINITIONS
//END   CPP DEFINITIONS

//BEGIN DATASTRUCTURES
//END	DATASTRUCTURES

//BEGIN GLOBALS
//END   GLOBALS

//BEGIN FUNCTION PROTOTYPES
//END	FUNCTION PROTOTYPES

/* DEFINED PROGRESS GOALS
 * 
 * 
 *
 */

//BEGIN MAIN FUNCTION
int main(int argc, char *argv[])
{

(void)argc;
(void)argv;

//BEGIN INIT
init();

SDL_SetWindowPosition(Window,0,0);
SDL_SetWindowSize(Window,540,540);
SDL_SetWindowTitle(Window, "Timed Rendering with Alpha fading");
SDL_RenderSetLogicalSize(Renderer, 1024, 1024);

SDL_Surface *temp_surface = NULL;
temp_surface = IMG_Load("/home/carsten/nas/IT/MyProjects/assets/test-images/1.5-UV-Test-Grid.png");
SDL_Texture *Texture;
Texture = SDL_CreateTextureFromSurface(Renderer, temp_surface);
SDL_FreeSurface(temp_surface);
SDL_SetRenderDrawColor(Renderer, 111, 111, 111, 200);
SDL_SetRenderDrawBlendMode(Renderer, SDL_BLENDMODE_BLEND);
SDL_ShowWindow(Window);

SDL_Event event;

Uint32 counter =0;
Uint32 frame_time;
Uint32 frame_start=0;
frame_time=0;

int alpha;
alpha = 0;

char b = 0;

SDL_Rect fill_dst;
fill_dst.h=1024;
fill_dst.w=1024;
fill_dst.x=0;
fill_dst.y=0;

int running = 1;

//END   INIT

//BEGIN Event Loop
while(running){
	frame_start=SDL_GetTicks();
//BEGIN EVENT LOOP
	while(SDL_PollEvent(&event)){
		if(event.type == SDL_QUIT){
			running = 0;
		}
		if(event.type == SDL_MOUSEBUTTONDOWN){
			if(event.button.button == SDL_BUTTON_RIGHT){
			running=0;
			}
		}
	}
//END   EVENT LOOP


//BEGIN RENDERING
SDL_RenderClear(Renderer);
//SDL_Delay(16);//~15fps

SDL_RenderCopy(Renderer, Texture, NULL, NULL);
SDL_SetRenderDrawColor(Renderer, 111, 111, 111, 150);

if (b){
	SDL_SetRenderDrawColor(Renderer, 0, 0, 0, alpha);
	SDL_RenderFillRect(Renderer, &fill_dst);
}

SDL_RenderPresent(Renderer);
//END   RENDERING

frame_time = SDL_GetTicks()-frame_start;
counter += frame_time;
if (counter > 1000)
	b=1;
if (b){
	alpha+=1;
	if (alpha>255)
		alpha=255;
}

//END   Event Loop
}
//BEGIN CLEAN UP

exit_();
//END   CLEAN UP
return EXIT_SUCCESS;

}
//END   MAIN FUNCTION

//BEGIN FUNCTIONS
//END   FUNCTIONS
