#include <stdlib.h>
#include <SDL2/SDL.h>
#include <math.h>
#include "object.h"
#include <stdbool.h>


ObjList* new_obj_list(){
  ObjList* res = malloc(sizeof(ObjList));
  res->head = NULL;
  res->tail = NULL;
  return res;
}

bool obj_list_empty(ObjList *list){
  return (list->head == NULL) & (list->tail == NULL);
}

DrawableObject* create_rectangle(int x, int y, int w, int h, SDL_Color c){
  DrawableObject* res = malloc(sizeof(DrawableObject));
  *res = (DrawableObject){
    .type = RECTANGLE,
    .obj.rect = {x,y,w,h,c}
  };
  return res;
}

DrawableObject* create_line(int x1, int y1, int x2, int y2, SDL_Color c){
  DrawableObject* res = malloc(sizeof(DrawableObject));
  *res = (DrawableObject){
    .type = LINE,
    .obj.line = {x1,y1,x2,y2,c}
  };
  return res;
}

DrawableObject* create_circle(int x, int y, int r, SDL_Color c){
  DrawableObject* res = malloc(sizeof(DrawableObject));
  *res = (DrawableObject){
    .type = CIRCLE,
    .obj.circ = {x,y,r,c}
  };
  return res;
}

void insert_obj(ObjList* list, DrawableObject* obj){
  ObjectNode* insert = malloc(sizeof(ObjectNode));
  insert->next = NULL;
  insert->obj = *obj;
  if(obj_list_empty(list)){
    list->head = insert;
    list->tail = insert;
  }else{
    list->tail->next = insert;
    list->tail = insert;
  }
}

void free_list(ObjList* list){
  if(list == NULL) return;

  ObjectNode* cur = list->head;
  while(cur != NULL){
    ObjectNode* free_node = cur;
    cur = cur->next;
    free(free_node);
  }

  free(list);
}