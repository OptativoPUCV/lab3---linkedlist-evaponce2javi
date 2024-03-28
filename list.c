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
  list->current = list->tail;
  return list->tail->data;
}

void *prevList(List *list) {
  if (list == NULL)
    return NULL;
  if (list->current == NULL)
    return NULL;
  if (list->current->prev == NULL)
    return NULL;
  list->current = list->current->prev;
  return list->current->data;
}

void pushFront(List *list, void *data) {
  Node *newN = createNode(data);
  if (list == NULL)
    return;
  if (list->head == NULL) {
    list->head = newN;
    list->tail = newN;
  } else {
    newN->next = list->head;
    list->head->prev = newN;
    list->head = newN;
  }
}

void pushBack(List *list, void *data) {
  list->current = list->tail;
  pushCurrent(list, data);
}

void pushCurrent(List *list, void *data) {
  Node *newN = createNode(data);

  if (list == NULL || list->current == NULL)
    return;

  if (list->current->next == NULL) {
    list->current->next = newN;
    newN->prev = list->current;
    list->tail = newN;
  } else {
    list->current->next->prev = newN;
    list->current->next = newN;
    newN->prev = list->current;
    newN->prev = list->current;
  }
}

void *popFront(List *list) {
  list->current = list->head;
  return popCurrent(list);
}

void *popBack(List *list) {
  list->current = list->tail;
  return popCurrent(list);
}

void *popCurrent(List *list) {
  Node *nodePipipi = list->current;

  if (list == NULL || list->current == NULL)
    return NULL;

  void *data = nodePipipi->data;

  if (nodePipipi == list->head) {
    if (list->head->next != NULL)
      list->head->next->prev = NULL;
    list->head = list->head->next;
  }

  return NULL;
}

void cleanList(List *list) {
  while (list->head != NULL) {
    popFront(list);
  }
}