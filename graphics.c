#include "graphics.h"
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "object.h"
#include <math.h>
/*
For this graphics library it's going to be really simple for now
The user initializes the graphics library
adds all there shapes 
and then displays it

for this implementation though
when a user calls draw line or something it adds it to a linked list containing all the shapes
once the user calls present screen it runs the for displaying the window and it will iterate through 
each of the shapes in the for loop. 

Later on though the plan is to have it be interactive and the user adding stuff real time
*/
static InternalRenderer* IR;
static ObjList* obj_list;
static SDL_Color background_color;

void init_graphics(int width, int height, char* title){
  IR = create_internal_renderer(width, height, title);
  obj_list = malloc(sizeof(ObjList));
  obj_list->head = NULL;
  obj_list->tail = NULL;
}

void set_background_color(SDL_Color c){
  background_color = c;
}

void draw_line(int x1, int y1, int x2, int y2, SDL_Color c){
  DrawableObject* line = create_line(x1,y1,x2,y2,c);
  insert_obj(obj_list, line);
}

void draw_rectangle(int x, int y, int w, int h, SDL_Color c){
  DrawableObject* rect = create_rectangle(x,y,w,h,c);
  insert_obj(obj_list, rect);
}

void draw_circle(int x, int y, int r,SDL_Color c){
  insert_obj(obj_list,create_circle(x,y,r,c));
}

//this is the for loop 
void present_screen(){
  SDL_Event event;
  bool running = true;
  while(running){
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT) running = false;
		}

    clear_internal_renderer(IR, background_color);

    ObjectNode* cur_node = obj_list->head; 
    DrawableObject cur_object = cur_node->obj;
    //I should probably make a general draw_shape internal function that just takes 
    //in the object type and not have 3 separate functions for drawing shapes
    while(cur_node != NULL){
      switch(cur_object.type){
        case CIRCLE:    
        ;
          Circle circ = cur_object.obj.circ;
          draw_circle_internal(IR,circ.x,circ.y,circ.r,circ.c);
          break;
        case RECTANGLE:
          ;
          Rectangle rect = cur_object.obj.rect;
          draw_rect_internal(IR, rect.x,rect.y,rect.w,rect.h,rect.c);
          break;
        case LINE:
          ;
          Line line = cur_object.obj.line;
          draw_line_internal(IR, line.x1,line.y1,line.x2,line.y2,line.c);
          break;
        default:
          break;
      }
      cur_node = cur_node->next;
      cur_object = cur_node->obj;
    }
    present_internal_renderer(IR);
  }
  destroy_internal_renderer(IR);
  free(obj_list);
  
}

//

