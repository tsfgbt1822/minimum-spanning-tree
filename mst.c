#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "mst.h"

// These are stubs.  That is, you need to implement these functions.
// Vertex vertices: the vertices
// startNumber: number of first node
// countVertices: number of vertices
void MST_Prim(Vertex vertices[], int startNumber, int countVertices)
{
    startNumber--;
    //int to add up all weights used
    float totalWeight=0;

    //int to track what vertex I'm on
    int current=startNumber;

    //an array to make sure all vertexes are included in mst
    //each index represents a vertex, a 0 is not included, a 1 is included
    int found[countVertices];

    Edge* temp=NULL;

    //a priority queue to compare edges, start with first edge of first vertices and increment
    Node* pq = newNode(NULL, 1000.0);
    //vertices[startNumber].list=vertices[startNumber].list->next;

    //initializing found arrays
    for(int c=0; c<countVertices; c++)
    {
        found[c]=0;
    }

    //
    for(int i=0; i<=countVertices+1; i++)
    {
        found[current]=1;
        //load all possible edges into priority queue
        while(vertices[current].list!= NULL)
        {
            temp=vertices[current].list->pEdge;
            //if the temporary edge hasn't been found yet, push onto pq
            if(found[temp->to-1]==0 || found[temp->from-1]==0)
            {
                push(&pq, temp, temp->weight);
            }
            //increment to next edge of vertices
            vertices[current].list=vertices[current].list->next;
        }

        //pull item off pq, and put in temp
        temp=peek(&pq);
        pop(&pq);

        //if the edge still hasnt been found (for the case of later connections), print the edge
        if(found[temp->to-1]==0 || found[temp->from-1]==0)
        {
            totalWeight+=temp->weight;
            printf("\n%d->%d weight: %f", temp->from, temp->to, temp->weight);
        }

        //if the "to" node is the one already in the MST, go to the "from" node
        if(found[temp->to-1]==1)
        { 
            current=temp->from-1;
            found[temp->from-1]=1;
        }

        //else, go to to node
        if(found[temp->to-1]!=1)
        {
            current=temp->to-1;
            found[temp->to-1]=1;
        }
    }

    //clear priority queue
    while(isEmpty(&pq))
        pop(&pq);

    //check that all vertices have been connected, and if they havent, find it's shortest path the way I did before.
    for(int j=0; j<countVertices; j++)
    {
        if(found[j]==0)
        {
            while(vertices[j].list!=NULL)
            {
                temp=vertices[j].list->pEdge;
                push(&pq, temp, temp->weight);
                vertices[j].list=vertices[j].list->next;
            }

            temp=peek(&pq);
            pop(&pq);

            while(temp->to != current+1 && temp->from != current+1 && !isEmpty(&pq))
            {
                temp=peek(&pq);
                pop(&pq);
            }

            totalWeight+=temp->weight;
            found[temp->from-1]=1;
            found[temp->to-1]=1;
            printf("\n%d->%d, weight: %f", temp->from, temp->to, temp->weight);
        }
    }
    printf("\nTotal weight: %f\n", totalWeight);
}






//create a new Node in the pq
Node * newNode(Edge* e, float p)
{
    Node *temp=(Node*)malloc(sizeof(Node));
    temp->edge=e;
    temp->priority=p;
    temp->next=NULL;

    return temp;
}

//retrieve first item in pq
Edge* peek(Node**head)
{
    return (*head)->edge;
}

//pop top item off pq
void pop(Node** head)
{
    Node* temp = *head;
    (*head)=(*head)->next;
    free(temp);

}

//pushes edge onto pq
void push(Node** head, Edge* e, float p)
{
    Node* start = (*head);

    Node* temp = newNode(e,p);

    if((*head)->priority > p)
    {
        temp->next = *head;
        (*head) = temp;
    }
    else
    {
        while(start->next != NULL && start->next->priority < p)
            start=start->next;

        temp->next = start->next;
        start->next = temp;
    }
}

//checks if empty, (is opposite form usual, returns 1 if not empty)
int isEmpty (Node** head)
{
    if (*head==NULL)
        return 1;
    else
        return 0;
}

