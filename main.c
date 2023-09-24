// You should not need to change main.c.  However, while
// developing your software, you may wish to uncomment various
// things that print out information for debugging purposes.  You
// can certainly add your own printing code as well to help you 
// debug things.
//
// Note also that the TAs may print out information when checking
// to see if your code actually works properly.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cs3050.h"
#include "mst.h"

int main(void)
{
    /******************************************************/
    /* Set things up by loading the graph and printing it */
    int countVertices, countEdges;

    GetCounts(&countVertices,&countEdges);

    Vertex vertices[countVertices];
    Edge edges[countEdges];
    memset(vertices,0,sizeof(vertices));
    memset(edges,0,sizeof(edges));

    GetEdges(edges,countEdges);
    BuildAdjacency(vertices,edges,countVertices,countEdges);
    PrintVertices(vertices,countVertices);
    /******************************************************/

    /******************************************************/
    /* Now, run Prim and print the results                */
    int startNumber=7;    // pick a vertext to start, you can change this
    MST_Prim(vertices, startNumber, countVertices);
    /******************************************************/
}
