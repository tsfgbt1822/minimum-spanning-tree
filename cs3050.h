#ifndef _cs3050_h
#define _cs3050_h
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Types
typedef struct _Edge
{
    int from;
    int to;
    float weight;
} Edge;

typedef struct _Adjacency
{
    Edge * pEdge;
    struct _Adjacency * next;
} Adjacency, * PAdjacency;

typedef struct _Vertex
{
    int number;
    PAdjacency list;
} Vertex;


// Prototypes
void GetCounts(int * pCountVertices, int * pCountEdges);
void GetEdge(Edge * pEdge);
void GetEdges(Edge edges[], int countEdges);
void PrintVertex(Vertex vertex);
void PrintVertices(Vertex vertices[], int count);
void AddAdjacentEdge(Vertex * pVertex, Edge * pEdge);
void BuildAdjacency(    Vertex vertices[],
                        Edge edges[],
                        int countVertices,
                        int countEdges);


#endif
