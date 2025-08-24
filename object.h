#ifndef OBJECT_H
#define OBJECT_H

#include <stdlib.h>
#include <SDL2/SDL.h>
#include <math.h>
#include <stdbool.h>

typedef enum { RECTANGLE, CIRCLE, LINE } ObjectType;
typedef struct {
  int x;
  int y;
  int w;
  int h; 
  SDL_Color c;
} Rectangle;

typedef struct {
  int x1;
  int y1;
  int x2;
  int y2;
  SDL_Color c;
} Line;

typedef struct {
  int x;
  int y;
  int r;
  SDL_Color c;
} Circle;

typedef union {
  Rectangle rect;
  Line line;
  Circle circ;
} Object;

typedef struct {
  ObjectType type;
  Object obj; 
} DrawableObject;

typedef struct ObjectNode{
  DrawableObject obj;
  struct ObjectNode* next;
} ObjectNode;

typedef struct ObjList{
  ObjectNode* head;
  ObjectNode* tail;
} ObjList;

ObjList* new_obj_list();
bool obj_list_empty(ObjList* list);
DrawableObject* create_rectangle(int x, int y, int w, int h, SDL_Color c);
DrawableObject* create_line(int x1, int y1, int x2, int y2, SDL_Color c);
DrawableObject* create_circle(int x, int y, int r, SDL_Color c);
void insert_obj(ObjList* list, DrawableObject* obj);
void free_list(ObjList* list);

/*I need to rethink how these objects are going to work and just overall structure of 
  how i'm going to use them in graphics.c
  i think most likely i will just input a drawableobject type and that's about it
*/ 

#endif