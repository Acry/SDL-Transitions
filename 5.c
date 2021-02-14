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
 * demonstrate logical render size
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

SDL_ShowWindow(Window);

SDL_Event event;
TTF_Font  *font;
font=TTF_OpenFont("/home/carsten/nas/IT/MyProjects/assets/fonts/vector/Alfphabet.ttf", 800);
int digits[10];
int i;
for (i=0; i<10; i++)
	digits[i]=i;

SDL_Surface *number;
SDL_Texture  *numb_tex[10];
SDL_Color font_color = {255,173,0,255};
for (i=0; i<10; i++){
	char buffer[64];
	sprintf(buffer,"%d",digits[i]);
	number = TTF_RenderText_Blended(font, buffer, font_color);
	numb_tex[i] = SDL_CreateTextureFromSurface(Renderer, number);
}

SDL_FreeSurface(number);

Uint32 counter =0;
Uint32 frame_time;
Uint32 frame_start=0;
frame_time=0;

int alpha;
alpha = 255;
SDL_Rect filter;
filter.x=0;
filter.y=0;
filter.h=1024;
filter.w=1024;

SDL_Rect number_dst;
number_dst.h=100;
number_dst.w=100;
number_dst.x=1024/2-number_dst.w/2;
number_dst.y=1024/2-number_dst.h/2;

int running = 1;
i=0;
//END   INIT

//BEGIN Event Loop
while(running){
	frame_start=SDL_GetTicks();
//BEGIN EVENT LOOP
	while(SDL_PollEvent(&event)){
		if(event.type == SDL_QUIT){
			running = 0;
		}
		if(event.button.button == SDL_BUTTON_LEFT){
			i=0;
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
SDL_Delay(16);//~15fps
SDL_SetRenderDrawColor(Renderer, 111, 111, 111, 200);
SDL_RenderCopy(Renderer, Texture, NULL, NULL);
SDL_SetRenderDrawBlendMode(Renderer, SDL_BLENDMODE_BLEND);
SDL_RenderFillRect(Renderer, &filter);
SDL_SetTextureAlphaMod(numb_tex[i], alpha);
SDL_RenderCopy(Renderer, numb_tex[i], NULL, &number_dst);

SDL_RenderPresent(Renderer);
//END   RENDERING

frame_time = SDL_GetTicks()-frame_start;

counter += frame_time;
alpha-=5;
if (alpha<0)
	alpha=0;
number_dst.h+=20;
number_dst.w+=20;
number_dst.x=1024/2-number_dst.w/2;
number_dst.y=1024/2-number_dst.h/2;
SDL_Log("alpha: %d",alpha);
if (counter > 1000){
	counter=0;
 	i++;
	alpha=255;
	number_dst.h=100;
	number_dst.w=100;
	number_dst.x=1024/2-number_dst.w/2;
	number_dst.y=1024/2-number_dst.h/2;
	if (i > 9)
		i=0;

}
//END   Event Loop
}
//BEGIN CLEAN UP
SDL_DestroyTexture(Texture);
for (i=0; i<10; i++){
	SDL_DestroyTexture(numb_tex[i]);
}
exit_();
//END   CLEAN UP
return EXIT_SUCCESS;

}
//END   MAIN FUNCTION

//BEGIN FUNCTIONS
//END   FUNCTIONS
