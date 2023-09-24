#ifndef _mst_h
#define _mst_h
#include "cs3050.h"

// Types
typedef struct node
{
    Edge * edge;
    int priority;
    struct node* next;
}Node;

// Prototypes
void MST_Prim(Vertex vertices[], int startNumber, int countVertices);
Node* newNode(Edge* e, float p);
Edge* peek (Node** head);
void pop(Node**head);
void push(Node**head, Edge* e, float p);
int isEmpty(Node** head);

#endif
