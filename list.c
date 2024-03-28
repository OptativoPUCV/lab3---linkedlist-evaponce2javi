#include "list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
  void *data; // puntero dirigido al dato
  Node *next; // al nodo de adelante
  Node *prev; // al nodo de atrás
};

struct List {
  Node *head;    // 1mer elemento
  Node *tail;    // ultimo
  Node *current; // puntero para recorrer
};

typedef List List;

Node *createNode(void *data) {
  Node *new = (Node *)malloc(sizeof(Node));
  assert(new != NULL);
  new->data = data;
  new->prev = NULL;
  new->next = NULL;
  return new;
}

List *createList() {
  List *lista = (List *)malloc(sizeof(List));
  lista->head = NULL;
  lista->tail = NULL;
  lista->current = 0;
  return lista;
}

void *firstList(List *list) {
  if (list == NULL)
    return NULL;
  if (list->head == NULL)
    return NULL;

  list->current = list->head;
  return list->head->data;
}

void *nextList(List *list) {
  if (list == NULL)
    return NULL;
  if (list->current == NULL)
    return NULL;
  if (list->current->next == NULL)
    return NULL;
  list->current = list->current->next;
  return list->current->data;
}

void *lastList(List *list) {
  if (list == NULL)
    return NULL;
  if (list->tail == NULL)
    return NULL;
  last->current = last->tail;
  return list->tail->data;
  return NULL;
}

void *prevList(List *list) { return NULL; }

void pushFront(List *list, void *data) {}

void pushBack(List *list, void *data) {
  list->current = list->tail;
  pushCurrent(list, data);
}

void pushCurrent(List *list, void *data) {}

void *popFront(List *list) {
  list->current = list->head;
  return popCurrent(list);
}

void *popBack(List *list) {
  list->current = list->tail;
  return popCurrent(list);
}

void *popCurrent(List *list) { return NULL; }

void cleanList(List *list) {
  while (list->head != NULL) {
    popFront(list);
  }
}